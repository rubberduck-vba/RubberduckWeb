using System;
using System.Linq;
using Microsoft.Vbe.Interop;
using Moq;
using Rubberduck.Parsing.VBA;
using Rubberduck.VBEditor.VBEHost;
using RubberduckTests;
using RubberduckWeb.Mocks;
using System.Threading.Tasks;
using System.Web.Mvc;
using RubberduckWeb.Mocks.Rubberduck.Inspections;

namespace RubberduckWeb.Controllers
{
    public class InspectionsController : Controller
    {
        private readonly DefaultInspector _inspector;
        private readonly RubberduckParserState _state;

        public InspectionsController(DefaultInspector inspector, RubberduckParserState state)
        {
            _inspector = inspector;
            _state = state;
        }

        [HttpPost]
        public Task<PartialViewResult> GetInspectionResults(string code)
        {
            //Arrange
            var builder = new MockVbeBuilder();
            VBComponent component;

            // ensure line endings are \r\n
            code = code.Replace("\r\n", "\n").Replace("\n", "\r\n");
            var vbe = builder.BuildFromSingleStandardModule(code ?? string.Empty, out component);

            var mockHost = new Mock<IHostApplication>();
            mockHost.SetupAllProperties();

            var parser = MockParser.Create(vbe.Object, _state);
            Task.Run(() => parser.Parse()).Wait();
            if (parser.State.Status >= ParserState.Error)
            {
                throw new ArgumentException(parser.State.Status.ToString());
            }

            var results = _inspector.FindIssuesAsync(parser.State);

            if (results.Any())
            {
                return Task.FromResult(PartialView("~/Views/Home/InspectionResults.cshtml", results));
            }

            return Task.FromResult(PartialView("~/Views/Home/NoInspectionResults.cshtml", results));
        }
    }
}