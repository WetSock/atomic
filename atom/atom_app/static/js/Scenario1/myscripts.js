var video = document.getElementById("myVideo");
var source = document.getElementById("mySource");
var btn = document.getElementById("pauseButton");
var ret = document.getElementById("returnButton");
var isClosedNav = true;

function pauseFunction() {
    window.location = "https://programmera.ru";
}

function myFunction1() {
    source.setAttribute('src', 'reactor.mp4');
    video.load();
    video.play();
}


function myFunction2() {
    source.setAttribute('src', 'Парогенератор.mp4');
    video.load();
    video.play();
}

function openNav() {
    if (isClosedNav) {
        document.getElementById("mySidenav").style.width = "30%";
        isClosedNav = false;
    } else {
        document.getElementById("mySidenav").style.width = "0";
        isClosedNav = true;
    }
}

function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
}