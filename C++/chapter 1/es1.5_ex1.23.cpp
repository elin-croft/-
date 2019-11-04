#include<iostream>
#include<map>
#include"Sales_item.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Sales_item item;
    std::map<std::string, int>books;
    while(cin>>item)
    {
        books[item.isbn()]++;
    }
    for(auto it = books.begin();it != books.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    system("pause");
    return 0;
}