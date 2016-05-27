using System.Web.Mvc;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using RubberduckWeb.Controllers;

namespace RubberduckWeb.Tests.Controllers
{
    [TestClass]
    public class HomeControllerTest
    {
        [TestMethod]
        public void Index()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.Index() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }

        [TestMethod]
        public void About()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.About() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }

        [TestMethod]
        public void Contact()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.Contact() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }

        [TestMethod]
        public void Refactorings()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.Refactorings() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
        
        [TestMethod]
        public void Inspections()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.Inspections() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
        
        [TestMethod]
        public void InspectionResults()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.InspectionResults() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
        
        [TestMethod]
        public void UnitTesting()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.UnitTesting() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
        
        [TestMethod]
        public void Navigation()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.Navigation() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
        
        [TestMethod]
        public void SourceControl()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.SourceControl() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
        
        [TestMethod]
        public void Indentation()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.Indentation() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
        
        [TestMethod]
        public void News()
        {
            // Arrange
            var controller = new HomeController();

            // Act
            var result = controller.News() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
    }
}
