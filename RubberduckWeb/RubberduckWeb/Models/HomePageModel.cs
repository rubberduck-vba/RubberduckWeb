using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace RubberduckWeb.Models
{
    public class HomePageModel
    {
        public HomePageModel(FeatureHighlight[] highlights, Func<int> totalReleaseDownloads)
        {
            Highlights = highlights;
            TotalReleaseDownloads = totalReleaseDownloads();
        }

        public FeatureHighlight[] Highlights { get; }
        public int TotalReleaseDownloads { get; }
    }

    public class FeatureHighlight
    {
        public FeatureHighlight(
            string title, 
            string description, 
            string image, 
            string imageAltText, 
            string caption, 
            string actionLink)
        {
            Title = title;
            Description = description;
            ImageUrl = image;
            ImageAltText = imageAltText;
            ImageCaption = caption;
            ActionLink = actionLink;
        }

        public string Title { get; }
        public string Description { get; }
        public string ImageUrl { get; }
        public string ImageAltText { get; }
        public string ImageCaption { get; }
        public string ActionLink { get; }
    }
}