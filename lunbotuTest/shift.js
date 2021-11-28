var imgs = document.querySelectorAll('ul > li')
var points = document.querySelectorAll('ol > li')
var banner = document.querySelector('.banner')

//准备一个变量，表示当前是第几张，默认是0，因为默认显示的是索引第0张
var index = 0

//书写一个切换一张的函数
/* 约定：参数为true，我们切换下一张；
参数为false，我们切换上一张；
参数为数字，我们切换到指定索引的那一张 */
function changeOne(type){
    //1、让当前这一张消失
    imgs[index].className = ''
    points[index].className = ''
    //2、根据type传递进来的参数，来切换index的值
    if(type == true){
        index++
    }else if(type == false){
        index--
    }else{
        index = type
    }
    //判定一下index的边界值
    if(index >= imgs.length){
        index = 0
    }
    if(index < 0){
        index = imgs.length-1
    }
    //3、让改变后的这一张显示出来
    imgs[index].className = 'active'
    points[index].className = 'active'
}

//给轮播图区域盒子绑定点击事件
banner.onclick = function(e){
    //判断点击的是左按钮
    if(e.target.className == 'left'){
        changeOne(false)
    }
    //判断点击的是右按钮
    if(e.target.className == 'right'){
        changeOne(true)
    }            
    //判断点击的是焦点盒子
    if(e.target.dataset.name == 'point'){
        var i = e.target.dataset.i
        changeOne(i)
    }
}

//自动切换功能
setInterval(function(){
    changeOne(true)
},5000)