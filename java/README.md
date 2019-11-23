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

inheritance执行结果

    don't know
    eat meat
    well sleep like a dog
    -----------------------------
    don't know
    eat meat
    well sleep like a dog
    hi guys, i'm not in any superclass
    walk like a dog
    like a wolf
java中特有的abstract关键字可以生命一个类为抽象类，不可被实例化，只能被继承，当一个类中的某个方法被abstract关键字修饰后整个类被默认为抽象类，必须用abstract修饰。

抽象方法必须全部被实现。
## java中的class
java中的calss全部都继承一个Object类

    class b extends Obaject()
但这个是默认继承，不用写。

java中的Object类可以单向指任意的类

    Object obj = new Object();
    Dog dog = new Dog();
    obj = dog;
类似C++里的void指针
## java中的类多继承
由于多继承可能会出现Deadly Diamond of Death问题,所以java中不能多继承

![image](https://github.com/elin-croft/study-record/blob/master/image/DDD.png)

java提出了interface关键字，类似class但是里面的所有方法都abstract修饰的，即必须在子类中实现。在继承是用implements关键字

    public interface pet{
        ...
    }
    
    public dog extends canine implements pet{
        ...
    }
