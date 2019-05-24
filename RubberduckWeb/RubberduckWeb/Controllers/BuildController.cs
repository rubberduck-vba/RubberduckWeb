using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;
using System.Web;
using System.Web.Mvc;
using RubberduckWeb.Models;

namespace RubberduckWeb.Controllers
{
    public class BuildController : Controller
    {
        // GET: Build
        public ActionResult Index()
        {
            return View("Version");
        }

        public ActionResult CacheStatus()
        {
            return View((object)RubberduckReleaseBuilds.LastInvalidated.ToString(CultureInfo.InvariantCulture));
        }

        public ActionResult Version(string id)
        {
            var version = string.Empty;
            if (RubberduckReleaseBuilds.ShouldInvalidate)
            {
                var task = Task.Run(async () => await RubberduckReleaseBuilds.InvalidateAsync());
                task.Wait();
            }

            if (string.Equals(id, "prerelease", StringComparison.OrdinalIgnoreCase))
            {
                version = RubberduckReleaseBuilds.LatestPreReleaseVersion.ToString();
            }
            else if (string.Equals(id, "stable", StringComparison.OrdinalIgnoreCase))
            {
                version = RubberduckReleaseBuilds.LatestStableVersion.ToString();
            }

            // If we leave `version` without casting to an `object`, it'll try to find a view with that name.
            return View((object)version);
        }
    }
}