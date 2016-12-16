using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Web;
using System.Web.Mvc;

namespace RubberduckWeb.Controllers
{
    public class BuildController : Controller
    {
        // GET: Build
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Version(string id)
        {
            var version = string.Empty;

            if (string.Equals(id, "stable", StringComparison.OrdinalIgnoreCase))
            {
                version = Assembly.GetAssembly(typeof(Rubberduck.App)).GetName().Version.ToString();
            }

            // If we leave `version` without casting to an `object`, it'll try to find a view with that name.
            return View((object)version);
        }
    }
}