using System;
using System.Linq;
using System.Threading.Tasks;
using System.Web.Mvc;
using RubberduckWeb.Models;

namespace RubberduckWeb.Controllers
{
    [OutputCache(VaryByParam = "*", Duration = 0, NoStore = true)]
    public class InspectionsController : AsyncController
    {
        public ActionResult Index() =>  RedirectToAction(nameof(List));

        public async Task<ActionResult> List()
        {
            if (RubberduckAssets.ShouldInvalidate)
            {
                await RubberduckAssets.InvalidateAsync();
            }

            var ignoreModuleExample = @"Option Explicit
'@IgnoreModule: inspections will ignore this module";

            return View(new InspectionsModel(RubberduckAssets.CodeAnalysisXmlDocs.Inspections.Where(e => !e.IsHidden), ignoreModuleExample));
        }

        public ActionResult Details(string id)
        {
            var info = RubberduckAssets.CodeAnalysisXmlDocs.Inspections.SingleOrDefault(e => e.InspectionName == id);
            if (info != default)
            {
                return View(info);
            }

            return RedirectToAction(nameof(ErrorController.PageNotFound), "Error");
        }

        public ActionResult QuickFixInfo(string id)
        {
            var info = RubberduckAssets.CodeAnalysisXmlDocs.QuickFixes.SingleOrDefault(e => e.QuickFixName == id);
            if (info != default)
            {
                return View(info);
            }

            return RedirectToAction(nameof(ErrorController.PageNotFound), "Error");
        }
    }
}