#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using num = int;
using numptr = int*;

int main()
{
    num a[3]={1,2,3};
    for(int i :a)
        cout<<i<<'\t';
    cout<<endl;
    numptr b = a;
    for(num i = 0; i < 3; i++,b++)
        cout<<*b<<'\t';
    cout<<endl;
    return 0;
}