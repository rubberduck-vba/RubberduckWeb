using System;
using System.Threading.Tasks;
using System.Web.Mvc;
using RubberduckWeb.Models;

namespace RubberduckWeb.Controllers
{
    [OutputCache(VaryByParam = "*", Duration = 0, NoStore = true)]
    public class InspectionsController : Controller
    {
        public ActionResult Index() =>  RedirectToAction("List");

        public ActionResult List()
        {
            if (RubberduckInspections.ShouldInvalidate)
            {
                // todo async controller method to await the invalidate task?
                try
                {
                    Task.Delay(0).ContinueWith(t => ValidateInspectionsCache()).Wait();
                }
                catch (Exception e)
                {
                    throw;
                }
            }
            return View(RubberduckInspections.Inspections.Values);
        }

        private async Task ValidateInspectionsCache()
        {
            try
            {
                await RubberduckInspections.InvalidateAsync();
            }
            catch (Exception e)
            {
                throw;
            }
        }

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