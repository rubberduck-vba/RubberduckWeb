using System;
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
            return View(RubberduckAssets.Inspections.Values);
        }

        public ActionResult Details(string id)
        {
            if (RubberduckAssets.Inspections.TryGetValue(id, out var info))
            {
                return View(info);
            }

            return RedirectToAction("PageNotFound", "Error");
        }
    }
}