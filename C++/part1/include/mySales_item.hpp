#ifndef _MY_SALES_ITEM_HPP
#define _MY_SALES_ITEM_HPP
#include<iostream>
//do not use using in header
//using std::string;
class mySalesitem{
public:
    std::string bookNo;
    int unit_sold = 0;
    double revenue = 0.0;
    std::string isbn()const;//for we are not going to change the value of bookNo
    double avg_price()const;//for we are not going to change the value of unit_sold and revenue
};
std::istream &read(std::istream &is, mySalesitem &tmp);
std::ostream &print(std::ostream &os, mySalesitem &tmp);
#endif