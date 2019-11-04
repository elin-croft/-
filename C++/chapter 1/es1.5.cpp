#include<iostream>
#include"Sales_item.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Sales_item item1, item2;
    cout<<"input your isbn"<<endl;
    while(cin>>item1>>item2)
    {
        cout<<item1.isbn()<<endl;//you can't access bookNo, beacuse it's in private section.
        cout<<item2.isbn()<<endl;
        if(compareIsbn(item1, item2))
        {
            cout<<item1+item2<<endl;
        }
        else
        {
            cout<<"can't add these two up"<<'\n'<<
            "check and make sure isbn of these two is the same"<<endl;
            break;
        }
        
    }
    return 0;
}