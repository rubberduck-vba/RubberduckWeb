using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace RubberduckWeb.Models
{
    public class ReleaseDownloadInfo
    {
        public bool IsPreRelease { get; set; }
        public string TagName { get; set; }
        public DateTime ReleaseDate { get; set; }
        public int Downloads { get; set; }
        public string InspectionDocsUrl { get; set; }
    }

    public class HomePageModel
    {
        public HomePageModel(FeatureHighlight[] highlights, 
            ReleaseDownloadInfo totalReleaseDownloads, 
            ReleaseDownloadInfo latestReleaseDownloads,
            ReleaseDownloadInfo totalPreReleaseDownloads,
            ReleaseDownloadInfo latestPreReleaseDownloads)
        {
            Highlights = highlights;
            TotalReleaseDownloads = totalReleaseDownloads;
            LatestReleaseDownloads = latestReleaseDownloads;
            TotalPreReleaseDownloads = totalPreReleaseDownloads;
            LatestPreReleaseDownloads = latestPreReleaseDownloads;
        }

        public FeatureHighlight[] Highlights { get; }
        public ReleaseDownloadInfo TotalReleaseDownloads { get; }
        public ReleaseDownloadInfo LatestReleaseDownloads { get; }
        public ReleaseDownloadInfo TotalPreReleaseDownloads { get; }
        public ReleaseDownloadInfo LatestPreReleaseDownloads { get; }
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