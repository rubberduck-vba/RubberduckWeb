using Rubberduck.SmartIndenter;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace RubberduckWeb.Mocks
{
    public class MockIndenterSettings : IIndenterSettings
    {
        public bool AlignCommentsWithCode { get; set; } = true;

        public bool AlignContinuations { get; set; } = true;

        public int AlignDimColumn { get; set; } = 15;

        public bool AlignDims { get; set; } = false;

        public int EndOfLineCommentColumnSpaceAlignment { get; set; } = 50;

        public EndOfLineCommentStyle EndOfLineCommentStyle { get; set; } = EndOfLineCommentStyle.AlignInColumn;

        public bool ForceCompilerDirectivesInColumn1 { get; set; } = false;

        public bool ForceDebugStatementsInColumn1 { get; set; } = false;

        public bool IgnoreOperatorsInContinuations { get; set; } = true;

        public bool IndentCase { get; set; } = false;

        public bool IndentCompilerDirectives { get; set; } = true;

        public bool IndentEntireProcedureBody { get; set; } = true;

        public bool IndentEnumTypeAsProcedure { get; set; } = false;

        public bool IndentFirstCommentBlock { get; set; } = true;

        public bool IndentFirstDeclarationBlock { get; set; } = true;

        public int IndentSpaces { get; set; } = 4;

        public int LinesBetweenProcedures { get; set; } = 1;

        public bool VerticallySpaceProcedures { get; set; } = true;

        public bool LegacySettingsExist() => false;

        public void LoadLegacyFromRegistry() { }
    }
}