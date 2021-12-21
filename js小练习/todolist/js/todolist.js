$(function() {
    load()
    // 1、按下回车，将input的value存入localStorage
    $("#title").on("keydown",function(e) {
        if(e.keyCode === 13){
            //获取内存
            var local = getData()
            //添加内存
            local.push({title:$(this).val(), done:false})
            saveData(local)
            //渲染
            load()
            $(this).val("")
        }
    })

    //2、删除
    $("ol,ul").on("click","a",function() {
        //获取内存
        var local = getData()
        //删除对应的对象
        var index = $(this).attr("id")
        local.splice(index, 1)
        //保存到本地内存
        saveData(local)
        //渲染
        load()

    })

    //3、选中复选框
    $("ol,ul").on("click","input",function(){
        //获取内存
        var local = getData()
        //根据是否选中更改对象的done值
        var index = $(this).siblings("a").attr("id")
        local[index].done = $(this).prop("checked")
        //保存到本地内存
        saveData(local)
        load()
    })

    function getData() {
        var data = localStorage.getItem("todolist")
        if(data !== null){
            return JSON.parse(data)
        }else{
            return []
        }
    }

    function saveData(data) {
        localStorage.setItem("todolist",JSON.stringify(data))
    }

    function load() {
        //渲染之前先清空ol
        $("ol").empty()
        $("ul").empty()
        var todoCount = 0
        var doneCount = 0
        //读取本地内存
        var data = getData()
        $.each(data,function(i,e) {
            if(e.done){
                $("ul").prepend("<li><input type='checkbox' checked=''checked><p>"+e.title+"</p><a href='javascript:;' id="+ i +"></a> </li>")
                doneCount++
            }else{
                $("ol").prepend("<li><input type='checkbox'><p>"+e.title+"</p><a href='javascript:;' id="+ i +"></a> </li>")
                todoCount++
            }
        })
        $("#todocount").text(todoCount)
        $("#donecount").text(doneCount)
    }
})