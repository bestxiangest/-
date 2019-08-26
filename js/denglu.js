var zhanghao = document.getElementById("zhanghao");
var mima = document.getElementById("mima");
var zhuce = document.getElementsByClassName("btn")[0];

zhuce.onclick = function() {
	if (zhanghao.value == (localStorage.getItem("zh"))) {
		if (mima.value == (localStorage.getItem("mm"))) {
			alert("登陆成功！");
		}
	}

}
