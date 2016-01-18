using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel.Syndication;
using System.Web;
using System.Web.Mvc;
using System.Xml;

namespace RubberduckWeb.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }

        public ActionResult News()
        {
            //todo: do this client side so the page loads faster.
            const string rssUri = "https://rubberduckvba.wordpress.com/feed/";
            using (var reader = XmlReader.Create(rssUri))
            {
                var feed = SyndicationFeed.Load(reader);

                return View(feed?.Items);
            }
        }

        public ActionResult Features()
        {
            return View();
        }
    }
}