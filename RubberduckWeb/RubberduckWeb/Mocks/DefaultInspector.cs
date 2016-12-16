using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Antlr4.Runtime.Tree;
using Moq;
using Rubberduck.Inspections;
using Rubberduck.Inspections.Abstract;
using Rubberduck.Inspections.Resources;
using Rubberduck.Parsing;
using Rubberduck.Parsing.VBA;
using Rubberduck.Settings;
using Rubberduck.SettingsProvider;
using Rubberduck.UI;

namespace RubberduckWeb.Mocks
{
    namespace Rubberduck.Inspections
    {
        public class DefaultInspector
        {
            private readonly List<IInspection> _inspections;

            public DefaultInspector(IEnumerable<IInspection> inspections, RubberduckParserState state)
            {
                _inspections = inspections.Where(x => x.Name != nameof(UndeclaredVariableInspection)).ToList();

                if (_inspections.All(i => i.Name != nameof(ParameterNotUsedInspection)))
                {
                    _inspections.Add(new ParameterNotUsedInspection(state, null));
                }

                if (_inspections.All(i => i.Name != nameof(UseMeaningfulNameInspection)))
                {
                    var settings = new Mock<IPersistanceService<CodeInspectionSettings>>();
                    settings.Setup(s => s.Load(It.IsAny<CodeInspectionSettings>()))
                        .Returns(new CodeInspectionSettings());
                    _inspections.Add(new UseMeaningfulNameInspection(null, state, settings.Object));
                }
            }

            public List<IInspectionResult> Inspect(RubberduckParserState state)
            {
                if (state == null || !state.AllUserDeclarations.Any())
                {
                    return new List<IInspectionResult>();
                }

                state.OnStatusMessageUpdate(RubberduckUI.CodeInspections_Inspecting);

                var allIssues = new ConcurrentBag<IInspectionResult>();

                // Prepare ParseTreeWalker based inspections
                var parseTreeWalkResults = GetParseTreeResults(state);
                foreach (var parseTreeInspection in _inspections.Where(inspection => inspection.Severity != CodeInspectionSeverity.DoNotShow && inspection is IParseTreeInspection))
                {
                    ((IParseTreeInspection)parseTreeInspection).SetResults(parseTreeWalkResults);
                }

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

                return allIssues.ToList();
            }

            private IEnumerable<QualifiedContext> GetParseTreeResults(RubberduckParserState state)
            {
                var result = new List<QualifiedContext>();

                foreach (var componentTreePair in state.ParseTrees)
                {
                    /*
                    Need to reinitialize these for each and every ParseTree we process, since the results are aggregated in the instances themselves 
                    before moving them into the ParseTreeResults after qualifying them 
                    */
                    var obsoleteCallStatementListener = new ObsoleteCallStatementInspection.ObsoleteCallStatementListener();
                    var obsoleteLetStatementListener = new ObsoleteLetStatementInspection.ObsoleteLetStatementListener();
                    var emptyStringLiteralListener = new EmptyStringLiteralInspection.EmptyStringLiteralListener();
                    var argListWithOneByRefParamListener = new ProcedureCanBeWrittenAsFunctionInspection.SingleByRefParamArgListListener();
                    var malformedAnnotationListener = new MissingAnnotationArgumentInspection.InvalidAnnotationStatementListener();

                    var combinedListener = new CombinedParseTreeListener(new IParseTreeListener[]{
                        obsoleteCallStatementListener,
                        obsoleteLetStatementListener,
                        emptyStringLiteralListener,
                        argListWithOneByRefParamListener,
                        malformedAnnotationListener
                    });

                    ParseTreeWalker.Default.Walk(combinedListener, componentTreePair.Value);

                    result.AddRange(argListWithOneByRefParamListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                    result.AddRange(emptyStringLiteralListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                    result.AddRange(obsoleteLetStatementListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                    result.AddRange(obsoleteCallStatementListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                    result.AddRange(malformedAnnotationListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                }
                return result;
            }
        }
    }
}
