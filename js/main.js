var youce = document.getElementsByClassName("youce")[0];
var yc = document.getElementsByClassName("yc");
var baidu = document.getElementById("baidu");
var bilibili = document.getElementById("bilibili");
var wode = document.getElementById("wode");
var QQ = document.getElementById("QQ");
var control = document.getElementsByClassName("control")[0];
var container = document.getElementsByClassName("container")[0];
var yx = document.getElementsByClassName("yx");
//var gb = document.getElementsByClassName("gb")[0];
//var gg = document.getElementById("gg");
var friends = document.getElementById("friends");
var zhuye = document.getElementById("zhuye");
var banji = document.getElementById("banji");
var xiangce = document.getElementById("xiangce");
var biji = document.getElementById("biji");
var youxi = document.getElementById("youxi");
var zuozhe = document.getElementsByClassName("zuozhe")[0];
var a = document.getElementsByClassName("kongzhi");
var tx = document.getElementsByClassName("tx")[0];
var text = document.getElementsByClassName("text")[0];
var xm = document.getElementById("xm");
var h1 = document.getElementsByClassName("h1")[0];
var bj = document.getElementsByClassName("bj");
var pictures = document.getElementsByClassName("xiangce")[0];
var picture = document.getElementById("picture");
var bottompicture = document.getElementById("bottompicture");
var panding = 1;
//判断班级显示位置1正常位置 2底部
var panding2 = 1;
//判断控制栏是否在顶端1在 2不在

/**gb.onclick = function() {
 gg.style.display = "none";
 }*/
function click() {
	if (event.button == 2) {
		alert('本网站欢迎您 !!');
	}
}

document.onmousedown = click;

zhuye.onclick = function() {
	document.getElementsByClassName("dl")[0].style.top = "-500px";
	document.getElementsByClassName("dl")[0].style.transition = "top 1s";
	game.style.top = "-300px";
	game.style.transition = "top 1s";
	bottompicture.style.display = "block";
	panding = 1;
	panding2 = 2;
	for (var i = 0; i < bj.length; i++) {
		bj[i].style.display = "none";
	}
	zuozhe.style.display = "none";
	pictures.style.display = "none";
	h1.className = "h1";
	h1.innerHTML = "Welcome！";
	h1.style.display = "block";
	container.style.display = "none";
	h1.style.margin = "400px auto";
	control.style.width = "877px";
	control.style.height = "80px";
	control.style.position = "fixed";
	control.style.left = "200px";
	control.style.top = "0px";

	for (var i = 0; i < a.length; i++) {
		a[i].style.display = "inline";
		a[i].style.margin = "0px 43px";
	}
	h1.style.transition = "margin 1s";
	control.style.transition = "position 1s";
	control.style.transition = "margin  1s";

}

friends.onclick = function() {
	document.getElementsByClassName("dl")[0].style.top = "-500px";
	document.getElementsByClassName("dl")[0].style.transition = "top 1s";
	game.style.top = "-400px";
	game.style.transition = "top 1s";
	bottompicture.style.display = "block";
	pictures.style.display = "none";
	panding2 = 2;
	panding = 2;
	for (var i = 0; i < bj.length; i++) {
		bj[i].style.display = "none";
	}
	zuozhe.style.margin = "40000px auto";
	h1.style.display = "block";
	h1.className = "time";
	container.style.display = "block";
	h1.style.margin = "0px auto";
	control.style.width = "150px";
	control.style.height = "650px";
	control.style.marginLeft = "300px";
	control.style.marginTop = "30px";
	control.style.left = "25px";
	control.style.top = "50px";
	for (var i = 0; i < a.length; i++) {
		a[i].style.display = "block";
		a[i].style.margin = "25px 0px";
	}
}

banji.onclick = function() {
	document.getElementsByClassName("dl")[0].style.top = "-500px";
	document.getElementsByClassName("dl")[0].style.transition = "top 1s";
	game.style.top = "-400px";
	game.style.transition = "top 1s";
	bottompicture.style.display = "block";
	pictures.style.display = "none";
	for (var i = 0; i < bj.length; i++) {
		bj[i].style.display = "none";
	}
	zuozhe.style.display = "block";
	h1.style.margin = "-100px auto";
	h1.style.transition = "margin 1s";
	if (panding == 1) {
		zuozhe.style.margin = "400px auto";
	}
	if (panding == 2) {
		zuozhe.style.margin = "0px auto";
		//panding = 1;
	}
}

xiangce.onclick = function() {
	document.getElementsByClassName("dl")[0].style.top = "-500px";
	document.getElementsByClassName("dl")[0].style.transition = "top 1s";
	game.style.top = "-400px";
	game.style.transition = "top 1s";
	bottompicture.style.display = "none";
	container.style.display = "none";
	panding2 = 2;
	panding = 1;
	zuozhe.style.display = "none";
	for (var i = 0; i < bj.length; i++) {
		bj[i].style.display = "none";
	}
	h1.style.display = "block";
	h1.className = "time";
	h1.style.margin = "0px auto";
	control.style.width = "150px";
	control.style.height = "650px";
	control.style.marginLeft = "300px";
	control.style.marginTop = "30px";
	control.style.left = "25px";
	control.style.top = "50px";
	for (var i = 0; i < a.length; i++) {
		a[i].style.display = "block";
		a[i].style.margin = "25px 0px";
	}
	pictures.style.display = "block"
}
/*
 * pictures.style.display = "none";
 * zuozhe.style.display = "none";
 * h1.style.display = "block";
 * h1.className = "time";
 container.style.display = "none";
 * for (var i = 0; i < bj.length; i++) {
 bj[i].style.display = "none";
 }
 * bottompicture.style.display = "block";
 *
 *
 *
 * */
biji.onclick = function() {
	document.getElementsByClassName("dl")[0].style.top = "-500px";
	document.getElementsByClassName("dl")[0].style.transition = "top 1s";
	game.style.top = "-400px";
	game.style.transition = "top 1s";
	bottompicture.style.display = "block";
	pictures.style.display = "none";
	for (var i = 0; i < bj.length; i++) {
		bj[i].style.display = "block";
		bj[i].style.margin = "100px auto";
	}
	container.style.display = "none";
	panding2 = 2;
	panding = 1;
	zuozhe.style.display = "none";
	h1.style.display = "block";
	h1.className = "time";
	h1.style.margin = "0px auto";
	control.style.width = "150px";
	control.style.height = "650px";
	control.style.marginLeft = "300px";
	control.style.marginTop = "30px";
	control.style.left = "25px";
	control.style.top = "50px";
	for (var i = 0; i < a.length; i++) {
		a[i].style.display = "block";
		a[i].style.margin = "25px 0px";
	}
}
var game = document.getElementById("game");
var yx_wang = document.getElementById("yx_wang");
var yx_fei = document.getElementById("yx_fei");

youxi.onclick = function() {
	document.getElementsByClassName("dl")[0].style.top = "-500px";
	document.getElementsByClassName("dl")[0].style.transition = "top 1s";
	control.style.width = "150px";
	control.style.height = "650px";
	control.style.marginLeft = "300px";
	control.style.marginTop = "30px";
	control.style.left = "25px";
	control.style.top = "50px";
	for (var i = 0; i < a.length; i++) {
		a[i].style.display = "block";
		a[i].style.margin = "25px 0px";
	}
	pictures.style.display = "none";
	zuozhe.style.display = "none";
	h1.style.display = "block";
	h1.className = "time";
	h1.style.margin = "0px auto";
	container.style.display = "none";
	for (var i = 0; i < bj.length; i++) {
		bj[i].style.display = "none";
	}
	bottompicture.style.display = "block";
	game.style.display = "block";

	game.style.top = "300px";
	game.style.transition = "top 1s";
}

window.onload = function() {
	zuozhe.style.display = "none";
	container.style.display = "none";
	h1.style.margin = "400px auto";
	control.style.width = "877px";
	control.style.height = "80px";
	control.style.position = "fixed";
	control.style.left = "200px";
	control.style.top = "0px";

	for (var i = 0; i < a.length; i++) {
		a[i].style.display = "inline";
		a[i].style.margin = "0px 43px";
	}
	h1.style.transition = "margin 1s";
	control.style.transition = "position 1s";
	control.style.transition = "margin  1s";
	zuozhe.style.display = "none";
}
/**************************************/

baidu.onclick = function() {
	window.open('https://www.baidu.com');
}

bilibili.onclick = function() {
	window.open('https://www.bilibili.com/')
}

wode.onclick = function() {
	window.open('https://www.zhihu.com/');
}

QQ.onclick = function() {
	window.open('tencent://message/?Site=baidu.com&uin=1816054322&Menu=yes')
}
youce.onmouseover = function() {
	for (var i = 0; i < yc.length; i++) {
		yc[i].style.color = "white";
	}
}
var dl = document.getElementById("dl");
dl.onclick = function() {
	document.getElementsByClassName("dl")[0].style.top = "200px";
	document.getElementsByClassName("dl")[0].style.transition = "top 1s";
	h1.style.display = "block";
	h1.className = "time";
	h1.style.margin = "0px auto";
	control.style.width = "150px";
	control.style.height = "650px";
	control.style.marginLeft = "300px";
	control.style.marginTop = "30px";
	control.style.left = "25px";
	control.style.top = "50px";
	for (var i = 0; i < a.length; i++) {
		a[i].style.display = "block";
		a[i].style.margin = "25px 0px";
	}
}
youce.onmouseout = function() {
	for (var i = 0; i < yc.length; i++) {
		yc[i].style.color = "pink";
	}
}
picture.onmouseover = function() {
	picture.style.height = "532px";
	picture.style.background = "url(images/7.jpg) no-repeat 100% 100%";
	picture.style.left = "700px";
	picture.style.transition = "all 1s";
	setTimeout(function() {
		picture.style.height = "300px";
		picture.style.background = "pink";
		picture.style.left = "-450px";
		picture.style.transition = "all 1s";
	}, 2000)
}
bottompicture.onmouseover = function() {
	bottompicture.style.bottom = "125px"
	bottompicture.style.background = "url(images/9.jpg)";
	setTimeout(function() {
		bottompicture.style.background = "pink";
		bottompicture.style.bottom = "-648px";
		bottompicture.style.transition = "all 1s";
	}, 2000)
}
/**************************************/
setInterval(function() {

	//时间变化

	var today = new Date()
	var h = today.getHours()
	var m = today.getMinutes()
	var s = today.getSeconds()
	// add a zero in front of numbers<10
	m = checkTime(m)
	s = checkTime(s)
	document.getElementsByClassName('time')[0].innerHTML = h + ":" + m + ":" + s
	function checkTime(i) {
		if (i < 10) {
			i = "0" + i
		}
		return i
	}

}, 10)

//title变化
var f = 0;
var title = document.getElementById("title");
setInterval(function() {
	f++;
	switch(f) {
		case 1:
			title.innerHTML = "!@#$%^&*";
			break;
		case 2:
			title.innerHTML = "@#$%^&*!";
			break;
		case 3:
			title.innerHTML = "#$%^&*!@";
			break;
		case 4:
			title.innerHTML = "$%^&*!@#";
			break;
		case 5:
			title.innerHTML = "%^&*!@#$";
			break;
		case 6:
			title.innerHTML = "^&*!@#$%";
			break;
		case 7:
			title.innerHTML = "&*!@#$%^";
			break;
		case 8:
			title.innerHTML = "*!@#$%^&";
			break;
	}
	if (f >= 8) {
		f = 1;
	}
}, 250)