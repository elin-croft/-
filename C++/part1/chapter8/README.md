# part two chapter 8
## 关于cin和cout的关联
在C++中cin，cerr和cout是默认关联在一起的，也就是说当从cin里读数据和往cerr里写数据的时候都会刷新cout的缓冲区，这样cout缓冲区里的数据就会被立即输出。

io类提供了tie函数来设置自己本身的流和其他流的关联,tie有两个版本

    strm::tie() //takes no args
    strm::tie(std::ostream *) // takes a output stream
不带参数的会返回自己当前关联的流，没有的话输出空指针。  
带参数的会关联对应的流，输出上一个关联的流

输出缓冲区有个特性，即如果不刷新缓冲区或者未满则不向目标输出

    //linux
    auto old_stream = cin.tie(nullptr);
    while(cin>>i)
    {
        cout<<i;
    }
上面的代码已经对cin和cout进行和解绑，但还是cout还是会刷新并立即输出i值。

我的猜想是因为cin，cout流和stdio流同步的关系

因为从cin流读入数据后不会刷新cout流，但是会改动stdin流，这样就会对stdout流产生影响，由于stdout流和cout流是同步的，所以cout流也被改变了。

    std::ios::sync_with_stdio(false);
在上述代码中加入上面这句就可以关闭iostream和stdio流的同步，这样的话就可以看到在解除绑定后从cin读数据不会使cout流的缓冲区刷新。  
两类流同步应该是为了向下兼容C，在关闭同步后scanf，printf和cin，cout不能混用。

## 关于fstream 和 sstream的混合使用
可以从文件中读入一行，然后在读出这一行的单词数

g++编译

    while(!in.eof())
    {
        std::getline(in, tmp);
        std::istringstream ins(tmp);
        string numbers;
        while(!ins.eof())
        {
            ins>>numbers;
            cout<<numbers<<std::ends;
            if(ins.peek() == EOF)
                break;
        }
        cout<<endl;
    }
当文件内容大于一行时会存在除最后一行以外，其他每一行的最后一个单词会被输出两遍。

我个人的猜测是从文件里都进来的每一行如果不是最后一行的话会有隐藏换行符'\n'这样会导致读完正确的内容后还未到eof，所以不管是用peek()还是ins.eof()都无法解决读两遍的问题。  
但是'\n'无法被string正确读入会导致错误，所以要用fail来控制，而且流出现错误的话fail都会被置位，所以用fail最合适。

    while(!in.eof())
    {
        std::getline(in, tmp);
        std::istringstream ins(tmp);
        string numbers;
        while(!ins.eof())
        {
            ins>>numbers;
            if(ins.fail())
                break;
            else
                cout<<numbers<<std::ends;
        }
        cout<<endl;
    }
这里因为string试图从流中读入错误字符，fail被置位，不进行输出操作。

    while(!in.eof())
    {
        std::getline(in, tmp);
        std::istringstream ins(tmp);
        string numbers;
        while(ins>>numbers)
        {
            cout<<numbers<<std::ends;
        }
        cout<<endl;
    }
可以直接将读入作为条件，这样更加方便

但是读完后会将eof和fail会被置位导致流无法再次使用，可以通过clear函数将其清除。

     in.clear(in.rdstate() & ~in.failbit);
     in.seekg(std::ios::beg);
然后通过seekg将指针移回开头即可将eof复位，然后重新读文件。