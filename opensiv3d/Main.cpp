# include <Siv3D.hpp>

void Main()
{
    Array<Vec2> points;

    while (System::Update())
    {
        if (MouseL.down())
        {
            // 配列に要素を追加
            points << Cursor::Pos();
        }
        if (points.size() > 0)
        {
          Circle(points.back(), 10).draw();
        }
    }
        
}
