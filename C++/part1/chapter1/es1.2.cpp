#include<iostream>
//#include"Sales_item.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
class test{
public:
    int a = 10;
    test &set()
    {
        cout<<"non const"<<endl;
        return *this;
    }
    const test& set() const
    {
        cout<<"const"<<endl;
        return *this;
    }
};
const int& cte(int &a)
{
    return a;
}
int main()
{
    int a =10;
    const int &b = a;
    cout<<++a<<' '<<b<<endl;
    return 0;
}