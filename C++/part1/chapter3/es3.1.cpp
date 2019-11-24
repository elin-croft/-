#include<iostream>
#include<cstring>
#include"mySales_item.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    mySalesitem *stack[2];
    mySalesitem *books = new mySalesitem;
    mySalesitem *books1 = new mySalesitem;
    double price = 0;
    string bookNo;
    cin>>books->bookNo>>books->unit_sold>>price;
    books->revenue = books->unit_sold * price;
    cin>>books1->bookNo>>books1->unit_sold>>price;
    books1->revenue = books1->unit_sold * price;
    if(books->isbn() == books1->isbn())
        cout<<books->bookNo<<" "<<books1->unit_sold + books->unit_sold<<" "<<books->revenue + books1->revenue<<endl;
    else
        cout<<"can't"<<endl;
    stack[0] = books;
    stack[1] = books1;
    for(auto tmp:stack)
        cout<<tmp->bookNo<<endl;
    return 0;
}