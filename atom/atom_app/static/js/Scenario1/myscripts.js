var video = document.getElementById("myVideo");
var source = document.getElementById("mySource");
var btn = document.getElementById("pauseButton");
var ret = document.getElementById("returnButton")

function pauseFunction() {
    window.location = "https://programmera.ru";
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