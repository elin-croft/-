#ifndef _MY_SALES_ITEM_HPP
#define _MY_SALES_ITEM_HPP
#include<iostream>
class mySalesitem{
public:
    mySalesitem() = default;
    mySalesitem(const std::string &s):bookNo(s) {};
    mySalesitem(const std::string &s, int unit_sold, double revenue);
    mySalesitem(std::istream &is);
    friend std::istream &read(std::istream &is, mySalesitem &tmp);
    friend std::ostream &print(std::ostream &os, mySalesitem &tmp);
private:
    mutable int times = 0;
    std::string bookNo;
    int unit_sold = 0;
    double revenue = 0.0;
    std::string isbn()const;//for we are not going to change the value of bookNo
    double avg_price()const;//for we are not going to change the value of unit_sold and revenue
};
std::istream &read(std::istream &is, mySalesitem &tmp);
std::ostream &print(std::ostream &os, mySalesitem &tmp);
#endif