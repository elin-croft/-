#ifndef _MY_SALES_ITEM_HPP
#define _MY_SALES_ITEM_HPP
#include<iostream>
using std::string;
class mySalesitem{
public:
    string bookNo;
    int unit_sold = 0;
    double revenue = 0.0;
    string isbn()const;
    double avg_price()const;
};
#endif