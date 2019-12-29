using System;
using System.Collections.Generic;
using System.IO;
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
            CodeAnalysisXmlDocs = await RequestInspectionsAsync();
        }

        public static bool ShouldInvalidate => CodeAnalysisXmlDocs == null || !Downloads.Any() || 
            DateTime.UtcNow > _lastInvalalidated.AddMinutes(MinutesToInvalide);

        public static IReadOnlyList<ReleaseDownloadInfo> Downloads { get; private set; } 
            = new List<ReleaseDownloadInfo>();

        private static DateTime _lastInvalalidated;
        public static CodeAnalysisXmlDocs CodeAnalysisXmlDocs { get; private set; } = new CodeAnalysisXmlDocs();

        private static async Task<CodeAnalysisXmlDocs> RequestInspectionsAsync()
        {
            var original = CodeAnalysisXmlDocs;
            try
            {
                var masterDocs = new CodeAnalysisXmlDocs();
                var nextDocs = new CodeAnalysisXmlDocs();
                var allReleases = await GetAllGitHubReleases();
                if (allReleases != default)
                {
                    var master = allReleases.Last(tag => !tag.IsPreRelease);
                    var next = allReleases.Last();

                    if (!string.IsNullOrEmpty(master.CodeAnalysisXmlDocsUrl))
                    {
                        masterDocs = await DownloadXmlDocAssetAsync(master.CodeAnalysisXmlDocsUrl, isPreRelease: false);
                    }
                    if (!string.IsNullOrEmpty(next.CodeAnalysisXmlDocsUrl))
                    {
                        nextDocs = await DownloadXmlDocAssetAsync(next.CodeAnalysisXmlDocsUrl, isPreRelease: masterDocs.Inspections.Any()); // don't mark as prerelease if there's no docs in master
                    }
                }
                else
                {
                    masterDocs = LoadLocalCodeAnalysisXmlDocs(isPreRelease: false);
                    nextDocs = LoadLocalCodeAnalysisXmlDocs(isPreRelease: true);
                }

                var mergedInspections = masterDocs.Inspections
                    .Concat(nextDocs.Inspections.Where(inspection => !masterDocs.HasInspection(inspection)));
                var mergedQuickFixes = masterDocs.QuickFixes
                    .Concat(nextDocs.QuickFixes.Where(quickFix => !masterDocs.HasQuickFix(quickFix)));
                var result = new CodeAnalysisXmlDocs(mergedInspections, mergedQuickFixes);

                _lastInvalalidated = DateTime.UtcNow;
                Downloads = allReleases?.ToList();
                return result;
            }
            catch (Exception exception)
            {
                /* log? */
                return original;
            }
        }

        private static async Task<IEnumerable<ReleaseDownloadInfo>> GetAllGitHubReleases()
        {
            try
            {
                var client = new GitHubClient(new ProductHeaderValue("rubberduck-vba_RubberduckWEB"));
                return (await client.Repository.Release.GetAll(GitHubOrg, RepositoryName))
                    .Select(release => new ReleaseDownloadInfo
                    {
                        IsPreRelease = release.Prerelease,
                        TagName = $"[{release.TagName}]",
                        ReleaseDate = release.CreatedAt.UtcDateTime,
                        Downloads = release.Assets.Where(a => a.Name.EndsWith(".exe")).Sum(a => a.DownloadCount),
                        CodeAnalysisXmlDocsUrl = release.Assets.SingleOrDefault(a => a.Name == AssetName)?.BrowserDownloadUrl
                    }).OrderBy(tag => tag.ReleaseDate).ToList();
            }
            catch
            {
                // GitHub API rate limit busted
                return default;
            }
        }

        private static CodeAnalysisXmlDocs LoadLocalCodeAnalysisXmlDocs(bool isPreRelease)
        {
            var path = isPreRelease
                ? "Content/Rubberduck.CodeAnalysis.next.xml"
                : "Content/Rubberduck.CodeAnalysis.master.xml";
            using (var stream = File.OpenRead(path))
            {
                var document = XDocument.Load(stream);
                var inspections = GetInspectionDocs(document, isPreRelease);
                var quickfixes = GetQuickFixDocs(document, isPreRelease);
                return new CodeAnalysisXmlDocs(inspections, quickfixes);
            }
        }

        private static async Task<CodeAnalysisXmlDocs> DownloadXmlDocAssetAsync(string assetUrl, bool isPreRelease)
        {
            if (string.IsNullOrEmpty(assetUrl))
            {
                return new CodeAnalysisXmlDocs();
            }

            using (var client = new HttpClient())
            {
                var uri = new Uri(assetUrl);
                var response = await client.GetAsync(uri);
                var xml = await response.Content.ReadAsStreamAsync();
                var document = XDocument.Load(xml);
                var inspections = GetInspectionDocs(document, isPreRelease);
                var quickfixes = GetQuickFixDocs(document, isPreRelease);
                return new CodeAnalysisXmlDocs(inspections, quickfixes);
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
                return default;
            }

            return name.Substring(name.LastIndexOf(".", StringComparison.Ordinal) + 1);
        }

        private static IEnumerable<QuickFixInfo> GetQuickFixDocs(XDocument doc, bool isPreRelease) =>
            from node in doc.Descendants("member")
            let name = GetQuickFixNameOrDefault(node)
            where !string.IsNullOrEmpty(name)
            && node.Descendants("canfix").Any() // excludes quickfixes added to master prior to v2.5.0 
            select new QuickFixInfo(name, node, isPreRelease);

        private static string GetQuickFixNameOrDefault(XElement memberNode)
        {
            var name = memberNode.Attribute("name")?.Value;
            if (name == null || !name.StartsWith("T:") || !name.EndsWith("QuickFix"))
            {
                return default;
            }

            return name.Substring(name.LastIndexOf(".", StringComparison.Ordinal) + 1);
        }
    }
}