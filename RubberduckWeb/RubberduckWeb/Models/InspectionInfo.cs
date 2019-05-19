using System.Linq;
using System.Xml.Linq;
using RubberduckWeb.VBA;

namespace RubberduckWeb.Models
{
    public class InspectionInfo
    {
        public InspectionInfo(string name, XElement node, bool isPreRelease = false)
        {
            var formatter = new FormattedCodeBlockBuilder();
            InspectionName = name.Replace("Inspection", string.Empty).Trim();
            Summary = node.Element("summary")?.Value.Trim();
            References = node.Elements("references").Select(e => e.Attribute("name")?.Value).ToArray();
            Reasoning = node.Element("why")?.Value.Trim();
            Examples = node.Elements("example").Select(e => formatter.Format(e.Value)).ToArray();
            IsPreRelease = isPreRelease;
        }

        public bool IsPreRelease { get; }
        public string InspectionName { get; }
        public string Summary { get; }
        public string[] References { get; }
        public string Reasoning { get; }
        public string[] Examples { get; }
    }
}