#include<iostream>
#include<ctime>
#include<vector>
#include<mySales_item.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    mySalesitem *item;
    std::string bookno;
    double sold, price;
    item = new mySalesitem;
    read(cin, *item);
    print(cout, *item);
    return 0;
}