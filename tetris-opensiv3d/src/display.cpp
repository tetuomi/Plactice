#include <display.hpp>
#include <vector>

#define MAG 40

void show(const Mino& mino, const Field& field)
{
  const std::vector<std::vector<bool>> _field{field.get_field()};
  const int _x{field.get_x()}, _y{field.get_y()};
  const std::vector<std::vector<ComplexCell>> _mino{mino.get_mino()};
  const std::pair<int, int> fallen_mino_posi{field.predict_fallen_mino(mino)};

  const Rect rect(10, 10, WIDTH * MAG , HEIGHT * MAG);
  rect.drawFrame(0, 10, Palette::Green);
  
  for (int i = 0;i < HEIGHT;i++)
  {
    for (int j = 1;j < WIDTH + 1;j++)
    {
      if (_field[i][j])
      {
        Rect(MAG * j - 30, MAG * i + 10, MAG - 2, MAG -2 ).draw(Palette::Orange);
      }
    }
  }

  for (int i = 0;i < MINO_SIZE;i++)
  {
    for (int j = 0;j < MINO_SIZE;j++)
    {
      if (_mino[i][j].is_active)
      {
        Rect(MAG * (fallen_mino_posi.first + _mino[i][j].re) - 30,
             MAG * (fallen_mino_posi.second - _mino[i][j].im - 1) + 10,
             MAG, MAG).drawFrame(5, 0, Palette::Red);
      }
    }
  }
  
  for (int i = 0;i < MINO_SIZE;i++)
  {
    for (int j = 0;j < MINO_SIZE;j++)
    {
      if (_mino[i][j].is_active)
      {
        Rect(MAG * (_x + _mino[i][j].re) - 30,
             MAG * (_y - _mino[i][j].im) + 10,
             MAG, MAG).draw(Palette::Blue);
      }
    }
  }
}

