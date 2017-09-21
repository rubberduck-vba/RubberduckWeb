using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Antlr4.Runtime.Tree;
using Moq;
using Rubberduck.Inspections.Concrete;
using Rubberduck.Parsing.Inspections.Abstract;
using Rubberduck.Parsing.Inspections.Resources;
using Rubberduck.Parsing.VBA;
using Rubberduck.Settings;
using Rubberduck.SettingsProvider;
using Rubberduck.UI.Inspections;

namespace RubberduckWeb.Mocks
{
    namespace Rubberduck.Inspections
    {
        public class DefaultInspector
        {
            private const int AGGREGATION_THRESHOLD = 128;
            private readonly List<IInspection> _inspections;

            public DefaultInspector(IEnumerable<IInspection> inspections, RubberduckParserState state)
            {
                _inspections = inspections.ToList();

                if (_inspections.All(i => i.Name != nameof(UseMeaningfulNameInspection)))
                {
                    var settings = new Mock<IPersistanceService<CodeInspectionSettings>>();
                    settings.Setup(s => s.Load(It.IsAny<CodeInspectionSettings>()))
                        .Returns(new CodeInspectionSettings());
                    _inspections.Add(new UseMeaningfulNameInspection(state, settings.Object));
                }
            }

            public List<IInspectionResult> Inspect(RubberduckParserState state)
            {
                if (state == null || !state.AllUserDeclarations.Any())
                {
                    return new List<IInspectionResult>();
                }

                var allIssues = new ConcurrentBag<IInspectionResult>();

                // Prepare ParseTreeWalker based inspections
                WalkTrees(state, _inspections.OfType<IParseTreeInspection>());

                var inspections = _inspections.Where(inspection => inspection.Severity != CodeInspectionSeverity.DoNotShow)
                    .Select(inspection =>
                        new Task(() =>
                        {
                            var inspectionResults = inspection.GetInspectionResults();

                            foreach (var inspectionResult in inspectionResults)
                            {
                                allIssues.Add(inspectionResult);
                            }
                        })).ToArray();

                foreach (var inspection in inspections)
                {
                    inspection.Start();
                }

                Task.WaitAll(inspections);

                var issuesByType = allIssues.GroupBy(issue => issue.Inspection.Name)
                            .ToDictionary(grouping => grouping.Key, grouping => grouping.ToList());
                var results = issuesByType.Where(kv => kv.Value.Count <= AGGREGATION_THRESHOLD)
                    .SelectMany(kv => kv.Value)
                    .Union(issuesByType.Where(kv => kv.Value.Count > AGGREGATION_THRESHOLD)
                    .Select(kv => new AggregateInspectionResult(kv.Value.OrderBy(i => i.QualifiedSelection).First(), kv.Value.Count)))
                    .ToList();

                return results;
            }

            private void WalkTrees(RubberduckParserState state, IEnumerable<IParseTreeInspection> inspections)
            {
                var listeners =
                    inspections.Where(i => i.Severity != CodeInspectionSeverity.DoNotShow)
                        .Select(inspection =>
                        {
                            inspection.Listener.ClearContexts();
                            return inspection.Listener;
                        })
                        .ToList();

                foreach (var componentTreePair in state.ParseTrees)
                {
                    foreach (var listener in listeners)
                    {
                        listener.CurrentModuleName = componentTreePair.Key;
                    }

                    ParseTreeWalker.Default.Walk(new CombinedParseTreeListener(listeners), componentTreePair.Value);
                }
            }
        }
    }
}
