#include <iostream>
#include <string>
#include<vector>
#include<list>
#include<mySales_item.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<mySalesitem> sales_item(2);
    vector<string> str = {"a","an","the"};
    vector<string> str1(5,"abc");
    vector<int> num={1,2,3};
    int tmp;
    vector<int> num_test(3);
    string test = "hello world";
    str.insert(str.end(),test);
    cout<<str.at(0)<<endl;
    cout<<*(str.end()-1)<<endl;
    sales_item.at(0).bookNo = "asdf";
    for(auto itv = sales_item.begin();itv != sales_item.end(); itv++)
    {
        cout<<(*itv).bookNo<<endl;
    }
    //while(cin>>tmp)
    //    num.push_back(tmp);
    for(auto itv = num.begin();itv != num.end(); itv++)
    {
        cout<<*itv<<endl;
    }
    num_test.insert(num_test.end(), 5);
    for(auto itv = num_test.begin();itv != num_test.end(); itv++)
    {
        cout<<*itv<<endl;
    }
    cout<<num[1]<<endl;
    cout<<num.at(0)<<endl;
    return 0;
}