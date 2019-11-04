#include<iostream>
#include"Sales_item.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Sales_item item, total;
    int flag=0;
    cin>>item;
    total = item;
    cout<<total<<endl;
    while(cin>>item)
    {
        if(item.isbn() == total.isbn())
        {
            total += item;
            cout<<total<<endl;
        }
        else
        {
            cout<<"you input a different book"<<endl;
            break;
        }
        
    }
    return 0;
}