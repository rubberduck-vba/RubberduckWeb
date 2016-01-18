using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.ServiceModel.Syndication;
using System.Threading.Tasks;
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

        public async Task<ActionResult> News()
        {
            //todo: do this client side so the page loads faster?
            return View(await GetBlogFeedItemsAsync());
        }

        private async Task<IEnumerable<SyndicationItem>> GetBlogFeedItemsAsync()
        {
            const string rssUri = "https://rubberduckvba.wordpress.com/feed/";

            using (var httpClient = new HttpClient())
            {
                var response = await httpClient.GetAsync(new Uri(rssUri));

                if (!response.IsSuccessStatusCode)
                {
                    return null;
                }

                using (var reader = XmlReader.Create(await response.Content.ReadAsStreamAsync()))
                {
                    var feed = SyndicationFeed.Load(reader);
                    return feed?.Items;
                }
            }
        }

        public ActionResult Features()
        {
            return View();
        }
    }
}