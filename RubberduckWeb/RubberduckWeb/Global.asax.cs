using RubberduckWeb.Controllers;
using System;
using System.Web;
using System.Web.Mvc;
using System.Web.Optimization;
using System.Web.Routing;

namespace RubberduckWeb
{
    public class MvcApplication : System.Web.HttpApplication
    {
        protected void Application_Start()
        {
            AreaRegistration.RegisterAllAreas();
            FilterConfig.RegisterGlobalFilters(GlobalFilters.Filters);
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);
        }

        protected void Application_Error(object sender, EventArgs e)
        {
            var exception = Server.GetLastError();

            // Log it here

            Response.Clear();

            var httpException = exception as HttpException;

            var routeData = new RouteData();
            routeData.Values.Add("controller", "Error");

            if (httpException == null)
            {
                routeData.Values.Add("action", "Generic");
            }
            else
            {
                switch (httpException.GetHttpCode())
                {
                    case 404:
                        routeData.Values.Add("action", "PageNotFound");
                        break;
                    case 418:
                        // I don't know of any situation where "I'm a Teapot" will actually be an error code, but we'll add it just for fun.
                        routeData.Values.Add("action", "Code418");
                        break;
                    case 500:
                        routeData.Values.Add("action", "InternalServerError");
                        break;
                    default:
                        routeData.Values.Add("action", "HttpDefault");
                        break;
                }
            }

            routeData.Values.Add("error", exception);

            Server.ClearError();

            IController controller = new ErrorController();
            controller.Execute(new RequestContext(new HttpContextWrapper(Context), routeData));
        }
    }
}
