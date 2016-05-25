using System;
using Microsoft.Vbe.Interop;
using Moq;
using Rubberduck.Inspections;
using Rubberduck.Parsing.VBA;
using Rubberduck.VBEditor.VBEHost;
using RubberduckTests;
using RubberduckWeb.Mocks;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web.Mvc;

namespace RubberduckWeb.Controllers
{
    public class InspectionsController : Controller
    {
        private readonly IEnumerable<IInspection> _inspections;
        private readonly RubberduckParserState _state;

        public InspectionsController(IEnumerable<IInspection> inspections, RubberduckParserState state)
        {
            _inspections = inspections;
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

            var inspectionResults = new List<ICodeInspectionResult>();
            foreach (var inspection in _inspections)
            {
                inspectionResults.AddRange(inspection.GetInspectionResults());
            }

            return string.Join(Environment.NewLine, inspectionResults.Select(s => $"<table class=\"inspections-table\"><tr><td>{s.Description}</td><td>{s.Inspection.Severity}</td><td>{s.Inspection.InspectionType}</td></tr></table>"));
        }
    }
}