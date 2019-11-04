#include<iostream>
#include"Sales_item.hpp"

int main()
{
    int v1, v2;
    std::cout<<"hello world"<<std::endl;
    std::cin>>v1>>v2;
    std::cout<<"the sum of "<<v1
            <<" and "<<v2<<" is "<<v1+v2<<std::endl;
    std::cout<<"the multiplication of "<<v1
            <<" and "<<v2<<" is "<<v1*v2<<std::endl;
    std::cout<<"and of course the program in ex1.6 is illegal"<<'\n'<<
                "to correct it you need to erase the ';' after v1 and v2 "<<std::endl;
    return 0;
}