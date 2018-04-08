using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Antlr4.Runtime.Tree;
using Rubberduck.Inspections.Concrete;
using Rubberduck.Parsing.Inspections.Abstract;
using Rubberduck.Parsing.Inspections.Resources;
using Rubberduck.Parsing.VBA;

namespace RubberduckWeb.Mocks
{
    namespace Rubberduck.Inspections
    {
        public class DefaultInspector
        {
            //private const int AGGREGATION_THRESHOLD = 128;
            private readonly List<IInspection> _inspections;

            public DefaultInspector(IEnumerable<IInspection> inspections)
            {
                _inspections = inspections.Where(e => e.GetType().Name != nameof(HungarianNotationInspection)).ToList();
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
                            var inspectionResults = inspection.GetInspectionResults(CancellationToken.None);

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

                return allIssues
                    .GroupBy(issue => issue.Inspection.Name)
                    .ToDictionary(grouping => grouping.Key, grouping => grouping.ToList())
                    .SelectMany(kv => kv.Value)
                    .ToList();
            }

            private void WalkTrees(IParseTreeProvider state, IEnumerable<IParseTreeInspection> inspections)
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
