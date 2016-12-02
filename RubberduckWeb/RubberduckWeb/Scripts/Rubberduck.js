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
    $.ajax({
        url: "/Inspections/GetInspectionResults",
        datatype: "json",
        data: { code: $("textarea#code").val() },
        type: "POST",
        success: function (data) {
            console.log(data);
            console.log("success");
            $("div#inspection-results").html(data);
        },
        error: function (data) {
            console.log(data);
            console.log("error");
            $("div#inspection-results").html('<div class="row"><p class="rd-alert error">Rubberduck failed to either parse or resolve this code.  Please verify that it works, then report this problem at our <a href="https://github.com/rubberduck-vba/Rubberduck">GitHub repository</a> if necessary.</p></div>');
        }
    });
}