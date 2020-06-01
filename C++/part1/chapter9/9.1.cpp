#include<iostream>
#include<fstream>
#include<list>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int agrc, char *agrv[])
{
    std::list<int> list(10,1);
    for(auto item:list)
        cout<<item<<endl;
    return 0;
}