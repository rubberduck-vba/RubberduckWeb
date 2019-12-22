using RubberduckWeb.Controllers;
using System;
using System.Web;
using System.Web.Mvc;
using System.Web.Optimization;
using System.Web.Routing;

namespace RubberduckWeb
{
    public class MvcApplication : HttpApplication
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


            var routeData = new RouteData();
            routeData.Values.Add("controller", "Error");

            if (exception is HttpException httpException)
            {
                Response.Clear();

                switch (httpException.GetHttpCode())
                {
                    case 404:
                        Response.Redirect("~/Error/PageNotFound");
                        break;
                    case 418:
                        // I don't know of any situation where "I'm a Teapot" will actually be an error code, but we'll add it just for fun.
                        Response.Redirect("~/Error/Code418");
                        break;
                    case 500:
                        Response.Redirect("~/Error/InternalServerError");
                        break;
                    default:
                        Response.Redirect($"~/Error/HttpDefault/{httpException.GetHttpCode()}");
                        break;
                }
            }
        }
    }
}
