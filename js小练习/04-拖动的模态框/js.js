//1、获取元素
var login = document.querySelector('.login')
var mask = document.querySelector('.log-bg')
var link = document.querySelector('#link')
var closeBtn = document.querySelector('#closeBtn')
var title = document.querySelector('.login-title')
//2、点击弹出层这个链接，让mask和login显示出来
link.addEventListener('click',function(){
    login.style.display = 'block'
    mask.style.display = 'block'
})
//3、点击closeBtn，让mask和login隐藏起来
closeBtn.addEventListener('click',function(){
    login.style.display = 'none'
    mask.style.display = 'none'
})
//4、开始拖拽
//（1）当鼠标按下，就获得鼠标在盒子内的坐标
title.addEventListener('mousedown',function(e){
    var x = e.pageX - login.offsetLeft
    var y = e.pageY - login.offsetTop
    //（2）鼠标移动时，把鼠标在页面中的坐标，减去鼠标在盒子内的坐标就是模态框的Left和top值
    document.addEventListener('mousemove',move)
    function move(e){
        login.style.left = e.pageX - x + 'px'
        login.style.top = e.pageY - y + 'px'
    }
    //（3）鼠标弹起，就让鼠标移动事件移除
    document.addEventListener('mouseup',function(){
        document.removeEventListener('mousemove',move)
    })
})
