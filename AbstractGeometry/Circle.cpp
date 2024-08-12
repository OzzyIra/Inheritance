#include"Circle.h"

Geometry::Circle::Circle(double rad, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
{
    set_rad(rad);
}
double Geometry::Circle:: get_rad()const
{
    return rad;
}
void  Geometry::Circle::set_rad(double rad)
{
    this->rad = filter_size(rad);
}
Geometry::Circle::~Circle() {}
double  Geometry::Circle::get_diameter()const
{
    return 2 * rad;
}
double  Geometry::Circle::get_area()const 
{
    return ((rad * rad) * M_PI);
}
double  Geometry::Circle::get_perimeter()const
{
    return M_PI * get_diameter();;
}
void  Geometry::Circle::draw()const 
{

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    HPEN hPen = CreatePen(PS_SOLID, 5, get_color());

    HBRUSH hBrush = CreateSolidBrush(get_color());

    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);

    ::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

    DeleteObject(hPen);
    DeleteObject(hBrush);

    ReleaseDC(hwnd, hdc);
}
void  Geometry::Circle::info()const
{
    cout << typeid(*this).name() << endl;
    cout << "Радиус " << get_rad() << endl;
    Shape::info();
}