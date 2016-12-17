using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace RubberduckWeb.Controllers
{
    public class ErrorController : Controller
    {
        public ActionResult PageNotFound()
        {
            return View();
        }

        public ActionResult InternalServerError()
        {
            return View();
        }

        public ActionResult HttpDefault(string id = null)
        {
            return View((object)id);
        }

        public ActionResult Code418()
        {
            return View();
        }
    }
}