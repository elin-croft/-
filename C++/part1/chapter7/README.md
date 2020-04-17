# chapter 7
前面的语句函数什么的就不做专门做练习了。今天开始系统学习class

在有了python项目的经验后重新看C++的class简单了很多。

首先是class的成员和方法这些基础，还有作用域的说明。

在下面就是对this指针的说明。我以前一直都不太理解this指针，在长时间接触python后现在再看清晰了不少  
首先C++的class其实有个大坑，this指针是隐藏变量，python中的self也是纯新人大坑，在没有this指针概念的时候会不太好理解self，但是理解起来比this简单
因为self是肉眼可见的，而且python解释器会在方法中明确指出方法中与局部变量非同名的全局变量在不加self的时候是未定义，包括调用方法时也是。

在C++中this是常量指针,是方法的隐藏参数, 伪代码如下

    yourclass *const this = &instance;
不能再class定义的范围外使用this，在代码中不能定义this，class方法的本质
    
    void class::method(class *const this, args)
    class::method(&instance, args)
第二行为调用方法时的过程，要先将实例的地址赋给this，然后执行函数。

在C++中不能像python中self.value = xxx这样动态的定义成员变量，只能一次性定义完。  
C++在方法中一般不需要给成员变量加this，因为编译器会自动加上。但是，方法中的变量和成员变量重名时是必须加this来区分
 
    assume we have an int value defined in class
    void method(int age)
    {
        this->age = age;
    }

    class test{
        public:
        int age =0;
        void set(int age)
        {
            age = age;
            cout<<this->age<<'; '<<age<<endl;
        }
    };
    output:0; value of age
在调用上面的set会有output那样的输出，就是因为set里玩来玩去都是形参age，覆盖掉了成员变量age，要用this->age才能访问到。

当方法不改变this所指的变量的值时可以在函数后加const把this指针变成一个指向常量的常量指针，下面就是const的伪代码定义

    void isbn()const

    const class *const this

## 编写io类的函数
std::istream和std::ostream  
调用流的时候必须要引用

    std::istream &read(std::istream &is, args)
    {
        ...
        return is;
    }
    std::ostream &print(std::ostream &os, args)
    {
        ...
        return os;
    }
## friend
在class中可以声明友元函数或者class，这些友元可以访问该class的私有成员
    
    class test{
        int a;
        friend void change(int a);
    }
    void change(int a)
    {
        a++;
    }
这样change函数就可以访问到a成员。

friend在类中的声明是不受位置和访问标识符限制的，可以在任意位置声明
>推荐在集中位置声明全部的friend

friend声明和函数声明是不一样的，在类内部声明友元后还需要在类外部重新声明和定义函数才可以

## 关于返回this的成员函数
this指针指的是当前对象，*this是对this的解引用也就是对象本身

返回*this可以级联操作  
    
    Test test;
    test.move().set();
这里要注意函数一定要返回引用

    Test &move();
    Test &set();
要想上面那样定义成员函数的返回类型。否则的话对成员变量的改动是在另外一个对象上面，不是原对象。

因为子函数在返回时是先将要返回的内容放到一个暂时的内存中，然后回到调用该函数的位置，返回引用的话就是直接返回该内容本身。同时要注意栈中的内容无法引用，所以传参数的话要考虑是否要引用。
