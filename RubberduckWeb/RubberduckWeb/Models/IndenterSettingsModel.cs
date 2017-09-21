using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace RubberduckWeb.Models
{
    public class IndenterSettingsModel : Mocks.MockIndenterSettings
    {
        public SelectList EndOfLineCommentStyleSelectList { get; } = new SelectList(Enum.GetNames(typeof(Rubberduck.SmartIndenter.EndOfLineCommentStyle)));
        public string Code { get; set; }
    }
}