#include<Screen.hpp>

Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

inline
char Screen::get()
{
    return contents[cursor];
}

inline
char Screen::get(pos r, pos c)
{
    return contents[r * width + c];
}

Screen &Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}

const Screen &Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}

void Screen::do_display(std::ostream &os) const
{
    for(int i = 0; i<height; i++)
    {
        os<<contents.substr(i * width, width)<<std::endl;
    }
}
inline
Screen::pos Screen::size() const
{
    return height * width;
}

void windows_mrg::clear(index Sindex)
{
    auto &screen = screens[Sindex];
    screen.contents = std::string(screen.height * screen.width, ' ');
}