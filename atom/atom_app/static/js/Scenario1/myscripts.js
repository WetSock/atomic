var video = document.getElementById("myVideo");
var source = document.getElementById("mySource");
var btn = document.getElementById("pauseButton");

function pauseFunction() {
    if (video.paused) {
        video.play();
        btn.src="file:/home/amadeo/Atomic/atomic/atom/atom_app/static/js/Scenario1/pause1.png";
    } else {
        video.pause();
        btn.src="file:/home/amadeo/Atomic/atomic/atom/atom_app/static/js/Scenario1/play1.png";
    }
}

function openNav() {
    document.getElementById("mySidenav").style.width = "250px";
  }
  
function closeNav() {
document.getElementById("mySidenav").style.width = "0";
}