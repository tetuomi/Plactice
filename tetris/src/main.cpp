#include <vector>
#include <memory>
#include <mino.hpp>
#include <field.hpp>
#include <display.hpp>
#include <ncurses.h>

int main()
{
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, FALSE);
  noecho();
  curs_set(0);
  
  std::unique_ptr<Mino> mino_ptr{std::make_unique<Mino>(I)};
  Field field;
  Display display;

  while(true)
  {
    display.show(*mino_ptr, field);
    flushinp();
    const auto key{getch()};
    switch(key)
    {
      case KEY_LEFT:
        field.move_mino(Direction::LEFT);
        break;
      case KEY_RIGHT:
        field.move_mino(Direction::RIGHT);
        break;
      case KEY_DOWN:
        field.move_mino(Direction::DOWN);
        break;
      case KEY_UP:
        mino_ptr->rotate_mino(IMAGINARY);
        break;
    }
  }
  endwin();
}
