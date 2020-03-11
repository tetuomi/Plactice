#include <display.hpp>
#include <mino.hpp>
#include <field.hpp>
#include <ncurses.h>
#include <vector>


Display::Display()
  : win{newwin(HEIGHT+1,WIDTH,0,0)}
{
}

void Display::show(const Mino& mino, const Field& field)
{
  const std::vector<std::vector<bool>> _field{field.get_field()};
  const int _x{field.get_x()}, _y{field.get_y()};
  const std::vector<std::vector<ComplexCell>> _mino{mino.get_mino()};
  wclear(win.get());
  for (int i = 0;i < HEIGHT + 1;i++)
  {
    for (int j = 1;j < WIDTH + 1;j++)
    {
      if (_field[i][j])
      {
        mvwaddch(win.get(), i, j, 'O');
      }
    }
  }

  for (int i = 0;i < MINO_SIZE;i++)
  {
    for (int j = 0;j < MINO_SIZE;j++)
    {
      if (_mino[i][j].is_active)
      {
        mvwaddch(win.get(), _y - _mino[i][j].im, _x + _mino[i][j].re, 'O');
      }
    }
  }
  box(win.get(), ACS_VLINE, ACS_HLINE);
  wrefresh(win.get());
}
