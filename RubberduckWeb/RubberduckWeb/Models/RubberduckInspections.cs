using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;
using System.Xml.Linq;
using Octokit;

namespace RubberduckWeb.Models
{
    public static class RubberduckInspections
    {
        private const string GitHubOrg = "rubberduck-vba";
        private const string RepositoryName = "Rubberduck";
        private const string AssetName = "Rubberduck.CodeAnalysis.xml";

        public static async Task InvalidateAsync()
        {
            Inspections = /*await*/ RequestInspectionsAsync();
            if (Inspections != null)
            {
                _lastInvalalidated = DateTime.UtcNow;
            }
        }

        public static bool ShouldInvalidate => Inspections == null || DateTime.UtcNow > _lastInvalalidated.AddDays(1);

        private static DateTime _lastInvalalidated;
        public static IDictionary<string, InspectionInfo> Inspections { get; private set; }

        private static /*async Task<*/IDictionary<string, InspectionInfo>/*>*/ RequestInspectionsAsync()
        {
            var client = new GitHubClient(new ProductHeaderValue("rubberduck-vba_RubberduckWEB"));
            var masterTask = /*await*/ Task.Run(async () => await client.Repository.Release.GetLatest(GitHubOrg, RepositoryName));
            masterTask.Wait();
            if (masterTask.IsFaulted)
            {
                var e = masterTask.Exception;
            }
            var master = masterTask.Result;
            var masterUrl = master.Assets.SingleOrDefault(a => a.Name == AssetName)?.BrowserDownloadUrl;

            var nextTask = /*await*/ Task.Run(async () => await client.Repository.Release.GetAll(GitHubOrg, RepositoryName));
            nextTask.Wait();
            if (nextTask.IsFaulted)
            {
                var e = nextTask.Exception;
            }
            var next = nextTask.Result.FirstOrDefault(tag => tag.Prerelease);
            var nextUrl = next?.Assets.SingleOrDefault(a => a.Name == AssetName)?.BrowserDownloadUrl;

            var masterDocsTask = /*await*/ Task.Run(async () => await DownloadXmlDocAssetAsync(masterUrl, isPreRelease: false));

            masterDocsTask.Wait();
            if (masterDocsTask.IsFaulted)
            {
                var e = masterDocsTask.Exception;
            }
            var masterDocs = masterDocsTask.Result;
            var nextDocsTask = /*await*/ Task.Run(async () => await DownloadXmlDocAssetAsync(nextUrl, isPreRelease: masterDocs.Any()));

            nextDocsTask.Wait();
            var nextDocs = nextDocsTask.Result;
            if (nextDocsTask.IsFaulted)
            {
                var e = nextDocsTask.Exception;
            }

            return masterDocs.AsEnumerable()
                .Concat(nextDocs.AsEnumerable().Where(kvp => !masterDocs.ContainsKey(kvp.Key)))
                .ToDictionary(kvp => kvp.Key, kvp => kvp.Value);
        }

        private static async Task<IDictionary<string, InspectionInfo>> DownloadXmlDocAssetAsync(string assetUrl, bool isPreRelease)
        {
            if (string.IsNullOrEmpty(assetUrl))
            {
                return new Dictionary<string, InspectionInfo>();
            }

            using (var client = new HttpClient())
            {
                var uri = new Uri(assetUrl);
                var response = await client.GetAsync(uri);
                var xml = await response.Content.ReadAsStreamAsync();
                var document = XDocument.Load(xml);
                var result = GetInspectionDocs(document, isPreRelease).ToDictionary(info => info.InspectionName, info => info);
                return result;
            }
        }

        private static IEnumerable<InspectionInfo> GetInspectionDocs(XDocument doc, bool isPreRelease) =>
            from node in doc.Descendants("member")
            let name = GetInspectionNameOrDefault(node)
            where !string.IsNullOrEmpty(name)
            select new InspectionInfo(name, node, isPreRelease);

        private static string GetInspectionNameOrDefault(XElement memberNode)
        {
            var name = memberNode.Attribute("name")?.Value;
            if (name == null || !name.StartsWith("T:") || !name.EndsWith("Inspection"))
            {
                return default(string);
            }

            return name.Substring(name.LastIndexOf(".", StringComparison.Ordinal) + 1);
        }
    }
}