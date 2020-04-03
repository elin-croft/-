# 运行结果
## es3.2.2
前面简单的从流里读一行和读单词懒得写了

用getline的话会读空格，从流里直接读的话遇到空格自动判定输入结束
## 关于vector
关于vector之前有些误解以为就是构建数组甚至搞混了new和vector

vector就是维度不限的向量也被叫容器，可以存放规定的类型的数据

    vector<type> name1;
    vector<type> name2(n);
上面的第一句生成一个空的type类的容器，第二句是生成一个初始长度为n的容器。

要在name1中放数据的话可以用insert函数进行任意位置插入插入,或者push_back。

    insert(name.end(),...)可以达到相同的效果
string的很多成员函数和vector的成员函数功能是大致一样的,同样可以用name[]的形式和at来访问数据

对于迭代器来说份常量迭代器和pt迭代器常量就是只能读不能写

    const_iterator
同时在C++11种引入了cbegin和cend两个函数还方便auto确定类型

    vector<int> test1;
    const vector<int> test2;
    auto v1 = tes1.begin();//iterator
    auto v2 = test2.begin();//const_iterator
## 关于类的vector见vector.cpp
注意*和.的结合优先级，一定要以下面其中一个方式访问

    (*it).method
    it->method
对于第二个我个人是理解的是一个class的指针数组，通过it移动来访问每个class和class指针性质一样

## 数组与指针
数组与指针是基本类似的东西，但是，数组在逻辑空间中是连续的，而指针是离散的

在编译器编译时数组会被换成指针

### 数组的声明与定义
    int a[3] = {1,2,3};
    int a[] = {1,2,3};
第一种定义是可以不初始化的，但第二种必须要初始化。同样可以用auto进行定义

    auto b = a;
    auto b(a);
在推断时会被推断为指针，并同时将a的第一个元素赋给b

在C++11中添加了begin和end两个std中的函数，功能和容器里的同名函数基本一致

由于实质基本一样，所以可以用指针指向数组在执行运算时，会根据指针的类型进行相应大小的运算如下

    int a[] = {1,2,3};
    int *b = a;
    cout<<"b in mem: "<<b<<" b+1 in mem: "<<b+1<<endl;
    cout<<"a in mem: "<<a<<" a+1 in mem: "<<a+1<<endl;

    b in mem: 0x7fffedf778a4 b+1 in mem: 0x7fffedf778a8
    a in mem: 0x7fffedf778a4 a+1 in mem: 0x7fffedf778a8
也可以用*和[]来解地址

    *b
    b[0] //*(b + 0)
两个都可以解析出b指向的整数的值其中  
指针间的运算也和容器的相似，同样两个指针必须要指向一个数组

有时候用指针来遍历数组还是挺好用，在不需要获知数组长度的前提下可用指针来遍历

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