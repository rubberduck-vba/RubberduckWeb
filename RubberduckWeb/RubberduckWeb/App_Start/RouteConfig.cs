using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace RubberduckWeb
{
    public class RouteConfig
    {
        public static void RegisterRoutes(RouteCollection routes)
        {
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");

            /* ex: 
                http://www.rubberduck-vba.com/about
                http://www.rubberduck-vba.com/contact
            */
            routes.MapRoute(
                name: "OnlyAction",
                url: "{action}",
                defaults: new { controller = "Home", action = "Index" }
            );

            // default mvc routing 
            routes.MapRoute(
                name: "Default",
                url: "{controller}/{action}/{id}",
                defaults: new { controller = "Home", action = "Index", id = UrlParameter.Optional }
            );
        }
    }
}
