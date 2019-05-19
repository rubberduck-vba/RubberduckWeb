using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace RubberduckWeb.Models
{
    public static class RubberduckInspections
    {
        private static readonly string XmlDocumentationUrl = 
            "https://raw.githubusercontent.com/rubberduck-vba/Rubberduck/next/docs/Rubberduck.CodeAnalysis.xml";

        static RubberduckInspections()
        {
            Invalidate();
        }
 
        public static void Invalidate()
        {
            _inspectionsCache
                = new Lazy<IDictionary<string, InspectionInfo>>(CacheValueFactory, 
                    LazyThreadSafetyMode.ExecutionAndPublication);
        }

        public static IDictionary<string, InspectionInfo> Inspections => 
            _inspectionsCache.Value;

        private static Lazy<IDictionary<string, InspectionInfo>> _inspectionsCache;

        private static IDictionary<string, InspectionInfo> CacheValueFactory() => 
            RequestInspections();

        private static IDictionary<string, InspectionInfo> RequestInspections()
        {
            using (var client = new HttpClient())
            {
                var uri = new Uri(XmlDocumentationUrl);
                var task = client.GetAsync(uri);
                task.Wait();
                var response = task.Result;
                var readTask = response.Content.ReadAsStreamAsync();
                readTask.Wait();
                var document = XDocument.Load(readTask.Result);
                var result = GetInspectionDocs(document)
                    .ToDictionary(info => info.InspectionName, info => info);
                return result;
            }
        }

        private static IEnumerable<InspectionInfo> GetInspectionDocs(XDocument doc) =>
            from node in doc.Descendants("member")
            let name = GetInspectionNameOrDefault(node)
            where !string.IsNullOrEmpty(name)
            select new InspectionInfo(name, node);

        private static string GetInspectionNameOrDefault(XElement memberNode)
        {
            var name = memberNode.Attribute("name")?.Value;
            if (name == null || !name.StartsWith("T:") || !name.EndsWith("Inspection"))
            {
                return default(string);
            }

            return name.Substring(name.LastIndexOf(".", StringComparison.Ordinal) + 1);
        }
    }
}