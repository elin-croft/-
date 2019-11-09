#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int test = 100;
    int *p1 = nullptr,*p2 = nullptr;
    void *p3 = 0;
    if(p3 == nullptr)
    {
        cout<<"true"<<endl;
    }
    if(p3 == NULL)
    {
        cout<<"true"<<endl;
    }
    int *p4;
    cout<<"test number is "<<test<<endl;
    cout<<"testing if p1 equels p3 "<<(p1 == p3)<<endl;
    p1 = &test;
    p2 = p1;
    cout<<"set p1 = p2"<<endl;
    cout<<"p1: "<<*p1<<" "<<"p2: "<<*p2<<endl;
    *p2 = 90;
    cout<<"change the vaule p2 is holding"<<endl;
    cout<<"p1: "<<*p1<<" "<<"p2: "<<*p2<<" "<<"test: "<<test<<endl;
    p3 = p2;
    cout<<"p3: "<<*(int *)p3<<endl;
    p4 = new int;
    *p4 = test;
    cout<<"p4: "<<*p4<<endl;
    *p4 = 80;
    cout<<"p4: "<<*p4<<" "<<"test: "<<*(int *)p3<<endl;
    system("pause");
    return 0;
}