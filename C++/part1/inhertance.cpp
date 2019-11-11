#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class shape{
public:
    virtual string getshape()=0;
    virtual int areas()=0;
    virtual void test()
    {
        cout<<"this is a override test."<<" "<<
        "for this function will not be override in subclass"<<endl;
    }
    void show()
    {
        cout<<"this is a "<< getshape() <<endl;
        cout<<"the areas is "<< areas() <<endl;
    }
};
class subshape:public shape{
public:
    subshape(int h, int w)
    {
        _h = h;
        _w = w;
    }
    string getshape()
    {
        return "square";
    }
    int areas()
    {
        if(_h == 0 || _w == 0)
            throw "input error";
        return _h * _w;
    }
    int _h = 0;
    int _w = 0;
    void unique()
    {
        cout<<"i'm not in superclass"<<endl;
    }
};

void test(void* object)
{
    if(object == NULL)
        throw "pointer is Null";
}

int main()
{
    shape *dome=NULL;
    subshape *subdome = nullptr;
    dome = new subshape(2, 3);
    try{
        test(dome);
    }
    catch(const char* msg)
    {
        cout<<msg;
        exit(1);
    }
    dome = new subshape(2, 3);
    subdome = new subshape(2,3);
    try{
        dome->areas();
    }
    catch(const char* msg){
        cout<<msg;
        exit(1);
    }
    dome->show();
    dome->test();
    cout<<"------------------------------------------"<<endl;
    subdome->show();
    subdome->test();
    subdome->unique();
    system("pause");
    delete dome;
    delete subdome;
    return 0;
}