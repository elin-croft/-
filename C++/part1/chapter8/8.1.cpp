#include<iostream>
#include<fstream>
#include<ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
std::istream &read(std::istream &);
int main(int argc, char *argv[])
{
    int ival;
    try
    {
        read(cin);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
std::istream &read(std::istream &is)
{
    int val;
    if(is.fail())
    {
        is.clear();
        throw std::runtime_error ("stream is already failed");
    }
    //cout<<std::unitbuf;
    while(!is.fail() && !is.eof())
    {
        //is>>val;
        if(is.fail())
            throw std::runtime_error("failed stream");
        else
            cout<<"1";
        auto t1 = clock();
        cout<<"t1 is "<<t1;
        while((clock() - t1)< (CLOCKS_PER_SEC/1000 * 34));
        //cout<<std::flush;
    }
    is.clear();
    return is;
}