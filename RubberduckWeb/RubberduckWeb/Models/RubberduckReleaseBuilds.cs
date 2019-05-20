using System;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Octokit;

namespace RubberduckWeb.Models
{
    public static class RubberduckReleaseBuilds
    {
        private const string GitHubOrg = "rubberduck-vba";
        private const string RepositoryName = "Rubberduck";

        private static readonly string VersionPattern = @"v(?<major>\d+)\.(?<minor>\d+)\.(?<revision>\d+)\.?(?<build>\d+)?";

        public static async Task InvalidateAsync()
        {
            var client = new GitHubClient(new ProductHeaderValue("rubberduck-vba_RubberduckWEB"));
            var releases = await client.Repository.Release.GetAll(GitHubOrg, RepositoryName);
            var stable = releases.FirstOrDefault(e => !e.Prerelease);
            if (stable != default(Release))
            {
                var stableVersion = Regex.Match(stable.TagName, VersionPattern);
                LatestStableVersion = new Version(
                    int.Parse(stableVersion.Groups["major"].Value),
                    int.Parse(stableVersion.Groups["minor"].Value),
                    int.Parse(stableVersion.Groups["revision"].Value),
                    stableVersion.Groups["build"].Success ? int.Parse(stableVersion.Groups["build"].Value) : 0);

                LastInvalidated = DateTime.UtcNow;
            }
            var pre = releases.FirstOrDefault(e => e.Prerelease);
            if (pre != default(Release))
            {
                var preVersion = Regex.Match(pre.TagName, VersionPattern);
                LatestPreReleaseVersion = new Version(
                    int.Parse(preVersion.Groups["major"].Value),
                    int.Parse(preVersion.Groups["minor"].Value),
                    int.Parse(preVersion.Groups["revision"].Value),
                    preVersion.Groups["build"].Success ? int.Parse(preVersion.Groups["build"].Value) : 0);

                LastInvalidated = DateTime.UtcNow;
            }
        }

        public static Version LatestStableVersion { get; private set; }
        public static Version LatestPreReleaseVersion { get; private set; }

        public static DateTime LastInvalidated { get; private set; }

        public static bool ShouldInvalidate => LastInvalidated == default(DateTime) || DateTime.UtcNow > LastInvalidated.AddDays(1);
    }
}