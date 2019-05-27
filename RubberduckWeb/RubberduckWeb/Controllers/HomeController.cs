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
    public class HomeController : AsyncController
    {
        private readonly Random _random = new Random(DateTime.UtcNow.Minute);

        public async Task<ActionResult> Index()
        {
            var highlights = GetFeatureHighlights();
            var model = new HomePageModel(highlights, () => RubberduckAssets.TotalReleaseDownloads);
            if (RubberduckAssets.ShouldInvalidate)
            {
                await RubberduckAssets.InvalidateAsync();
            }
            return View(model);
        }

        private FeatureHighlight[] GetFeatureHighlights()
        {
            return new[]
            {
                new FeatureHighlight(
                    "Unit Testing", 
                    _aboutUnitTesting, 
                    "~/Content/Images/TestExplorer.png",
                    "Test Explorer dockable toolwindow", 
                    "Unit testing. In VBA/VB6.", 
                    Url.Action("UnitTesting")),
                new FeatureHighlight(
                    "Code Inspections",
                    _aboutInspections,
                    "~/Content/Images/CodeInspections.png",
                    "Inspection Results dockable toolwindow",
                    "Well over 80 inspections, and counting.",
                    Url.Action("List", "Inspections")),
                new FeatureHighlight(
                    "Smart Indenter",
                    _aboutSmartIndenter,
                    "~/Content/Images/SmartIndenter.png",
                    "All your Smart Indenter options, and more.",
                    "Rubberduck can import your legacy Smart Indenter settings.",
                    Url.Action("Indentation")),
                new FeatureHighlight(
                    "Refactorings",
                    _aboutRefactorings,
                    "~/Content/Images/Refactoring.png",
                    "Refactorings context menu",
                    "Why risk Find/Replace when you can Refactor/Rename?",
                    Url.Action("Refactorings")),
                new FeatureHighlight(
                    "Navigation",
                    _aboutNavigation,
                    "~/Content/Images/Navigation.png",
                    "Navigation tools menu",
                    "Features that make you want to early-bind everything.",
                    Url.Action("Navigation")),
                new FeatureHighlight(
                    "Code Explorer",
                    _aboutCodeExplorer,
                    "~/Content/Images/CodeExplorer.png",
                    "Navigation tools menu",
                    "Warning: Addictive.",
                    Url.Action("Navigation")),
                /* todo */
            }
            .Select(highlight => new {Value=_random.NextDouble(), Highlight=highlight})
            .OrderBy(e => e.Value)
            .Select(e => e.Highlight)
            .Take(3)
            .ToArray();
        }

        private readonly string _aboutUnitTesting = @"Rubberduck gives you a powerful and fully integrated test environment for your VBA code.";
        private readonly string _aboutInspections = @"Find and fix issues in your code with Rubberduck inspecting code quality, readability, language opportunities, and more.";
        private readonly string _aboutSmartIndenter = @"A C# port/rewrite of the original Smart Indenter 32-bit VBIDE add-in works in 64-bit hosts.";
        private readonly string _aboutNavigation = @"Quickly find what's using what and where, with enhanced navigation tooling.";
        private readonly string _aboutCodeExplorer = @"Organize your VBA/VB6 project like never before, using special annotation comments to customize a folder hierarchy.";
        private readonly string _aboutCodeMetrics = @"Identify potentially problematic areas by reviewing cyclomatic complexity, nesting, and other metrics.";
        private readonly string _aboutRefactorings = @"Clean up your code by easily renaming existing identifiers. Extract interfaces, reorder parameters, and more.";

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
            var initialCode = "Sub DoSomething()\n'Try it! Paste your unindented VBA code here.\nEnd Sub";
            return View(new IndenterSettingsModel {Code = initialCode});
        }

        public ActionResult Indenter() => RedirectToAction(nameof(Indentation));

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
        [ValidateInput(false)]
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
