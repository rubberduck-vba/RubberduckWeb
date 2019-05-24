using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;
using System.Xml.Linq;
using NLog;
using Octokit;

namespace RubberduckWeb.Models
{
    public static class RubberduckAssets
    {
        private const string GitHubOrg = "rubberduck-vba";
        private const string RepositoryName = "Rubberduck";
        private const string AssetName = "Rubberduck.CodeAnalysis.xml";

        public static async Task InvalidateAsync()
        {
            Inspections = await RequestInspectionsAsync();
        }

        public static bool ShouldInvalidate => Inspections == null || TotalReleaseDownloads == 0 || 
            DateTime.UtcNow > _lastInvalalidated.AddDays(1);

        //public static int TotalDownloads { get; private set; }
        public static int TotalReleaseDownloads { get; private set; }

        private static DateTime _lastInvalalidated;
        public static IDictionary<string, InspectionInfo> Inspections { get; private set; }

        private static async Task<IDictionary<string, InspectionInfo>> RequestInspectionsAsync()
        {
            var original = Inspections?.ToDictionary(kvp => kvp.Key, kvp => kvp.Value);
            try
            {
                var client = new GitHubClient(new ProductHeaderValue("rubberduck-vba_RubberduckWEB"));

                var master = await client.Repository.Release.GetLatest(GitHubOrg, RepositoryName);
                var masterUrl = master.Assets.SingleOrDefault(a => a.Name == AssetName)?.BrowserDownloadUrl;

                var allReleases = await client.Repository.Release.GetAll(GitHubOrg, RepositoryName);
                var next = allReleases.FirstOrDefault(tag => tag.Prerelease);
                var nextUrl = next?.Assets.SingleOrDefault(a => a.Name == AssetName)?.BrowserDownloadUrl;

                var masterDocs = await DownloadXmlDocAssetAsync(masterUrl, isPreRelease: false);
                var nextDocs = await DownloadXmlDocAssetAsync(nextUrl, isPreRelease: masterDocs.Any());

                var result = masterDocs.AsEnumerable()
                    .Concat(nextDocs.AsEnumerable().Where(kvp => !masterDocs.ContainsKey(kvp.Key)))
                    .ToDictionary(kvp => kvp.Key, kvp => kvp.Value);

                _lastInvalalidated = DateTime.UtcNow;
                /*TotalDownloads = allReleases
                    .Sum(release => release.Assets.Where(asset => asset.Name.EndsWith(".exe"))
                    .Sum(asset => asset.DownloadCount));*/
                TotalReleaseDownloads = allReleases
                    .Where(release => !release.Prerelease)
                    .Sum(release => release.Assets.Where(asset => asset.Name.EndsWith(".exe"))
                    .Sum(asset => asset.DownloadCount));
                return result;
            }
            catch (Exception)
            {
                /* log? */
                return original;
            }
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