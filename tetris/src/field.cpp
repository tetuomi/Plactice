#include <mino.hpp>
#include <field.hpp>


Field::Field()
  : field(HEIGHT+1, std::vector<bool>(WIDTH + 2, false))
  , posi(WIDTH / 2, 2)
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
  int mino_posi_x, mino_posi_y;
  const std::vector<std::vector<ComplexCell>> _mino{mino.get_mino()};
  for (int i = 0;i < MINO_SIZE;i++)
  {
    for (int j = 0;j < MINO_SIZE;j++)
    {
      mino_posi_x = posi.first + _mino[i][j].re;
      mino_posi_y = posi.second - _mino[i][j].im;
      if (dire == Direction::RIGHT &&_mino[i][j].is_active && field[mino_posi_y][mino_posi_x + 1])
      {
        accept = false;
      }
      else if (dire == Direction::LEFT &&_mino[i][j].is_active && field[mino_posi_y][mino_posi_x - 1])
      {
        accept = false;
      }
    }
  }
  return accept;
}

bool Field::accept_to_rotate(Mino& mino,int imaginary) const
{
  bool accept = true;
  Mino copy_mino{mino};
  copy_mino.rotate_mino(imaginary);
  const std::vector<std::vector<ComplexCell>> next_mino{copy_mino.get_mino()};
  for (int i = 0;i < MINO_SIZE;i++)
  {
    for (int j = 0;j < MINO_SIZE;j++)
    {
      if (next_mino[i][j].is_active && field[posi.second - next_mino[i][j].im][posi.first + next_mino[i][j].re])
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

std::vector<int> Field::filled_lines_index() const
{
  std::vector<int> lines;
  int count;
  for (int i = 0;i < HEIGHT;i++)
  {
    count = 0;
    for (int j = 1;j < WIDTH + 1;j++)
    {
      count += field[i][j];
    }
    if (count == WIDTH)
    {
      lines.push_back(i);
    }
  }
  return lines;
}

void Field::kill_lines(std::vector<int> lines)
{
  for (std::size_t i = 0;i < lines.size();i++)
  {
    for (std::size_t j = 1;j < WIDTH + 1;j++)
    {
      field[lines[i]][j] = false;
    }
  }
  
  for (std::size_t i = 0;i < lines.size();i++)
  {
    for (std::size_t j = lines.back();j > 0;j--)
    {
      const auto tmp{field[j]};
      field[j] = field[j - 1];
      field[j - 1] = tmp;
    }
  }
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

bool Field::game_over() const
{
  return field[2][WIDTH / 2];
}
