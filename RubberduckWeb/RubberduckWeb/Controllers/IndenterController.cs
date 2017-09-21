using Rubberduck.SmartIndenter;
using RubberduckWeb.Mocks;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using RubberduckWeb.Models;

namespace RubberduckWeb.Controllers
{
    public class IndenterController : Controller
    {
        // GET: Indenter
        public ActionResult Index()
        {
            return View(new IndenterSettingsModel());
        }

        [HttpPost]
        public ActionResult Index(IndenterSettingsModel model)
        {
            var code = model.Code;

            // Mat says this is how it works, and he seems to be right.
            var indenter = new Indenter(null, () => model);
            var lines = code.Split(new[] { Environment.NewLine }, StringSplitOptions.None);
            lines = indenter.Indent(lines, false).ToArray();
            var result = string.Join(Environment.NewLine, lines);

            // Required to update Code textarea
            // Otherwise it reloads the POSTed data
            ModelState.Clear();

            model.Code = result + Environment.NewLine;
            return View(model);
        }
    }
}
