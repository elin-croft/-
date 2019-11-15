#include<iostream>
#include<map>
#include"Sales_item.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    Sales_item item;
    std::map<string, int>books;
    std::map<string, int>::iterator it1;
    //you can also use this iterator
    while(cin>>item)
    {
        books[item.isbn()]++;
    }
    for(auto it = books.begin();it != books.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    system("pause");
    return 0;
}