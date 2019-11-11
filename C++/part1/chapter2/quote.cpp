#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a = 10;
    int &b = a;
    a = 11;
    b = 12;
    /************removed during disassembly*************/
    //cout<<"a's addr: "<<&a<<'\n'<<"b's addr: "<<&b<<endl;
    //system("pause");
    /************removed during disassembly*************/
    return 0;
}
