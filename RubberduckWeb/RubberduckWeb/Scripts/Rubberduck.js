"use strict";

function $displayImage(path) {
    $("div.image-div").css("display", "block");
    $("img.image").attr("src", path);
    
    var image = $("img.image");
    var width = image.innerWidth();
    var height = image.innerHeight();

    $("div.image-div").css("margin-left", -1 * (width / 2));
    $("div.image-div").css("margin-top", -1 * (height / 2));
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
            $("div#inspection-results").html(data);
        },
        error: function () {
            $("div#inspection-results").html('<p class="error">Rubberduck failed to either parse or resolve this code.  Please verify that it works, then report this problem at our <a href="https://github.com/rubberduck-vba/Rubberduck">GitHub repository</a> if necessary.</p>');
        }
    });
}