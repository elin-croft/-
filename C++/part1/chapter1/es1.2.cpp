#include<iostream>
#include"Sales_item.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    int v1, v2;
    cout<<"hello world"<<endl;
    cin>>v1>>v2;
    cout<<"the sum of "<<v1
            <<" and "<<v2<<" is "<<v1+v2<<endl;
    cout<<"the multiplication of "<<v1
            <<" and "<<v2<<" is "<<v1*v2<<endl;
    cout<<"and of course the program in ex1.6 is illegal"<<'\n'<<
                "to correct it you need to erase the ';' after v1 and v2 "<<endl;
    return 0;
}