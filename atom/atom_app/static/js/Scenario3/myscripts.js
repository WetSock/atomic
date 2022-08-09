var video = document.getElementById("myVideo");
var source = document.getElementById("mySource");

setVideoFile()

function getVideoName() {
    const queryString = window.location.search;
    const urlParams = new URLSearchParams(queryString);
    const file = urlParams.get('file')
    console.log(file);
    return file
}

function setVideoFile() {
    var videoFile = getVideoName()
    source.setAttribute('src', "media/" + videoFile);
    video.load();
    video.play();
}
