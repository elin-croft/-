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