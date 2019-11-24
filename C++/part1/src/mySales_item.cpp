#include"mySales_item.hpp"

std::string mySalesitem::isbn()const
{
    return bookNo;
}
double mySalesitem::avg_price()const
{
    double ans = 0.0;
    if(unit_sold)
        ans = revenue/unit_sold;
    return ans;
}