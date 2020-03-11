#ifndef FIELD_HPP
#define FIELD_HPP

#include <mino.hpp>
#include <vector>

#define HEIGHT 30
#define WIDTH 10

class Mino;

enum class Direction : int
{
  RIGHT, LEFT, DOWN
};

class Field
{
private:
  std::vector<std::vector<bool>> field;
  std::pair<int, int> posi;
  
public:
  Field();
  bool is_touching_mino(Mino& mino) const;
  bool accept_to_move(Mino& mino, Direction dire) const;
  void change_mino_to_field(Mino& mino);
  void set_init_posi();
  int how_many_lines_filled();
  void kill_lines(int lines);
  std::vector<std::vector<bool>> get_field() const;
  std::pair<int, int>::first_type get_x() const;
  std::pair<int, int>::second_type get_y() const;
  void move_mino(Mino& mino, Direction dire);
};

#endif
