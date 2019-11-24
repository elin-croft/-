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
