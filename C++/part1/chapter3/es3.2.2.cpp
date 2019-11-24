#include <iostream>
#include <string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str1 > str2)
        cout << str1 << " is biger" << endl;
    else
        cout << str2 << " is biger" << endl;
    if (str1.length() > str2.length())
        cout << str1 << " is longer" << endl;
    else
        cout << str2 << " is longer" << endl;
    cout<<str1[0]<<endl;
    for (auto &c : str1) //actually auto c equits to char c
        c = 'X';
    cout << str1 << endl;
    //use for
    auto it = str1.begin();
    int i = 0;
    while (it != str1.end())
    {
        *it = i + 48;
        it++, i++;
    }
    cout << str1 << endl;
    for (it = str2.begin(); it != str2.end(); it++)
        if (ispunct(*it))
        {
            str2.erase(it);
            it--;
        }
        else
        {
            *it = 'X';
        }

    cout << str2 << endl;
    return 0;
}