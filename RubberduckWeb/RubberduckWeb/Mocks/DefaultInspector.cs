using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Rubberduck.Parsing.VBA;
using Rubberduck.UI;
using Antlr4.Runtime.Tree;
using Rubberduck.Inspections;
using Rubberduck.Parsing;

namespace RubberduckWeb.Mocks
{
    namespace Rubberduck.Inspections
    {
        public class DefaultInspector
        {
            private readonly IEnumerable<IInspection> _inspections;

            public DefaultInspector(IEnumerable<IInspection> inspections)
            {
                _inspections = inspections;
            }

            public List<ICodeInspectionResult> FindIssuesAsync(RubberduckParserState state, CancellationToken token)
            {
                if (state == null || !state.AllUserDeclarations.Any())
                {
                    return new List<ICodeInspectionResult>();
                }

                state.OnStatusMessageUpdate(RubberduckUI.CodeInspections_Inspecting);

                var allIssues = new ConcurrentBag<ICodeInspectionResult>();

                // Prepare ParseTreeWalker based inspections
                var parseTreeWalkResults = GetParseTreeResults(state);
                foreach (var parseTreeInspection in _inspections.Where(inspection => inspection.Severity != CodeInspectionSeverity.DoNotShow && inspection is IParseTreeInspection))
                {
                    (parseTreeInspection as IParseTreeInspection).ParseTreeResults = parseTreeWalkResults;
                }

                var inspections = _inspections.Where(inspection => inspection.Severity != CodeInspectionSeverity.DoNotShow)
                    .Select(inspection =>
                        new Task(() =>
                        {
                            token.ThrowIfCancellationRequested();
                            var inspectionResults = inspection.GetInspectionResults();

                            if (inspectionResults.Any())
                            {
                                foreach (var inspectionResult in inspectionResults)
                                {
                                    allIssues.Add(inspectionResult);
                                }
                            }
                        })).ToArray();

                foreach (var inspection in inspections)
                {
                    inspection.Start();
                }

                Task.WaitAll(inspections);

                return allIssues.ToList();
            }

            private ParseTreeResults GetParseTreeResults(RubberduckParserState state)
            {
                var result = new ParseTreeResults();

                foreach (var componentTreePair in state.ParseTrees)
                {
                    /*
                    Need to reinitialize these for each and every ParseTree we process, since the results are aggregated in the instances themselves 
                    before moving them into the ParseTreeResults after qualifying them 
                    */
                    var obsoleteCallStatementListener = new ObsoleteCallStatementInspection.ObsoleteCallStatementListener();
                    var obsoleteLetStatementListener = new ObsoleteLetStatementInspection.ObsoleteLetStatementListener();
                    var emptyStringLiteralListener = new EmptyStringLiteralInspection.EmptyStringLiteralListener();
                    var argListWithOneByRefParamListener = new ProcedureCanBeWrittenAsFunctionInspection.ArgListWithOneByRefParamListener();

                    var combinedListener = new CombinedParseTreeListener(new IParseTreeListener[]{
                        obsoleteCallStatementListener,
                        obsoleteLetStatementListener,
                        emptyStringLiteralListener,
                        argListWithOneByRefParamListener,
                    });

                    ParseTreeWalker.Default.Walk(combinedListener, componentTreePair.Value);

                    result.ArgListsWithOneByRefParam = result.ArgListsWithOneByRefParam.Concat(argListWithOneByRefParamListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                    result.EmptyStringLiterals = result.EmptyStringLiterals.Concat(emptyStringLiteralListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                    result.ObsoleteLetContexts = result.ObsoleteLetContexts.Concat(obsoleteLetStatementListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                    result.ObsoleteCallContexts = result.ObsoleteCallContexts.Concat(obsoleteCallStatementListener.Contexts.Select(context => new QualifiedContext(componentTreePair.Key, context)));
                }
                return result;
            }
        }
    }
}
