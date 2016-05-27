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
            $("div#inspection-results").html(data);
        },
        error: function (data) {
            //$("div#inspection-results").html('<p class="error">Rubberduck failed to either parse or resolve this code.  Please verify that it works, then report this problem at our <a href="https://github.com/rubberduck-vba/Rubberduck">GitHub repository</a> if necessary.</p>');
            $("div#inspection-results").html(data.responseText);
        }
    });
}