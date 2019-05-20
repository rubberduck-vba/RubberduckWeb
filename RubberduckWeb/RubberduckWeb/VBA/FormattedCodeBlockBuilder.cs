using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using Antlr4.Runtime;
using Antlr4.Runtime.Atn;
using Antlr4.Runtime.Misc;
using Rubberduck.Parsing.Grammar;
using Rubberduck.SmartIndenter;

namespace RubberduckWeb.VBA
{
    public class FormattedCodeBlockBuilder
    {
        private static readonly string KeywordClass = "keyword";
        private static readonly string StringLiteralClass = "string-literal";

        public string Format(string code)
        {
            var indenter = new Indenter(null, () => new IndenterSettings(true));
            var indentedCode = indenter.Indent(code.Split('\n').Select(line => line.Replace("\r", string.Empty))).ToArray();

            var builder = new StringBuilder();
            var tokens = Tokenize(string.Join("\n", indentedCode));

            var parser = new VBAParser(tokens)
            {
                Interpreter = {PredictionMode = PredictionMode.Ll}
            };
            var listeners = new IntervalListener[]
            {
                new CommentIntervalsListener(),
                new AnnotationIntervalsListener(),
                new AttributeIntervalsListener(),
                new AttributeValueIntervalsListener(),
            };

            foreach (var listener in listeners)
            {
                parser.AddParseListener(listener);
            }
            parser.startRule();

            for (var i = 0; i < tokens.Size; i++)
            {
                var token = tokens.Get(i);
                var listener = listeners
                    .Select(e => 
                    new
                    {
                        IsValidInterval = e.IsValidInterval(token, out var interval),
                        Interval = interval,
                        Class = e.Class
                    })
                .FirstOrDefault(e => e.IsValidInterval);

                if (listener != null)
                {
                    builder.Append($"<span class=\"{listener.Class}\">{tokens.GetText(listener.Interval)}</span>");
                    i = listener.Interval.b;
                }
                else
                {
                    if (StringLiteralTokens.Contains(token.Type))
                    {
                        builder.Append($"<span class=\"{StringLiteralClass}\">{token.Text}</span>");
                    }
                    else if (KeywordTokens.Contains(token.Type))
                    {
                        builder.Append($"<span class=\"{KeywordClass}\">{token.Text}</span>");
                    }
                    else if (token.Type != VBAParser.Eof)
                    {
                        builder.Append(token.Text);
                    }
                }
            }

            var lines = builder.ToString().Split('\n')
                .Where(line => !string.IsNullOrWhiteSpace(line))
                .ToArray();
            var indent = lines.Last().TakeWhile(char.IsWhiteSpace).Count();
            var formattedLines = from line in lines
                let trimmed = line.Substring(indent)
                select FormatIndents(trimmed);
            return string.Join("<br/>", formattedLines);
        }

        private static string FormatIndents(string line)
        {
            var formatted = line;
            var indent = line.TakeWhile(char.IsWhiteSpace).Count();
            if (indent > 0)
            {
                formatted = line.Substring(0, indent).Replace(" ", "&nbsp;")
                            + line.Substring(indent);
            }
            return formatted;
        }
        
        private ITokenStream Tokenize(string code)
        {
            AntlrInputStream input;
            using (var reader = new StringReader(code))
            {
                input = new AntlrInputStream(reader);
            }
            var lexer = new VBALexer(input);
            return new CommonTokenStream(lexer);
        }

        #region token classes
        private static readonly HashSet<int> StringLiteralTokens = new HashSet<int>
        {
            VBAParser.STRINGLITERAL,
            VBAParser.DATELITERAL,
        };
        private static readonly HashSet<int> KeywordTokens = new HashSet<int> { 
            VBAParser.ANY,
            VBAParser.CURRENCY,
            VBAParser.DEBUG,
            VBAParser.DOEVENTS,
            VBAParser.EXIT,
            VBAParser.FIX,
            VBAParser.INPUTB,
            VBAParser.LBOUND,
            VBAParser.LONGLONG,
            VBAParser.LONGPTR,
            VBAParser.OPTION,
            VBAParser.PSET,
            VBAParser.SCALE,
            VBAParser.SGN,
            VBAParser.UBOUND,
            VBAParser.ACCESS,
            VBAParser.ADDRESSOF,
            VBAParser.ALIAS,
            VBAParser.AND,
            VBAParser.ATTRIBUTE,
            VBAParser.APPEND,
            VBAParser.AS,
            VBAParser.BEGINPROPERTY,
            VBAParser.BEGIN,
            VBAParser.BINARY,
            VBAParser.BOOLEAN,
            VBAParser.BYVAL,
            VBAParser.BYREF,
            VBAParser.BYTE,
            VBAParser.CALL,
            VBAParser.CASE,
            VBAParser.CDECL,
            VBAParser.CLASS,
            VBAParser.CLOSE,
            VBAParser.CONST,
            VBAParser.CONST,
            VBAParser.DATABASE,
            VBAParser.DATE,
            VBAParser.DECLARE,
            VBAParser.DEFBOOL,
            VBAParser.DEFBYTE,
            VBAParser.DEFDATE,
            VBAParser.DEFDBL,
            VBAParser.DEFCUR,
            VBAParser.DEFINT,
            VBAParser.DEFLNG,
            VBAParser.DEFLNGLNG,
            VBAParser.DEFLNGPTR,
            VBAParser.DEFOBJ,
            VBAParser.DEFSNG,
            VBAParser.DEFSTR,
            VBAParser.DEFVAR,
            VBAParser.DIM,
            VBAParser.DO,
            VBAParser.DOUBLE,
            VBAParser.EACH,
            VBAParser.ELSE,
            VBAParser.ELSEIF,
            VBAParser.EMPTY,
            VBAParser.END_ENUM,
            VBAParser.END_FUNCTION,
            VBAParser.END_IF,
            VBAParser.ENDPROPERTY,
            VBAParser.END_SELECT,
            VBAParser.END_SUB,
            VBAParser.END_TYPE,
            VBAParser.END_WITH,
            VBAParser.END,
            VBAParser.ENUM,
            VBAParser.EQV,
            VBAParser.ERASE,
            VBAParser.ERROR,
            VBAParser.EVENT,
            VBAParser.EXIT_DO,
            VBAParser.EXIT_FOR,
            VBAParser.EXIT_FUNCTION,
            VBAParser.EXIT_PROPERTY,
            VBAParser.EXIT_SUB,
            VBAParser.FALSE,
            VBAParser.FRIEND,
            VBAParser.FOR,
            VBAParser.FUNCTION,
            VBAParser.GET,
            VBAParser.GLOBAL,
            VBAParser.GOSUB,
            VBAParser.GOTO,
            VBAParser.IF,
            VBAParser.IMP,
            VBAParser.IMPLEMENTS,
            VBAParser.IN,
            VBAParser.INPUT,
            VBAParser.IS,
            VBAParser.INTEGER,
            VBAParser.LOCK,
            VBAParser.LONG,
            VBAParser.LOOP,
            VBAParser.LET,
            VBAParser.LIB,
            VBAParser.LIKE,
            VBAParser.LINE_INPUT,
            VBAParser.LOCK_READ,
            VBAParser.LOCK_WRITE,
            VBAParser.LOCK_READ_WRITE,
            VBAParser.LSET,
            VBAParser.MOD,
            VBAParser.NAME,
            VBAParser.NEXT,
            VBAParser.NEW,
            VBAParser.NOT,
            VBAParser.NOTHING,
            VBAParser.NULL,
            VBAParser.OBJECT,
            VBAParser.ON_ERROR,
            VBAParser.ON_LOCAL_ERROR,
            VBAParser.OPEN,
            VBAParser.OPTIONAL,
            VBAParser.OPTION_BASE,
            VBAParser.OPTION_EXPLICIT,
            VBAParser.OPTION_COMPARE,
            VBAParser.OPTION_PRIVATE_MODULE,
            VBAParser.OR,
            VBAParser.OUTPUT,
            VBAParser.PARAMARRAY,
            VBAParser.PRESERVE,
            VBAParser.PRINT,
            VBAParser.PRIVATE,
            VBAParser.PROPERTY_GET,
            VBAParser.PROPERTY_LET,
            VBAParser.PROPERTY_SET,
            VBAParser.PTRSAFE,
            VBAParser.PUBLIC,
            VBAParser.PUT,
            VBAParser.RANDOM,
            VBAParser.RANDOMIZE,
            VBAParser.RAISEEVENT,
            VBAParser.READ,
            VBAParser.READ_WRITE,
            VBAParser.REDIM,
            VBAParser.REM,
            VBAParser.RESET,
            VBAParser.RESUME,
            VBAParser.RETURN,
            VBAParser.RSET,
            VBAParser.SEEK,
            VBAParser.SELECT,
            VBAParser.SET,
            VBAParser.SHARED,
            VBAParser.SINGLE,
            VBAParser.STATIC,
            VBAParser.STEP,
            VBAParser.STOP,
            VBAParser.STRING,
            VBAParser.SUB,
            VBAParser.TAB,
            VBAParser.TEXT,
            VBAParser.THEN,
            VBAParser.TO,
            VBAParser.TRUE,
            VBAParser.TYPE,
            VBAParser.TYPEOF,
            VBAParser.UNLOCK,
            VBAParser.UNTIL,
            VBAParser.VARIANT,
            VBAParser.VERSION,
            VBAParser.WEND,
            VBAParser.WITH,
            VBAParser.WITHEVENTS,
            VBAParser.WRITE,
            VBAParser.XOR
        };
        #endregion

        public abstract class IntervalListener : VBAParserBaseListener
        {
            private readonly IList<Interval> _intervals = new List<Interval>();
            
            protected IntervalListener(string cssClass)
            {
                Class = cssClass;
            }

            public string Class { get; }

            public bool IsValidInterval(IToken token, out Interval interval)
            {
                if (!_intervals.Any())
                {
                    interval = Interval.Invalid;
                    return false;
                }

                interval = ExistsIn(_intervals, token);
                return !interval.Equals(default(Interval));
            }

            private static Interval ExistsIn(IList<Interval> source, IToken token)
            {
                var tokenInterval = new Interval(token.TokenIndex, token.TokenIndex);
                return source.SingleOrDefault(e => e.ProperlyContains(tokenInterval));
            }

            protected void AddInterval(Interval interval)
            {
                if (!_intervals.Any(e => e.ProperlyContains(interval)))
                {
                    _intervals.Add(interval);
                }
            }
        }

        public class CommentIntervalsListener : IntervalListener
        {
            public CommentIntervalsListener() : base("comment") { }

            public override void ExitCommentOrAnnotation(VBAParser.CommentOrAnnotationContext context)
            {
                if (context.annotationList() == null)
                {
                    // exclude the line-ending token
                    AddInterval(new Interval(context.SourceInterval.a, context.SourceInterval.b - 1));
                }
            }
        }

        public class AnnotationIntervalsListener : IntervalListener
        {
            public AnnotationIntervalsListener() : base("annotation") { }

            public override void ExitAnnotationList(VBAParser.AnnotationListContext context)
            {
                // exclude the line-ending token at the end
                AddInterval(new Interval(context.SourceInterval.a, context.SourceInterval.b - 1));
            }
        }

        public class AttributeIntervalsListener : IntervalListener
        {
            public AttributeIntervalsListener() : base("attribute") { }

            public override void ExitAttributeStmt(VBAParser.AttributeStmtContext context)
            {
                // exclude the line-ending token
                AddInterval(new Interval(context.SourceInterval.a, context.SourceInterval.b - 1));
            }
        }

        public class AttributeValueIntervalsListener : IntervalListener
        {
            public AttributeValueIntervalsListener() : base("attribute-value") { }

            public override void ExitAttributeStmt(VBAParser.AttributeStmtContext context)
            {
                var value = context.attributeValue();
                if (value != null)
                {
                    // exclude the line-ending token
                    AddInterval(new Interval(value.First().SourceInterval.a, value.Last().SourceInterval.b - 1));
                }
            }
        }
    }


}