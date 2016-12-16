using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace RubberduckWeb.Controllers
{
    public class ErrorController : Controller
    {
        // GET: Error
        public ActionResult Generic(Exception error = null)
        {
            return View(error);
        }

        public ActionResult PageNotFound(HttpException error = null)
        {
            return View(error);
        }

        public ActionResult InternalServerError(HttpException error = null)
        {
            return View(error);
        }

        public ActionResult HttpDefault(HttpException error = null)
        {
            return View(error);
        }

        public ActionResult Code418(HttpException error = null)
        {
            error = new HttpException(418, "I'm a rubber duck.");
            return View(error);
        }
    }
}