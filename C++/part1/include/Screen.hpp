#ifndef _SCREEN_HPP
#define _SCREEN_HPP
#include<iostream>
#include<vector>

class Screen{
    friend class windows_mrg;
public:
    using pos = std::string::size_type;
    Screen()=default;
    Screen(pos h, pos w):height(h), width(w), contents(h*w, ' ') {};
    Screen(pos h, pos w, char c):height(h), width(w), contents(h*w, c) {};
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os);
    const Screen &display(std::ostream &os)const;
    pos size() const;
    char get();
    char get(pos, pos);
private:
    pos height = 0;
    pos width = 0;
    pos cursor = 0;
    std::string contents;
    void do_display(std::ostream &os)const;
};

class windows_mrg{
public:
    using index = std::vector<Screen>::size_type;
    void clear(index);
    std::vector<Screen> screens {Screen(6, 5, 'X')};
};
#endif