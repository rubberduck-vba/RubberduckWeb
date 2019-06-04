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
        private static readonly int MinutesToInvalide = 30; // NOTE: unauthenticated requests capped at 60 requests/hour.

        private const string GitHubOrg = "rubberduck-vba";
        private const string RepositoryName = "Rubberduck";
        private const string AssetName = "Rubberduck.CodeAnalysis.xml";

        public static async Task InvalidateAsync()
        {
            Inspections = await RequestInspectionsAsync();
        }

        public static bool ShouldInvalidate => Inspections == null || !Downloads.Any() || 
            DateTime.UtcNow > _lastInvalalidated.AddMinutes(MinutesToInvalide);

        public static IReadOnlyList<ReleaseDownloadInfo> Downloads { get; private set; } 
            = new List<ReleaseDownloadInfo>();

        private static DateTime _lastInvalalidated;
        public static IDictionary<string, InspectionInfo> Inspections { get; private set; }

        private static async Task<IDictionary<string, InspectionInfo>> RequestInspectionsAsync()
        {
            var original = Inspections?.ToDictionary(kvp => kvp.Key, kvp => kvp.Value);
            try
            {
                var client = new GitHubClient(new ProductHeaderValue("rubberduck-vba_RubberduckWEB"));
                var allReleases = (await client.Repository.Release.GetAll(GitHubOrg, RepositoryName))
                    .Select(release => new ReleaseDownloadInfo
                    {
                        IsPreRelease = release.Prerelease,
                        TagName = $"[{release.TagName}]",
                        ReleaseDate = release.CreatedAt.UtcDateTime,
                        Downloads = release.Assets.Where(a => a.Name.EndsWith(".exe")).Sum(a => a.DownloadCount),
                        InspectionDocsUrl = release.Assets.SingleOrDefault(a => a.Name == AssetName)?.BrowserDownloadUrl
                    }).OrderBy(tag => tag.ReleaseDate).ToList();

                var master = allReleases.Last(tag => !tag.IsPreRelease);
                var next = allReleases.Last();

                IDictionary<string, InspectionInfo> masterDocs = new Dictionary<string, InspectionInfo>();
                IDictionary<string, InspectionInfo> nextDocs = new Dictionary<string, InspectionInfo>();
                if (!string.IsNullOrEmpty(master.InspectionDocsUrl))
                {
                    masterDocs = await DownloadXmlDocAssetAsync(master.InspectionDocsUrl, isPreRelease: false);
                }
                if (!string.IsNullOrEmpty(next.InspectionDocsUrl))
                {
                    nextDocs = await DownloadXmlDocAssetAsync(next.InspectionDocsUrl, isPreRelease: masterDocs.Any()); // don't mark as prerelease if there's no docs in master
                }

                var result = masterDocs.AsEnumerable()
                    .Concat(nextDocs.AsEnumerable().Where(kvp => !masterDocs.ContainsKey(kvp.Key)))
                    .ToDictionary(kvp => kvp.Key, kvp => kvp.Value);

                _lastInvalalidated = DateTime.UtcNow;
                Downloads = allReleases;
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