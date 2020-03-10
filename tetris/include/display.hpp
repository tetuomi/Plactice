#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <memory>
#include <ncurses.h>
#include <mino.hpp>
#include <field.hpp>


class Mino;
class Field;

struct WindowPtrDeleter
{
  void operator()(WINDOW* ptr)
  {
    delwin(ptr);
  }
};

class Display
{
private:
  std::unique_ptr<WINDOW, WindowPtrDeleter> win;
public:
  Display();
  void show(const Mino& mino, const Field& field);
};

#endif
