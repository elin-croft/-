#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct personinfo{
    string name;
    vector<string> phones;
};
std::istream &read(std::istream &);
int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    if(argc < 2)
    {
        std::cerr<<"you haven't input your file"<<endl;
        return -2;
    }
    std::ifstream in(argv[1],std::fstream::in);
    vector<personinfo> infos;
    string tmp;
    if(!in)
    {
        std::cerr<<"can't open "<<endl;
        return -1;
    }
    cout<<std::unitbuf;
    while(!in.eof())
    {
        personinfo tmpp;
        std::getline(in, tmp);
        std::istringstream ins(tmp);
        string numbers;
        ins>>tmpp.name;
        while(!ins.eof())
        {
            ins>>numbers;
            if(ins.fail())
                break;
            else
                tmpp.phones.push_back(numbers);
        }
        infos.push_back(tmpp);
    }
    for(auto person:infos)
    {
        cout<<person.name<<' ';
        for(auto phone:person.phones)
            cout<<phone<<' ';
        cout<<endl;
    }
    return 0;
}
std::istream &read(std::istream &is)
{
    string s;
    if(is.fail())
    {
        is.clear();
        throw std::runtime_error ("stream is already failed");
    }
    //cout<<std::unitbuf;
    while(!is.fail() && !is.eof())
    {
        is>>s;
        if(is.fail())
            throw std::runtime_error("failed stream");
        else
            cout<<s<<endl;
    }
    is.clear();
    return is;
}