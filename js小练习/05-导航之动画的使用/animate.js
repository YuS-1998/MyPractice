function animate(obj,target,callback){//callback为回调函数，等函数执行完执行
    clearInterval(obj.timer)
    obj.timer = setInterval(function(){
        var len = (target - obj.offsetLeft) / 10//缓动动画，即移动速度随着移动减小
        len = len > 0 ? Math.ceil(len) : Math.floor(len)
        if(obj.offsetLeft == target){
            clearInterval(obj.timer)
            if(callback){
                callback();
            }
        }
        obj.style.left = obj.offsetLeft + len + 'px'
    },15)
}