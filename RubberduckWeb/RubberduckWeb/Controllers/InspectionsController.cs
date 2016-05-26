using System;
using Microsoft.Vbe.Interop;
using Moq;
using Rubberduck.Parsing.VBA;
using Rubberduck.VBEditor.VBEHost;
using RubberduckTests;
using RubberduckWeb.Mocks;
using System.Linq;
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
        public string GetInspectionResults(string code)
        {
            //Arrange
            var builder = new MockVbeBuilder();
            VBComponent component;
            var vbe = builder.BuildFromSingleStandardModule(code, out component);
            var mockHost = new Mock<IHostApplication>();
            mockHost.SetupAllProperties();
            var parser = MockParser.Create(vbe.Object, _state);

            Task.Run(() => parser.Parse()).Wait();
            if (parser.State.Status != ParserState.Ready)
            {
                return $"Rubberduck could not compile this code: {parser.State.Status}.";
            }
            
            var inspectionResults = _inspector.FindIssuesAsync(parser.State, new System.Threading.CancellationToken());

            return string.Join(Environment.NewLine,
                inspectionResults.Select(s =>
                        $"<table class=\"inspections-table\"><tr><td>{s.Description}</td><td>{s.Inspection.Severity}</td><td>{s.Inspection.InspectionType}</td></tr></table>"));
        }
    }
}