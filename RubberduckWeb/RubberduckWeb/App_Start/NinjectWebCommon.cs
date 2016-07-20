using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using Ninject.Extensions.Conventions;
using Ninject.Extensions.NamedScope;
using Rubberduck.Inspections;
using Rubberduck.Parsing;
using Rubberduck.Parsing.VBA;
using Rubberduck.VBEditor.VBEHost;

[assembly: WebActivatorEx.PreApplicationStartMethod(typeof(RubberduckWeb.App_Start.NinjectWebCommon), "Start")]
[assembly: WebActivatorEx.ApplicationShutdownMethodAttribute(typeof(RubberduckWeb.App_Start.NinjectWebCommon), "Stop")]

namespace RubberduckWeb.App_Start
{
    using System;
    using System.Web;

    using Microsoft.Web.Infrastructure.DynamicModuleHelper;

    using Ninject;
    using Ninject.Web.Common;

    public static class NinjectWebCommon 
    {
        private static readonly Bootstrapper bootstrapper = new Bootstrapper();

        /// <summary>
        /// Starts the application
        /// </summary>
        public static void Start() 
        {
            DynamicModuleUtility.RegisterModule(typeof(OnePerRequestHttpModule));
            DynamicModuleUtility.RegisterModule(typeof(NinjectHttpModule));
            bootstrapper.Initialize(CreateKernel);
        }
        
        /// <summary>
        /// Stops the application.
        /// </summary>
        public static void Stop()
        {
            bootstrapper.ShutDown();
        }
        
        /// <summary>
        /// Creates the kernel that will manage your application.
        /// </summary>
        /// <returns>The created kernel.</returns>
        private static IKernel CreateKernel()
        {
            var kernel = new StandardKernel();
            try
            {
                kernel.Bind<Func<IKernel>>().ToMethod(ctx => () => new Bootstrapper().Kernel);
                kernel.Bind<IHttpModule>().To<HttpApplicationInitializationHttpModule>();

                RegisterServices(kernel);
                return kernel;
            }
            catch(Exception exception)
            {
                kernel.Dispose();
                throw;
            }
        }

        /// <summary>
        /// Load your modules or register your services here!
        /// </summary>
        /// <param name="kernel">The kernel.</param>
        private static void RegisterServices(IKernel kernel)
        {
            kernel.Bind<RubberduckParserState>().ToSelf().InCallScope();
            kernel.Bind<RubberduckParser>().ToSelf().InCallScope();

            var assemblies = new[]
            {
                Assembly.GetExecutingAssembly(),
                Assembly.GetAssembly(typeof(IHostApplication)),
                Assembly.GetAssembly(typeof(InspectionBase)),
                Assembly.GetAssembly(typeof(IRubberduckParser))
            };

            BindCodeInspectionTypes(kernel);
            ApplyDefaultInterfacesConvention(kernel, assemblies);
        }

        private static void ApplyDefaultInterfacesConvention(IKernel kernel, IEnumerable<Assembly> assemblies)
        {
            kernel.Bind(t => t.From(assemblies)
                .SelectAllClasses()
                // inspections & factories have their own binding rules
                .Where(type => !type.Name.EndsWith("Factory") && !type.Name.EndsWith("ConfigProvider") && !type.GetInterfaces().Contains(typeof(IInspection)))
                .BindDefaultInterface()
                .Configure(binding => binding.InCallScope())); // TransientScope wouldn't dispose disposables
        }

        private static void BindCodeInspectionTypes(IKernel kernel)
        {
            var assembly = Assembly.GetAssembly(typeof (InspectionBase));
            var inspections = assembly.GetTypes().Where(type => type.BaseType == typeof(InspectionBase));

            // multibinding for IEnumerable<IInspection> dependency
            foreach (var inspection in inspections)
            {
                if (inspection.Name == nameof(ImplicitActiveSheetReferenceInspection) ||
                    inspection.Name == nameof(ImplicitActiveWorkbookReferenceInspection) ||
                    inspection.Name == nameof(ParameterNotUsedInspection))
                {
                    continue;
                }

                kernel.Bind<IInspection>().To(inspection).InCallScope();
            }
        }
    }
}
