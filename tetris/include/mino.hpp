#ifndef MINO_HPP
#define MINO_HPP

#include <vector>

#define MINO_SIZE 3
#define IMAGINARY -1

struct ComplexCell
{
  int re;
  int im;
  const bool is_active;
  
  ComplexCell(int _re, int _im, bool _is_active);
};

class Mino
{
private:
  std::vector<std::vector<ComplexCell>> mino;
  
public:
  Mino();
  Mino(std::vector<std::vector<ComplexCell>>&& mino);
  void rotate_mino(int imaginary);
  std::vector<std::vector<ComplexCell>> get_mino() const;
};

static Mino I{{
  {ComplexCell(-1,1,false), ComplexCell(0,1,true), ComplexCell(1,1,false)},
  {ComplexCell(-1,0,false), ComplexCell(0,0,true), ComplexCell(1,0,false)},
  {ComplexCell(-1,-1,false), ComplexCell(0,-1,true), ComplexCell(1,-1,false)}
}};

static Mino O{{
  {ComplexCell(-1,1,false), ComplexCell(0,1,true), ComplexCell(1,1,true)},
  {ComplexCell(-1,0,false), ComplexCell(0,0,true), ComplexCell(1,0,true)},
  {ComplexCell(-1,-1,false), ComplexCell(0,-1,false), ComplexCell(1,-1,false)}
}};

static Mino S{{
  {ComplexCell(-1,1,false), ComplexCell(0,1,true), ComplexCell(1,1,true)},
  {ComplexCell(-1,0,true), ComplexCell(0,0,true), ComplexCell(1,0,false)},
  {ComplexCell(-1,-1,false), ComplexCell(0,-1,false), ComplexCell(1,-1,false)}
}};

static Mino Z{{
  {ComplexCell(-1,1,true), ComplexCell(0,1,true), ComplexCell(1,1,false)},
  {ComplexCell(-1,0,false), ComplexCell(0,0,true), ComplexCell(1,0,true)},
  {ComplexCell(-1,-1,false), ComplexCell(0,-1,false), ComplexCell(1,-1,false)}
}};

static Mino J{{
  {ComplexCell(-1,1,true), ComplexCell(0,1,false), ComplexCell(1,1,false)},
  {ComplexCell(-1,0,true), ComplexCell(0,0,true), ComplexCell(1,0,true)},
  {ComplexCell(-1,-1,false), ComplexCell(0,-1,false), ComplexCell(1,-1,false)}
}};

static Mino L{{
  {ComplexCell(-1,1,false), ComplexCell(0,1,false), ComplexCell(1,1,true)},
  {ComplexCell(-1,0,true), ComplexCell(0,0,true), ComplexCell(1,0,true)},
  {ComplexCell(-1,-1,false), ComplexCell(0,-1,false), ComplexCell(1,-1,false)}
}};

static Mino T{{
  {ComplexCell(-1,1,false), ComplexCell(0,1,true), ComplexCell(1,1,false)},
  {ComplexCell(-1,0,true), ComplexCell(0,0,true), ComplexCell(1,0,true)},
  {ComplexCell(-1,-1,false), ComplexCell(0,-1,false), ComplexCell(1,-1,false)}
}};

#endif
