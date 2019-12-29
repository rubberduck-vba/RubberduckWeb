using System.Collections.Generic;
using System.Linq;

namespace RubberduckWeb.Models
{
    public class CodeAnalysisXmlDocs
    {
        private readonly HashSet<InspectionInfo> _inspections;
        private readonly HashSet<QuickFixInfo> _quickFixes;

        public CodeAnalysisXmlDocs()
            : this(Enumerable.Empty<InspectionInfo>(), Enumerable.Empty<QuickFixInfo>())
        { }

        public CodeAnalysisXmlDocs(IEnumerable<InspectionInfo> inspections, IEnumerable<QuickFixInfo> quickFixes)
        {
            _inspections = new HashSet<InspectionInfo>(SetInspectionQuickFixes(inspections, quickFixes));
            _quickFixes = new HashSet<QuickFixInfo>(quickFixes);
        }

        private static IEnumerable<InspectionInfo> SetInspectionQuickFixes(IEnumerable<InspectionInfo> inspections, IEnumerable<QuickFixInfo> quickFixes)
        {
            foreach (var inspection in inspections)
            {
                inspection.QuickFixes = quickFixes.Where(fix => fix.Inspections == null /* IgnoreOnce applies to all inspections */ || fix.Inspections.Contains(inspection.TypeName)).ToArray();
                yield return inspection;
            }
        }

        public bool HasInspection(InspectionInfo info) => _inspections.Contains(info);
        public bool HasQuickFix(QuickFixInfo info) => _quickFixes.Contains(info);

        public IEnumerable<InspectionInfo> Inspections => _inspections;
        public IEnumerable<QuickFixInfo> QuickFixes => _quickFixes;
    }
}