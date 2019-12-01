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
    vector<string> text{"hello",", ", "world"};
    int a[] = {1,2,3};
    int *b = a;
    cout<<"b in mem: "<<b<<" b+1 in mem: "<<b+1<<endl;
    cout<<"a in mem: "<<a<<" a+1 in mem: "<<a+1<<endl;
    for(auto it = text.begin();it != text.end() && *it != " "; it++)
    {
        string temp = *it;
        for(auto its = temp.begin();its != temp.end();its++)
        {
            if(!isspace(*its) && !ispunct(*its))
                *its = toupper(*its);
        }
        *it = temp;
        cout<<*it<<endl;
    }
    
    return 0;
}