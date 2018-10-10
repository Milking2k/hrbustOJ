<?php
header("Content-Type: text/html;charset=utf-8");
$usr = array('admin' => 123456);

$name = $_POST["name"];
$pwd = $_POST["pwd"];
if(is_null($name) || strlen($name) ==0 ){
    echo "<script LANGUAGE='Javascript'> location.href='index.html'; alert('请输入用户名！');</script>";
}else if(is_null($pwd)||strlen($pwd) == 0){
    echo "<script LANGUAGE='Javascript'> location.href='index.html'; alert('请输入密码！');</script>";
}else{
    if($usr[$name]==$pwd){
        echo "<div>登录成功！</div>";
    }
    else{
        echo "<script LANGUAGE='Javascript'> location.href='index.html'; alert('密码错误');</script>";
    }
}
?>