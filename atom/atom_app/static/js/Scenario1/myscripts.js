var video = document.getElementById("myVideo");
var source = document.getElementById("mySource");
var btn = document.getElementById("pauseButton");

function pauseFunction() {
    if (video.paused) {
        video.play();
        btn.src="pause1.png";
    } else {
        video.pause();
        btn.src="play1.png";
    }
}

function myFunction1() {
    source.setAttribute('src', 'Производство корпуса реактора.mp4');
    video.load();
    video.play();
}


function myFunction2() {
    source.setAttribute('src', 'Парогенератор.mp4');
    video.load();
    video.play();
}

function openNav() {
    document.getElementById("mySidenav").style.width = "250px";
  }
  
function closeNav() {
document.getElementById("mySidenav").style.width = "0";
}