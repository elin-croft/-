#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) a = i;
    i++;
    cout<<a;
    decltype((i)) b = i;
    decltype(*p) c = i;
    return 0;
}