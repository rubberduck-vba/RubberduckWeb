"use strict";

function $displayImage(path) {
    $("div.image-div").css("display", "block");
    $("img.image").attr("src", path);
};

function $hideImage() {
    $("div.image-div").css("display", "none");
};

function $loadInspections() {
    $.ajax({
        url: "/Inspections/GetInspectionResults",
        datatype: "json",
        data: { code: $("textarea#code").val() },
        type: "POST",
        success: function (data) {
            $("div#inspection-results").replaceWith(data);
        }
    });
}