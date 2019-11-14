# 运行结果
## es2.1
    32
    4294967264
    32
    -32
    0
    0
    4294967264
第一个没有问题，第二个是因为无符号在想减后要按照无符号输出故输出为4294967264

最后我加了一个 unsigned - int 由于隐式转换规则故转为unsigned

https://zh.cppreference.com/w/c/language/conversion

上链接为各种转换规则
## es2.3.2

    test number is 100
    testing if p1 equels p3 1
    set p1 = p2
    p1: 100 p2: 100
    change the vaule p2 is holding
    p1: 90 p2: 90 test: 90
    p3: 90
    p4: 90
    p4: 80 test: 90
引用必须要在声明的时候必须初始化

其实引用就是一个变量换个名字，建立了引用的两个变量在内存中是同一个地址
这是quote.cpp反汇编的结果

    0x00401410 <+0>:     push   ebp
    0x00401411 <+1>:     mov    ebp,esp
    0x00401413 <+3>:     and    esp,0xfffffff0
    0x00401416 <+6>:     sub    esp,0x10
    0x00401419 <+9>:     call   0x4019d0 <__main>

    int a = 10;
    0x0040141e <+14>:    mov    DWORD PTR [esp+0x8],0xa

    int &b = a;
    0x00401426 <+22>:    lea    eax,[esp+0x8]
    0x0040142a <+26>:    mov    DWORD PTR [esp+0xc],eax

    a = 11;
    0x0040142e <+30>:    mov    DWORD PTR [esp+0x8],0xb

    b = 12;
    0x00401436 <+38>:    mov    eax,DWORD PTR [esp+0xc]
    0x0040143a <+42>:    mov    DWORD PTR [eax],0xc

    return 0;
    0x00401440 <+48>:    mov    eax,0x0

    0x00401445 <+53>:   leave
    0x00401446 <+54>:    ret

下面针对关键语句进行解释

    int a = 10;
    0x0040141e <+14>:    mov    DWORD PTR [esp+0x8],0xa
可以看出a的“标签”放在esp寄存器，在对应的esp地址中存放着a在内存中的地址，通过mov指令将0xa，即10放入esp+0x8里存的内存地址中。

    int &b = a;
    0x00401426 <+22>:    lea    eax,[esp+0x8]
    0x0040142a <+26>:    mov    DWORD PTR [esp+0xc],eax
b和a基本同理，但是有一步lea操作。这个lea将esp+0x8里存的内存地址放入eax中，然后将eax里的值通过mov放入b在寄存器中的“标签”。

所以b保存的其实是a的内存地址。

    a = 11;
    0x0040142e <+30>:    mov    DWORD PTR [esp+0x8],0xb

    b = 12;
    0x00401436 <+38>:    mov    eax,DWORD PTR [esp+0xc]
    0x0040143a <+42>:    mov    DWORD PTR [eax],0xc
改a的值的时候直接改，改b的地址时就麻烦了点。

先将b的寄存器中对应的内存地址取出，即a的内存地址，然后放入eax。  
第二步就要将0xc放入eax中存放的内存地址中，即a的内存地址。

下面是AT&T格式的汇编。。。  
反正我是看不懂，我们学的是intel的((( ；ﾟДﾟ)))

    0x00401410 <+0>:     push   %ebp
    0x00401411 <+1>:     mov    %esp,%ebp
    0x00401413 <+3>:     and    $0xfffffff0,%esp
    0x00401416 <+6>:     sub    $0x10,%esp
    0x00401419 <+9>:     call   0x4019d0 <__main>

    int a = 10;
    0x0040141e <+14>:    movl   $0xa,0x8(%esp)

    int &b = a;
    0x00401426 <+22>:    lea    0x8(%esp),%eax
    0x0040142a <+26>:    mov    %eax,0xc(%esp)

    a = 11;
    0x0040142e <+30>:    movl   $0xb,0x8(%esp)

    b = 12;
    0x00401436 <+38>:    mov    0xc(%esp),%eax
    0x0040143a <+42>:    movl   $0xc,(%eax)

    return 0;
    0x00401440 <+48>:    mov    $0x0,%eax

    0x00401445 <+53>:   leave
    0x00401446 <+54>:    ret
用gdb查看反汇编的时候要在编译时加上-g参数

    g++ -g -o
gdb中默认的是AT&T格式，通过命令可改为intel格式

    set disassembly-flavor intel
下面这条命令查看main函数的汇编代码

    disas /m main

void 类的指针是可以指向任何指针的，但是不能反向。而且void指针不能被方位，不能自加操作(GNU规则中可以)

在若要将void指针赋给其他类型的指针可以用强制转换

    void *ptr = 0;
    void *ptr = NULL;
    void *ptr = nullptr;
这三个语句基本效果一样的，都是把指针初始化为空指针。
## constexpr
这是C++11种的新规则

    constexpr int i = 10;
在定义常量表达式的时候必须在声明的同时定义，而且这个变量必须是常量。  
可以用constexpr来修饰函数

    constexpr int change()
    {
        int i = 10;
        return i + 1;
    }
可以用普通的int还接受返回值，也可以用constexpr修饰的int来接受返回值
改变change函数

    constexpr int change(int i)
    {
        //int i = 10;
        return i + 1;
    }
    main中
    constexpr int i = 10;
    constexpr int a = change(i);
    cin>>t;
    int z = change(t);
    constexpr int b = change(t);//这句是不合法的
constexpr修饰的函数返回值可以被普通的int和const修饰的int接受

**因为传值不同会得出不同的返回值，所以不能被constexpr接受**  
这些都是我现在的理解，具体详细的内容在书的后面会讲，等着以后自己打脸(;¬_¬)
## 关于constexpr指针

    constexpr int *p = &p;
    constexpr int *const p1 = &j;
这里的p,j都要定义为全局变量，因为在函数内的局部变量在每次运行前都会被放在随机的位置，所以p无法指向局部变量
必须指向全局变量