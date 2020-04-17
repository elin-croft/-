#include<iostream>
#include<ctime>
#include<vector>
#include<mySales_item.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
std::istream &read(std::istream &is ,int &data)
{
    is>>data;
    return is;
}
int main()
{
    mySalesitem *item1, *item2, *item3, *item4;
    std::string bookno;
    double sold, price;
    item1 = new mySalesitem();
    read(cin, *item1);
    return 0;
}