#include <mino.hpp>
#include <field.hpp>


Field::Field()
  : field(HEIGHT+1, std::vector<bool>(WIDTH+2, false))
  , posi(2, 2)
{
  for (int i = 0;i < HEIGHT + 1;i++)
  {
    for (int j = 0;j < WIDTH + 2;j++)
    {
      if (i == HEIGHT || j == 0 || j == WIDTH + 1)
      {
        field[i][j] = true;
      }
    }
  }
  field[2][HEIGHT - 1] = true;
  field[2][HEIGHT] = true;
}

bool Field::is_touching_mino(Mino& mino)
{
  return true;
}

int Field::how_many_lines_filled()
{
  return 0;
}

void Field::kill_lines(int lines)
{
}

std::vector<std::vector<bool>> Field::get_field() const
{
  return field;
}
std::pair<int, int>::first_type Field::get_x() const
{
  return posi.first;
}
std::pair<int, int>::second_type Field::get_y() const
{
  return posi.second;
}

void Field::move_mino(Direction dire)
{
  switch(dire)
  {
    case Direction::RIGHT:
      posi.first++;
      break;
    case Direction::LEFT:
      posi.first--;
      break;
    case Direction::DOWN:
      posi.second++;
      break;
      
  }
}
