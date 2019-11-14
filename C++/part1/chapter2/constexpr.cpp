#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

constexpr int change(int i)
{
    //int i = 10;
    return i + 1;
}

int main()
{
    constexpr int i = 10;
    constexpr int j = change(i);
    cout<<j<<endl;
    int t;
    cin >> t;
    int z = change(t);
    z++;
    cout<<z<<endl;
    return 0;
}