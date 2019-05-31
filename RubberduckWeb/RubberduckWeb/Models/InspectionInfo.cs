using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;
using RubberduckWeb.VBA;

namespace RubberduckWeb.Models
{
    public class InspectionsModel
    {
        public InspectionsModel(IEnumerable<InspectionInfo> inspections, string ignoreModuleExampleCode)
        {
            Inspections = inspections;
            var formatter = new FormattedCodeBlockBuilder();
            IgnoreModuleAnnotationExample = formatter.Format(ignoreModuleExampleCode);
        }

        public IEnumerable<InspectionInfo> Inspections { get; }
        public string IgnoreModuleAnnotationExample { get; }
    }

    public class InspectionInfo
    {
        public InspectionInfo(string name, XElement node, bool isPreRelease = false)
        {
            IsPreRelease = isPreRelease;
            InspectionName = name.Replace("Inspection", string.Empty).Trim();
            Summary = node.Element("summary")?.Value.Trim();
            Reasoning = node.Element("why")?.Value.Trim();
            References = node.Elements("references").Select(e => e.Attribute("name")?.Value).ToArray();
            HostApp = node.Element("hostapp")?.Attribute("name")?.Value.Trim();
            Remarks = node.Element("remarks")?.Value;

            var examples = ParseExamples(node);
            ResultExamples = examples.Results;
            NoResultExamples = examples.NoResults;
        }

        private (string[] Results, string[] NoResults) ParseExamples(XElement node)
        {
            var formatter = new FormattedCodeBlockBuilder();

            var resultExamples = new List<string>();
            var noResultExamples = new List<string>();

            var examples = node.Elements("example")
                .GroupBy(e => e.Attribute("hasResult")?.Value ?? "implicit")
                .Select(g => new {HasExample = g.Key, Examples = g.Select(e => formatter.Format(e.Value))})
                .ToDictionary(e => e.HasExample, e => e.Examples.ToArray());

            if (examples.TryGetValue("implicit", out var implicitExamples))
            {
                resultExamples.Add(implicitExamples[0]);
                noResultExamples.AddRange(implicitExamples.Skip(1));
            }

            if (examples.TryGetValue("true", out var explicitResultExamples))
            {
                resultExamples.AddRange(explicitResultExamples);
            }

            if (examples.TryGetValue("false", out var explicitNoResultExamples))
            {
                noResultExamples.AddRange(explicitNoResultExamples);
            }

            return (resultExamples.ToArray(), noResultExamples.ToArray());
        }

        public bool IsPreRelease { get; }
        public string InspectionName { get; }
        public string Summary { get; }
        public string[] References { get; }
        public string HostApp { get; }
        public string Reasoning { get; }
        public string Remarks { get; }
        public string[] ResultExamples { get; private set; }
        public string[] NoResultExamples { get; private set; }
    }
}