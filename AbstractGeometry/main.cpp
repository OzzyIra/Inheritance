#include"Shape.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Square.h"
#include"Triangle.h"
#include"EquilateralTriangle.h"
#include"Isoscelestriangle.h"
#include"RightTriangle.h"


void main()
{ 
    setlocale(LC_ALL, "Russian");
    Geometry::Square square(30, 200, 100, 5, Geometry::Color::YELLOW);    square.info();
   Geometry:: Rectangle rect(100, 80, 300, 50, 3, Geometry::Color::BLUE);
   rect.info();
   Geometry::Circle circle(20,400,30,3, Geometry::Color::GREEN);
   circle.info();
   Geometry::EquilateralTriangle e_triangle(5, 200,200, 5, Geometry::Color::GREEN);
   e_triangle.info();
   Geometry::Isoscelestriangle i_triangle(10, 12, 150, 250, 5, Geometry::Color::BLUE);
   i_triangle.info();
   Geometry::RightTriangle r_triangle(12, 15, 150, 250, 5, Geometry::Color::BLUE);
   r_triangle.info();
   cout << "Количество фигур: " << e_triangle.get_count() << endl;
   cout << "Количество фигур: " << Geometry::Shape::get_count() << endl;
}