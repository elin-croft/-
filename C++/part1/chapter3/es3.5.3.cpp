#include <iostream>
#include <string>
#include<vector>

#define getsize(array, type) sizeof(array)/sizeof(type) 

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int a[9] = {1},b[9]={1};
    int flag = 0;
    a[8] = 2;
    b[8] = 9;
    int *p1 = a, *p2 = b;
    if(getsize(a, int) != getsize(b, int))
        flag = 1;
    vector<int>av(std::begin(a), std::end(a));
    int *ca=nullptr;
    while(p1 != std::end(a) && p2 != std::end(b) && flag != 1)
    {
        if(*p1 != *p2)
            flag = 1;
        p1++;
        p2++;
    }
    for(auto tmp = av.begin(); tmp != av.end(); tmp++)
        cout<<*tmp<<" ";
    ca = new int[av.size()];
    for(int i = 0; i < getsize(a, int); i++)
    {
        *(ca + i) = b[i];
    }
    cout<<endl;
    for(auto tmp = ca; tmp != ca + 9; tmp++)
        cout<<*tmp<<" ";
    if(flag == 1)
        cout<<"array a and array b is not the same"<<endl;
    else
        cout<<"two arrays are the same"<<endl;
    delete [] ca;
    return 0;
}