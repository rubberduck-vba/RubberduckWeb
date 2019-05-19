using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using RubberduckWeb.VBA;

namespace RubberduckWeb.Tests
{
    [TestClass]
    public class FormattedCodeBlockTests
    {
        [TestMethod]
        public void IndentsWithNonBreakingSpaces()
        {
            var code = @"
Public Sub DoSomething()
Dim foo As Long
foo = 12 ' assignment is redundant
foo = 34
End Sub
";
            var expected = @"
<span class=""keyword"">Public</span> <span class=""keyword"">Sub</span> DoSomething()<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<span class=""keyword""Dim</span> foo <span class=""keyword"">As</span> <span class=""keyword"">Long</span><br/>
&nbsp;&nbsp;&nbsp;&nbsp;foo = 12 <span class=""comment""' assignment is redundant</span></br>
&nbsp;&nbsp;&nbsp;&nbsp;foo = 34<<br/>
<span class=""keyword"">End Sub</span><br/>
".Replace("\n", string.Empty);
            
            var builder = new FormattedCodeBlockBuilder();
            var result = builder.Format(code);
            Assert.AreEqual(expected, result);
        }
    }
}
