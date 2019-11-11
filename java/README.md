# 运行记录
## String_test的运行结果
    str1 and str2 true
    str1 and str2 in memory
    str1 1421795058
    str2 1421795058
    str1 and str3 false
    content in str1 and str3 true
    str3 and str4 false
    str3 and str4 in memory
    str1 1555009629
    str2 41359092
## java的继承
整体来说java的继承和C++基本一样，用extends关键字来继承  

但是，java的属性一共分了4种private, defult, public, protect. 不支持多继承而且在继承时不能写继承属性。

    class Base{
        ...
    }
    class Dri extends Base{
        ...
    }
基类中的每个函数都可以被重写且在基类中不用添加virtual关键字

java中的类在继承时可以像C++一样给基类new一个子类

    Base base;
    base = new dri();
表现出来的结果也和C++中的一致  
不了解C++的见此解释  
总体还说是基类，会将在子类中被重写的函数的指针指向被重写的位置，子类中独有的函数无法访问(毕竟不是自己的嘛)
