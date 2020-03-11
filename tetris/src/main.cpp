#include <vector>
#include <memory>
#include <mino.hpp>
#include <field.hpp>
#include <display.hpp>
#include <ncurses.h>
#include <thread>
#include <chrono>

#define TIMEOUT 200

int main()
{
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, FALSE);
  timeout(TIMEOUT); //キー入力待ち時間(ms)
  noecho();
  curs_set(0);
  refresh();
  
  std::unique_ptr<Mino> mino_ptr{std::make_unique<Mino>(I)};
  Field field;
  Display display;
  
  while(true)
  {
    display.show(*mino_ptr, field);
    std::thread fall_mino
    {
      [&]{
        std::this_thread::sleep_for(std::chrono::milliseconds(TIMEOUT));
        field.move_mino(*mino_ptr, Direction::DOWN);
      }
    };

    if (field.is_touching_mino(*mino_ptr))
    {
      field.change_mino_to_field(*mino_ptr);
      field.kill_lines(field.filled_lines_index());
      field.set_init_posi();
      mino_ptr = std::make_unique<Mino>(I);
    }

    const auto key{getch()};
    switch(key)
    {
      case KEY_LEFT:
        field.move_mino(*mino_ptr, Direction::LEFT);
        break;
      case KEY_RIGHT:
        field.move_mino(*mino_ptr, Direction::RIGHT);
        break;
      case KEY_DOWN:
        mino_ptr->rotate_mino(-IMAGINARY);
        break;
      case KEY_UP:
        mino_ptr->rotate_mino(IMAGINARY);
        break;
    }
    fall_mino.join();
    flushinp();
  }
  endwin();
}
