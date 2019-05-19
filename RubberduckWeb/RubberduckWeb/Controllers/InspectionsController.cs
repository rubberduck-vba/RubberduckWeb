using System.Web.Mvc;
using RubberduckWeb.Models;

namespace RubberduckWeb.Controllers
{
    [OutputCache(VaryByParam = "*", Duration = 0, NoStore = true)]
    public class InspectionsController : Controller
    {
        public ActionResult Index() =>  RedirectToAction("List");

        public ActionResult List() => View(RubberduckInspections.Inspections.Values);

        public ActionResult Details(string id)
        {
            if (RubberduckInspections.Inspections.TryGetValue(id, out var info))
            {
                return View(info);
            }

            return RedirectToAction("PageNotFound", "Error");
        }
    }
}