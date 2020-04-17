#include"mySales_item.hpp"

mySalesitem::mySalesitem(const std::string &s, int unit_sold, double revenue)
{
    this->bookNo = s;
    this->unit_sold = unit_sold;
    this->revenue = revenue;
}
mySalesitem::mySalesitem(std::istream &is)
{
    read(is, *this);
}
inline
std::string mySalesitem::isbn()const
{
    return bookNo;
}
inline
double mySalesitem::avg_price()const
{
    double ans = 0.0;
    if(unit_sold)
        ans = revenue/unit_sold;
    return ans;
}
std::istream &read(std::istream &is, mySalesitem &tmp)
{
    double price = 0.0;
    is>>tmp.bookNo>>tmp.unit_sold>>price;
    tmp.revenue = tmp.unit_sold * price;
    return is;
}
std::ostream &print(std::ostream &os, mySalesitem &tmp)
{
    os<<tmp.isbn()<<' '<<tmp.unit_sold<<' '
      <<tmp.revenue<<' '<<tmp.avg_price()<<std::endl;
    return os;
}