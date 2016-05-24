"use strict";

function $displayImage(path) {
    $("div.image-div").css("display", "block");
    $("img.image").attr("src", path);
};

function $hideImage() {
    $("div.image-div").css("display", "none");
};