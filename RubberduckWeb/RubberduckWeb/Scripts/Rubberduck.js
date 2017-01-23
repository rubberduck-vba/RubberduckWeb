"use strict";

function $displayImage(path) {
    var imgPreload = new Image();
    $(imgPreload).attr({
        src: path
    });

    $("div.image-div").css("display", "block");
    $("img.image").attr("src", path);

    $("div.image-div").css("margin-left", -1 * (imgPreload.width / 2));
    $("div.image-div").css("margin-top", -1 * (imgPreload.height / 2));
};

function $hideImage() {
    $("div.image-div").css("display", "none");
};

function $loadInspections() {
    $("button#loadInspections").addClass("hidden");
    $("div#inspection-error-indicator").addClass("hidden");
    $("div#inspection-busy-indicator").removeClass("hidden");
    $.ajax({
        url: "/Inspections/GetInspectionResults",
        datatype: "json",
        data: { code: $("textarea#code").val() },
        type: "POST",
        success: function(data) {
            console.log(data);
            console.log("success");
            $("div#inspection-results").html(data);
            $("div#inspection-busy-indicator").addClass("hidden");
            $("button#loadInspections").removeClass("hidden");
        },
        error: function(data) {
            console.log(data);
            console.log("error");
            $("div#inspection-busy-indicator").addClass("hidden");
            $("div#inspection-error-indicator").removeClass("hidden");
            $("button#loadInspections").removeClass("hidden");
        }
    });
}