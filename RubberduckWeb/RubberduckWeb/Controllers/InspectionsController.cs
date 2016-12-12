using System;
using System.Linq;
using Moq;
using Rubberduck.Parsing.VBA;
using System.Threading.Tasks;
using System.Web.Mvc;
using Rubberduck.Inspections;
using Rubberduck.VBEditor.Application;
using Rubberduck.VBEditor.Events;
using Rubberduck.VBEditor.SafeComWrappers.Abstract;
using RubberduckWeb.Mocks.Rubberduck.Inspections;

namespace RubberduckWeb.Controllers
{
    using RubberduckTests.Mocks;

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
            IVBComponent component;

            // ensure line endings are \r\n
            code = code.Replace("\r\n", "\n").Replace("\n", "\r\n");
            var vbe = builder.BuildFromSingleStandardModule(code, out component);

            var mockHost = new Mock<IHostApplication>();
            mockHost.SetupAllProperties();

            var parser = MockParser.Create(vbe.Object, _state);
            Task.Run(() => parser.Parse(new System.Threading.CancellationTokenSource())).Wait();
            if (parser.State.Status >= ParserState.Error)
            {
                throw new ArgumentException(parser.State.Status.ToString());
            }

            var results = _inspector.Inspect(parser.State);

            // strip away module & project naming suggestions, they don't make sense in the web UI
            results.RemoveAll(ir => ir.Inspection is UseMeaningfulNameInspection
                        && (ir.QualifiedSelection.QualifiedName.Name == "TestProject1." || ir.QualifiedSelection.QualifiedName.Name == "TestProject1.TestModule1")
                    );


            if (results.Any())
            {
                return Task.FromResult(PartialView("~/Views/Home/InspectionResults.cshtml", results));
            }

            return Task.FromResult(PartialView("~/Views/Home/NoInspectionResults.cshtml", results));
        }
    }
}