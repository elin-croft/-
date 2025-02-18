#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void test(void *pointer)
{
    if(pointer == NULL)
        throw "pointer is Null";  
}
class Game{
private:
    string translate(int x);
    char detranslate(string x);
    string wins = "<01><12><20>";
    string condition;
    int win=0, g_tie=0,lost=0;
public:
    Game()
    {
        condition = "<**>";
    }
    ~Game()
    {
        cout<<"you win "<<win<<" times"<<'\n'
            <<"you tie "<<g_tie<<" times"<<'\n'
            <<"you lost "<<lost<<" times"<<endl;
    }
    void guess(string input);
};
int main()
{
    srand(time(NULL));
    Game *play;
    string input;
    play = new Game;
    try{
        test(play);
    }
    catch(const char* msg)
    {
        cout<<msg;
        exit(1);
    }
    cout<<"input your choose or input bye to finish"<<endl;
    while(cin>>input){
        if (input == "bye")
            break;
        play->guess(input);
    }
    delete play;
    //system("pause");

    return 0;
}
string Game::translate(int x)
{
    string ans;
    if (x == 0)
        ans = "rock";
    else if (x == 1)
        ans = "scissors";
    else
        ans = "paper";
    return ans;
}
char Game::detranslate(string x)
{
    char ans;
    if (x == "rock")
        ans = '0';
    else if (x == "scissors")
         ans = '1';
    else if (x == "paper")
        ans = '2';
    else{
        throw std::runtime_error("input error, it should be rock, paper or scissors");
    }
    return ans;   
}
void Game::guess(string input)
{
    int c = rand() % 3;
    string record;
    int tie =0;
    tie = c-tie;
    try{
        condition.at(1)= detranslate(input);
        tie = detranslate(input)-48 -tie;
        condition.at(2)=c+48;
        record = input + " vs " + translate(c);
        cout<<record<<endl;
        size_t pos = wins.find(condition);
        if (pos != string::npos){
            cout << "you won" << endl;
            win++;
        }
        else if (tie != 0){
            cout << "you lost" << endl;
            lost++;
        }
        else{
            cout << "tie" << endl;
            g_tie++;
        }
    }
    catch(const std::runtime_error& e){
        std::cerr << e.what() << '\n';
    }
}
