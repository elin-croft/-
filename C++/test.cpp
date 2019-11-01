#include<iostream>

int main()
{
    int val=0,ans=0;
    while(std::cin>>val)
    {
        ans += val;
    }
    std::cout<<ans<<std::endl;
    system("pause");
    return 0;
}