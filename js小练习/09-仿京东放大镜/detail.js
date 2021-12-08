window.addEventListener('load',function(){//等页面都加载完了再执行js操作
    var previewImg = document.querySelector('.preview-img')
    var mask = document.querySelector('.mask')
    var big = document.querySelector('.big')
    //1、当鼠标经过preview-img时，就显示和隐藏mask遮挡层和big大盒子
    previewImg.addEventListener('mouseover',function(){
        mask.style.display = 'block'
        big.style.display = 'block'
    })
    previewImg.addEventListener('mouseout',function(){
        mask.style.display = 'none'
        big.style.display = 'none'
    })
    //2、鼠标移动时，让黄色的盒子跟着鼠标来走
    previewImg.addEventListener('mousemove',function(e){
        //（1）先计算出鼠标在盒子内的坐标
        var x = e.pageX - this.offsetLeft//这里this指的是添加事件的元素
        var y = e.pageY - this.offsetTop
        //（2）减去盒子高度300的一半是150，就是我们mask的最终left和top值了
        //（3）限定盒子移动范围
        var maskX = x - mask.offsetWidth / 2
        var maskY = y - mask.offsetHeight / 2
        var maskMax = previewImg.offsetWidth - mask.offsetWidth
        maskX = maskX <= 0 ? 0 : maskX
        maskX = maskX >= maskMax ? maskMax : maskX
        maskY = maskY <= 0 ? 0 : maskY
        maskY = maskY >= maskMax ? maskMax : maskY//因为是正方形，所以高度和宽度的最大移动距离是一样的
        mask.style.left = maskX +'px'
        mask.style.top = maskY +'px'
        //3、大图片的移动距离 = 遮挡层移动距离*大图片最大移动距离/遮挡层的最大移动距离
        var bigImg = document.querySelector('.bigImg')
        var bigMax = bigImg.offsetWidth - big.offsetWidth//大图片的最大移动距离
        var bigX = maskX * bigMax / maskMax
        var bigY = maskY * bigMax / maskMax
        bigImg.style.left = -bigX + 'px'
        bigImg.style.top = -bigY + 'px'
    })
})