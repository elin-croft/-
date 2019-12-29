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
    int a[9] = {0},b[9]={0};
    int flag = 0;
    for(int i = 0; i < 9; i++)
    {
        cin>>a[i];
        cin>>b[i];
        cout<<endl<<i<<endl;
    }
    int *p1 = a, *p2 = b;
    if(getsize(a, int) != getsize(b, int))
        flag = 1;
    while(p1 != std::end(a) && p2 != std::end(b) && flag != 1)
    {
        if(*p1 != *p2)
            flag = 1;
        p1++;
        p2++;
    }
    if(flag == 1)
        cout<<"array a and array b is not the same"<<endl;
    else
        cout<<"two arrays are the same"<<endl;
    return 0;
}