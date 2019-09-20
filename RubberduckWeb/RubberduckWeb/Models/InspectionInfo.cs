using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;
using RubberduckWeb.VBA;

namespace RubberduckWeb.Models
{
    internal static class XElementExtensions
    {
        /// <summary>
        /// Gets an attribute by name, case-insensitive. Matches the beginning of the name, to match both e.g. "hasresults" and "hasresult"
        /// </summary>
        public static XAttribute GetAttribute(this XElement e, string name) 
            => e.Attributes().SingleOrDefault(a => a.Name.LocalName.StartsWith(name, StringComparison.InvariantCultureIgnoreCase));
    }

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

    public class InspectionCodeExample
    {
        public InspectionCodeExample(bool? hasResult, IEnumerable<InspectionCodeExampleModule> modules)
        {
            HasResult = hasResult.HasValue && hasResult.Value || !hasResult.HasValue; // null == true
            Modules = modules;
        }

        public bool HasResult { get; }
        public IEnumerable<InspectionCodeExampleModule> Modules { get; }
    }

    public class InspectionCodeExampleModule
    {
        public InspectionCodeExampleModule(string formattedContent, string name = null, string moduleType = null)
        {
            Name = name;
            ModuleType = moduleType;
            FormattedContent = formattedContent;
        }

        public string Name { get; }
        public string ModuleType { get; }
        public string FormattedContent { get; }
    }

    public class InspectionInfo
    {
        public InspectionInfo(string name, XElement node, bool isPreRelease = false)
        {
            IsPreRelease = isPreRelease;
            InspectionName = name.Replace("Inspection", string.Empty).Trim();
            Summary = node.Element("summary")?.Value.Trim();
            IsHidden = node.Element("summary")?.GetAttribute("hidden")?.Value.Equals("true", StringComparison.InvariantCultureIgnoreCase) ?? false;
            Reasoning = node.Element("why")?.Value.Trim();
            References = node.Elements("reference").Select(e => e.GetAttribute("name")?.Value).ToArray();
            HostApp = node.Element("hostapp")?.GetAttribute("name")?.Value.Trim();
            Remarks = node.Element("remarks")?.Value;

            Examples = ParseExamples(node);
        }

        private InspectionCodeExample[] ParseExamples(XElement node)
        {
            var formatter = new FormattedCodeBlockBuilder();
            return node.Elements("example")
                .Select(e => new InspectionCodeExample(
                    e.GetAttribute("hasresult")?.Value.Equals("true", StringComparison.InvariantCultureIgnoreCase),
                    e.Elements("module").Select(m => 
                        new InspectionCodeExampleModule(
                            formatter.Format(m.Nodes().OfType<XCData>().Single().Value), 
                            m.GetAttribute("name")?.Value,
                            m.GetAttribute("type")?.Value))
                        .Concat(e.Nodes().OfType<XCData>().Select(x =>
                            new InspectionCodeExampleModule(formatter.Format(x.Value))).Take(1))
                )).ToArray();
        }

        public bool IsPreRelease { get; }
        public bool IsHidden { get; }
        public string InspectionName { get; }
        public string Summary { get; }
        public string[] References { get; }
        public string HostApp { get; }
        public string Reasoning { get; }
        public string Remarks { get; }
        public InspectionCodeExample[] Examples { get; }
    }
}