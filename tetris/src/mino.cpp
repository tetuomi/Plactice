#include <mino.hpp>
#include <memory>

ComplexCell::ComplexCell(int _re, int _im, bool _is_active)
  : re{_re}
  , im{_im}
  , is_active{_is_active}
{
}

Mino::Mino()
  : mino{}
{
}

Mino::Mino(std::vector<std::vector<ComplexCell>>&& mino)
  : mino{std::move(mino)}
{
}

void Mino::rotate_mino(int imaginay)
{
  static int tmp;
  for (int i = 0;i < MINO_SIZE;i++)
  {
    for (int j = 0;j < MINO_SIZE;j++)
    {
      tmp = mino[i][j].re;
      mino[i][j].re = imaginay * mino[i][j].im;
      mino[i][j].im = -imaginay * tmp;
    }
  }
}

std::vector<std::vector<ComplexCell>> Mino::get_mino() const
{
  return mino;
}
