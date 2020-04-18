#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<mySales_item.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    if(argc < 3)
    {
        std::cerr<<"you haven't input your file"<<endl;
        return -2;
    }
    std::ifstream in(argv[1], std::fstream::in);
    std::ofstream out(argv[2], std::fstream::out | std::fstream::app);
    if(!in)
    {
        std::cerr<<"can't open " + string(argv[1])<<endl;
        return -1;
    }
    mySalesitem *item;
    item = new mySalesitem;
    read(in, *item);
    print(out, *item);
    in.close();
    out.close();
    return 0;
}