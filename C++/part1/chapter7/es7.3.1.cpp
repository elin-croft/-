#include<iostream>
#include<ctime>
#include<vector>
#include<Screen.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    windows_mrg *windows;
    windows = new windows_mrg;
    windows->screens[0].move(4, 0).set('#').display(cout);
    windows->clear(0);
    windows->screens[0].move(4, 0).set('#').display(cout);
    return 0;
}