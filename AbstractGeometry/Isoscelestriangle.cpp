#include"Isoscelestriangle.h"

Geometry::Isoscelestriangle::Isoscelestriangle(double side, double base_side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
{
    set_side(side);
    set_base_side(base_side);
}

double Geometry::Isoscelestriangle::get_base_side()const
{
    return base_side;
}
void Geometry::Isoscelestriangle::set_base_side(double base_side)
{
    this->base_side = filter_size(base_side);
}
double Geometry::Isoscelestriangle::get_side()const
{
    return side;
}
void Geometry::Isoscelestriangle::set_side(double side)
{
    this->side = filter_size(side);
}
double Geometry::Isoscelestriangle::get_height()const 
{
    return sqrt(side * side - base_side / 2 * base_side / 2);
}
double Geometry::Isoscelestriangle::get_area()const 
{
    return base_side / 2 * get_height();
}
double Geometry::Isoscelestriangle::get_perimeter()const 
{
    return base_side + side * 2;
}
void Geometry::Isoscelestriangle::draw()const 
{
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    HPEN hPen = CreatePen(PS_SOLID, line_width, color);
    HBRUSH hBrush = CreateSolidBrush(color);

    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);

    POINT apt[] =
    {
        {start_x, start_y + side},
        {start_x + side, start_y + base_side},
        {start_x + base_side / 2, start_y + side - get_height()}
    };

    ::Polygon(hdc, apt, 3);

    DeleteObject(hBrush);
    DeleteObject(hPen);

    ReleaseDC(hwnd, hdc);
}

Geometry::Isoscelestriangle::~Isoscelestriangle() {}
void Geometry::Isoscelestriangle::info()const 
{
    cout << typeid(*this).name() << endl;
    cout << "Длина стороны:\t" << side << endl;
    cout << "Длина основания:\t" << base_side << endl;
    Shape::info();
}