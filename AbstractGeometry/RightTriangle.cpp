#include"RightTriangle.h"

Geometry::RightTriangle::RightTriangle(double leg1, double leg2, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
{
    set_leg1(leg1);
    set_leg2(leg2);
}

double Geometry::RightTriangle::get_leg1()const
{
    return leg1;
}
void Geometry::RightTriangle::set_leg1(double leg1)
{
    this->leg1 = filter_size(leg1);
}
double Geometry::RightTriangle::get_leg2()const
{
    return leg2;
}
void Geometry::RightTriangle::set_leg2(double leg2)
{
    this->leg2 = filter_size(leg2);
}
double Geometry::RightTriangle::get_height()const 
{
    return (leg1 * leg2) / get_hypotenuse();
}
double Geometry::RightTriangle::get_area()const 
{
    return (leg1 * leg2) / 2;
}
double Geometry::RightTriangle::get_hypotenuse()const
{
    return sqrt(leg1 * leg1 + leg2 * leg2);
}
double Geometry::RightTriangle::get_perimeter()const 
{
    return  get_hypotenuse() + leg1 + leg2;
}
void Geometry::RightTriangle::draw()const 
{
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    HPEN hPen = CreatePen(PS_SOLID, line_width, color);
    HBRUSH hBrush = CreateSolidBrush(color);

    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);

    POINT apt[] =
    {
        {start_x, start_y + leg2},
        {start_x + leg1, start_y + leg2},
        {start_x + leg1, start_y + leg2 - leg2}
    };

    ::Polygon(hdc, apt, 3);

    DeleteObject(hBrush);
    DeleteObject(hPen);

    ReleaseDC(hwnd, hdc);
}
Geometry::RightTriangle::~RightTriangle() {};
void Geometry::RightTriangle::info()const 
{
    cout << typeid(*this).name() << endl;
    cout << "Длина катета1:\t" << leg1 << endl;
    cout << "Длина катета2:\t" << leg2 << endl;
    Triangle::info();
}