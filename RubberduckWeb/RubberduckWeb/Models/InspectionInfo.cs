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
        public InspectionCodeExample(bool? hasResult, IEnumerable<FormattedCodeExampleModule> modules)
        {
            HasResult = hasResult.HasValue && hasResult.Value || !hasResult.HasValue; // null == true
            Modules = modules;
        }

        public bool HasResult { get; }
        public IEnumerable<FormattedCodeExampleModule> Modules { get; }
    }

    public class QuickFixCodeExample
    {
        public QuickFixCodeExample(IEnumerable<FormattedCodeExampleModule> modulesBefore, IEnumerable<FormattedCodeExampleModule> modulesAfter)
        {
            ModulesBefore = modulesBefore;
            ModulesAfter = modulesAfter;
        }

        public IEnumerable<FormattedCodeExampleModule> ModulesBefore { get; }
        public IEnumerable<FormattedCodeExampleModule> ModulesAfter { get; }

    }

    public class FormattedCodeExampleModule
    {
        public FormattedCodeExampleModule(string formattedContent, string name = null, string moduleType = null)
        {
            Name = name;
            ModuleType = moduleType;
            FormattedContent = formattedContent;
        }

        public string Name { get; }
        public string ModuleType { get; }
        public string FormattedContent { get; }
    }

    public class QuickFixInfo : IEquatable<QuickFixInfo>
    {
        public QuickFixInfo(string name, XElement node, bool isPreRelease = false)
        {
            QuickFixName = name.Replace("QuickFix", string.Empty).Trim();
            Summary = node.Element("summary")?.Value.Trim();
            IsPreRelease = isPreRelease;

            var canFixNode = node.Element("canfix");
            CanFixInProcedure= Convert.ToBoolean(canFixNode?.GetAttribute("procedure")?.Value ?? "true");
            CanFixInModule = Convert.ToBoolean(canFixNode?.GetAttribute("module")?.Value ?? "true");
            CanFixInProject = Convert.ToBoolean(canFixNode?.GetAttribute("project")?.Value ?? "true");

            Inspections = node.Element("inspections")?
                .Elements("inspection")
                .Select(e => e.GetAttribute("name")?.Value)
                .ToArray();

            Examples = ParseExamples(node);
        }

        public IEnumerable<string> Inspections { get; } = Enumerable.Empty<string>();

        public string QuickFixName { get; }

        public string Summary { get; }
        public bool IsPreRelease { get; }

        public bool CanFixInProcedure { get; }
        public bool CanFixInModule { get; }
        public bool CanFixInProject { get; }

        public QuickFixCodeExample[] Examples { get; }

        public bool Equals(QuickFixInfo other) => other.QuickFixName == QuickFixName;

        public override bool Equals(object obj) => Equals((QuickFixInfo)obj);
        public override int GetHashCode() => QuickFixName.GetHashCode();

        private QuickFixCodeExample[] ParseExamples(XElement node)
        {
            var formatter = new FormattedCodeBlockBuilder();
            var exampleNodes = node.Elements("example");
            var result = exampleNodes?
                .Select(e => new QuickFixCodeExample(
                    e.Element("before")?.Elements("module")?.Select(m =>
                        new FormattedCodeExampleModule(
                            formatter.Format(m.Nodes().OfType<XCData>().Single().Value),
                            m.GetAttribute("name")?.Value,
                            m.GetAttribute("type")?.Value))
                        .Concat(e.Element("before")?.Nodes().OfType<XCData>().Take(1).Select(x => 
                            new FormattedCodeExampleModule(formatter.Format(x.Value))))
                        ,
                    e.Element("after")?.Elements("module")?.Select(m =>
                        new FormattedCodeExampleModule(
                            formatter.Format(m.Nodes().OfType<XCData>().Single().Value),
                            m.GetAttribute("name")?.Value,
                            m.GetAttribute("type")?.Value))
                        .Concat(e.Element("after")?.Nodes().OfType<XCData>().Take(1).Select(x => 
                            new FormattedCodeExampleModule(formatter.Format(x.Value))))
                )).ToArray();
            return result;
        }
    }

    public class InspectionInfo : IEquatable<InspectionInfo>
    {
        public InspectionInfo(string name, XElement node, bool isPreRelease = false)
        {
            TypeName = name;

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
                        new FormattedCodeExampleModule(
                            formatter.Format(m.Nodes().OfType<XCData>().Single().Value), 
                            m.GetAttribute("name")?.Value,
                            m.GetAttribute("type")?.Value))
                        .Concat(e.Nodes().OfType<XCData>().Select(x =>
                            new FormattedCodeExampleModule(formatter.Format(x.Value))).Take(1))
                )).ToArray();
        }

        public bool IsPreRelease { get; }
        public bool IsHidden { get; }
        public string TypeName { get; }
        public string InspectionName { get; }
        public string Summary { get; }
        public string[] References { get; }
        public string HostApp { get; }
        public string Reasoning { get; }
        public string Remarks { get; }
        public InspectionCodeExample[] Examples { get; }
        public QuickFixInfo[] QuickFixes { get; set; }

        public override bool Equals(object obj) => Equals((InspectionInfo)obj);

        public bool Equals(InspectionInfo other) => other.InspectionName == InspectionName;

        public override int GetHashCode() => InspectionName.GetHashCode();
    }
}