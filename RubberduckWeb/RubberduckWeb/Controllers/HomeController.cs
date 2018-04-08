using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.ServiceModel.Syndication;
using System.Threading.Tasks;
using System.Web.Mvc;
using System.Xml;
using Rubberduck.SmartIndenter;
using RubberduckWeb.Models;

namespace RubberduckWeb.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Refactorings()
        {
            return View();
        }

        public ActionResult UnitTesting()
        {
            return View();
        }

        public ActionResult Navigation()
        {
            return View();
        }

        public ActionResult Indentation()
        {
            return View(new IndenterSettingsModel {Code = "Sub DoSomething()\n'Try it! Paste your unindented VBA code here.\nEnd Sub"});
        }

        public ActionResult About()
        {
            return View();
        }

        public ActionResult Contact()
        {
            return View();
        }

        public ActionResult News()
        {
            return View();
        }

        public async Task<PartialViewResult> BlogFeed()
        {
            try
            {
                return PartialView(await GetBlogFeedItemsAsync());
            }
            catch
            { 
                // Whatever happens, don't return a 500 response code to the jQuery call.
                // That results in a half blank page.

                // If the model is null, an error message is shown, leverage that.
                return PartialView();
            }
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
                    return feed.Items;
                }
            }
        }

        [HttpPost]
        public ActionResult Indentation(IndenterSettingsModel model)
        {
            var code = model.Code;

            if (string.IsNullOrEmpty(code))
            {
                return View(model);
            }

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
