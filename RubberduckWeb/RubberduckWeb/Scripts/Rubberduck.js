var $displayImage = function (path) {
    $("div.image-div").css("display", "block");
    $("img.image").attr("src", path);
};

var $hideImage = function () {
    $("div.image-div").css("display", "none");
};