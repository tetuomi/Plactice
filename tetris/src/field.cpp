
#include <mino.hpp>
#include <field.hpp>


Field::Field()
  : field(HEIGHT+1, std::vector<bool>(WIDTH, false))
  , posi(WIDTH / 2, 2)
{
  for (int i = 0;i < WIDTH;i++)
  { 
    field[HEIGHT][i] = true;
  }
}

bool Field::is_touching_mino(Mino& mino) const
{
  bool is_touching = false;
  const std::vector<std::vector<ComplexCell>> _mino{mino.get_mino()};
  for (int i = 0;i < MINO_SIZE;i++)
  {
    for (int j = 0;j < MINO_SIZE;j++)
    {
      if (_mino[i][j].is_active && field[posi.second - _mino[i][j].im + 1][posi.first + _mino[i][j].re])
      {
        is_touching = true;
      }
    }
  }
  return is_touching;
}

bool Field::accept_to_move(Mino& mino, Direction dire) const
{
  bool accept = true;
  int mino_posi;
  const std::vector<std::vector<ComplexCell>> _mino{mino.get_mino()};
  for (int i = 0;i < MINO_SIZE;i++)
  {
    for (int j = 0;j < MINO_SIZE;j++)
    {
      mino_posi = posi.first + _mino[i][j].re;
      if (dire == Direction::RIGHT &&_mino[i][j].is_active && WIDTH - 1 <= mino_posi)
      {
        accept = false;
      }
      else if (dire == Direction::LEFT &&_mino[i][j].is_active && mino_posi <= 0)
      {
        accept = false;
      }
    }
  }
  return accept;
}
void Field::change_mino_to_field(Mino& mino)
{
  const std::vector<std::vector<ComplexCell>> _mino{mino.get_mino()};
  for (int i = 0;i < MINO_SIZE;i++)
  {
      for (int j = 0;j < MINO_SIZE;j++)
      {
          if (_mino[i][j].is_active)
          {
            field[posi.second - _mino[i][j].im][posi.first + _mino[i][j].re] = true;
          }
      }
  }
}

void Field::set_init_posi()
{
  posi.first = WIDTH / 2;
  posi.second = 2;
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

void Field::move_mino(Mino& mino, Direction dire)
{
  switch(dire)
  {
    case Direction::RIGHT:
      if (accept_to_move(mino, Direction::RIGHT)) posi.first++;
      break;
    case Direction::LEFT:
      if (accept_to_move(mino, Direction::LEFT)) posi.first--;
      break;
    case Direction::DOWN:
      posi.second++;
      break;
  }
}
