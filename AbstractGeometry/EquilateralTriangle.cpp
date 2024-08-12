#include"EquilateralTriangle.h"

Geometry::EquilateralTriangle::EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
{
    set_side(side);
}
Geometry::EquilateralTriangle::~EquilateralTriangle() {}

double Geometry::EquilateralTriangle::get_side()const
{
    return side;
}
void Geometry::EquilateralTriangle::set_side(double side)
{
    this->side = filter_size(side);
}
double Geometry::EquilateralTriangle::get_height()const 
{
    return sqrt(side * side - side / 2 * side / 2);
}
double Geometry::EquilateralTriangle::get_area()const 
{
    return side / 2 * get_height();
}
double Geometry::EquilateralTriangle::get_perimeter()const 
{
    return side * 3;
}
void Geometry::EquilateralTriangle::draw()const 
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
        {start_x + side, start_y + side},
        {start_x + side / 2, start_y + side - get_height()}
    };

    ::Polygon(hdc, apt, 3);

    DeleteObject(hBrush);
    DeleteObject(hPen);

    ReleaseDC(hwnd, hdc);
}

void Geometry::EquilateralTriangle::info()const 
{
    cout << typeid(*this).name() << endl;
    cout << "Длина стороны:\t" << side << endl;
    Shape::info();
}