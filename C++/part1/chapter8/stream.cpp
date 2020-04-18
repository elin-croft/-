#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<mySales_item.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    std::ifstream in("phonebook.txt");
    string tmp;
    while(!in.eof())
    {
        std::getline(in, tmp);
        cout<<tmp<<endl;
        if(in.peek() == EOF)
            break;
    }
    cout<<"--------------------------"<<endl;
    cout<<in.fail()<<endl;
    cout<<in.eof()<<endl;
    cout<<in.bad()<<endl;
    in.clear(in.rdstate() & ~in.failbit);
    cout<<"--------------------------"<<endl;
    cout<<in.fail()<<endl;
    cout<<in.eof()<<endl;
    cout<<in.bad()<<endl;
    in.seekg(std::ios::beg);
    cout<<"--------------------------"<<endl;
    cout<<in.fail()<<endl;
    cout<<in.eof()<<endl;
    cout<<in.bad()<<endl;
    while(!in.eof())
    {
        std::getline(in, tmp);
        cout<<tmp<<endl;
    }
    in.close();
    return 0;
}