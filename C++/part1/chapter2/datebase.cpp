#include<iostream>
#include"mysql.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    MYSQL *mysql;
    int res;
    const char host[] = "localhost";
    const char user[] = "root";
    const char pswd[] = "root";
    const char table[] = "test";
    const char db[] = "mydb";
    unsigned int port = 3306;
    mysql_init(mysql);
    if(mysql_real_connect(mysql, host, user, "4869",db, port, NULL, 0))
        cout<<"OK"<<endl;
    else
        cout<<"Can't"<<endl;
    return 0;
}