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

