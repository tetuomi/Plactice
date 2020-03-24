#include <vector>
#include <memory>
#include <mino.hpp>
#include <field.hpp>
#include <display.hpp>
#include "/opt/OpenSiv3D/Siv3D/include/Siv3D.hpp"
#include <random>

#define TIMEOUT 300
#define MINO_TYPES 7

void Main()
{
  std::random_device seed_gen;
  std::minstd_rand0 engine(seed_gen());
  
  std::unique_ptr<Mino> mino_ptr{std::make_unique<Mino>(MINOES[(int)engine() % MINO_TYPES])};
  Field field;

  Window::Resize(Size(400,1000));
  
  while(System::Update())
  {
    show(*mino_ptr, field);

    if (KeyLeft.down())
    {
      field.move_mino(*mino_ptr, Direction::LEFT);
    }
    if (KeyRight.down())
    {
      field.move_mino(*mino_ptr, Direction::RIGHT);
    }
    if (KeyDown.pressed())
    {    
       field.move_mino(*mino_ptr, Direction::DOWN);
    }
    if (KeyUp.down())
    {     
       if (field.accept_to_rotate(*mino_ptr, IMAGINARY)) mino_ptr->rotate_mino(IMAGINARY);
    }
    
    if (field.is_touching_mino(*mino_ptr))
    {
      field.change_mino_to_field(*mino_ptr);
      field.kill_lines(field.filled_lines_index());
      field.set_init_posi();
      mino_ptr = std::make_unique<Mino>(MINOES[(int)engine() % MINO_TYPES]);
    }
    if (field.game_over())
    {
      break;
    }
  }
}
