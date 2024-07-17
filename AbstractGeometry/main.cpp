#include <iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
    enum Color
    {
        RED = 0x000000FF,
        GREEN = 0x0000FF00,
        BLUE = 0x00FF0000,
        YELLOW =  0x0000FFFF,
        CONSOLEBLUE = 0x09,
        LIGHT_GREEN = 0xAA,
        CONSOLE_RED = 0xCC,
        CONSOLE_DEFAULT = 0x07,
        /*RGB_RED = RGB(255, 0, 0),
        RGB_GREEN = RGB(0,255,0),
        RGB_BLUE = RGB(0,0,255)*/
    };
#define SHAPE_TAKE_PARAMETERS unsigned start_x,unsigned int start_y,unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x,start_y,line_width,color
    class Shape
    {
    protected:
        Color color;
        unsigned int start_x;
        unsigned int start_y;
        unsigned int line_width;

    public:
        Shape(SHAPE_TAKE_PARAMETERS) :color(color)
        {
            set_start_x(start_x);
            set_start_y(start_y);
            set_line_width(line_width);
        }
        virtual ~Shape() {}
        virtual double get_area()const = 0;
        virtual double get_perimeter()const = 0;
        virtual void draw()const = 0;
        Color get_color()const
        {
            return color;
        }
        void  set_color(Color color)
        {
            this->color = color;
        }
        unsigned int get_start_x()const
        {
            return start_x;
        }
        unsigned int get_start_y()const
        {
            return start_y;
        }
        unsigned int get_line_width()const
        {
            return line_width;
        }
        void set_start_x(unsigned int start_x)
        {
            this->start_x = start_x;
        }
         void set_start_y(unsigned int start_y)
        {
            this->start_y = start_y;
        }
         void set_line_width(unsigned int line_width)
        {
            this->line_width = line_width;
        }
         
        virtual void info()const
        {
            cout << "Площадь фигуры " << get_area() << endl;
            cout << "Периметр фигуры " << get_perimeter() << endl;
            draw();
        }
    };

  /*  class Square :public Shape
    {
        double side;
    public:
        Square(double side, Color color) :Shape(color)
        {
            set_side(side);
        }
        virtual ~Square() {}
        double get_area()const override
        {
            return side * side;
        }
        double get_perimeter()const override
        {
            return side * 4;
        }
        void draw()const override
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, get_color());
            for (int i = 0; i < side; i++)
            {

                for (int i = 0; i < side; i++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);

        }
        double get_side()const
        {
            return side;
        }
        void set_side(double side)
        {
            this->side = side;
        }
        void info()const override
        {
            cout << typeid(*this).name() << endl;
            cout << "Длина стороны " << side << endl;
            Shape::info();
        }
    };*/
    class Rectangle :public Shape
    {
        double width;
        double height;
    public:
        Rectangle( double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
        {
            set_width(width);
            set_height(height);
        }
        double get_width()const
        {
            return width;
        }
        double get_height()const
        {
            return height;
        }
        void set_width(double width)
        {
            this->width = width;
        }
        void set_height(double height)
        {
            this->height = height;
        }
        ~Rectangle() {}
        double get_area()const override
        {
            return width * height;
        }
        double get_perimeter()const override
        {
            return (width + height) * 2;
        }
        void draw()const override
        {

            HWND hwnd = GetConsoleWindow();	
            HDC hdc = GetDC(hwnd);			
            HPEN hPen = CreatePen(PS_SOLID, 5, get_color());	

            HBRUSH hBrush = CreateSolidBrush(get_color());

            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);

            ::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);

            DeleteObject(hPen);
            DeleteObject(hBrush);

            ReleaseDC(hwnd, hdc);
        }
        void info()const override
        {
            cout << typeid(*this).name() << endl;
            cout << "Ширина " << get_width() << endl;
            cout << "Высота " << get_height() << endl;
            Shape::info();
        }
    };
    class Square :public Rectangle
    {
    public:
        Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
        ~Square() {}
    };

    class Circle :public Shape
    {
        double rad;
    public:
        Circle(double rad, Color color) :Shape(SHAPE_GIVE_PARAMETERS)
        {
            set_rad(rad);
        }
        double get_rad()const
        {
            return rad;
        }
        void set_rad(double rad)
        {
            this->rad = rad;
        }
        ~Circle(){}
        double get_area()const override
        {
            return ((rad * rad) * 3.14);
        }
        double get_perimeter()const override
        {
            return(rad * 3.14) * 2;
        }
        void draw()const override
        {

            HWND hwnd = GetConsoleWindow();
            HDC hdc = GetDC(hwnd);
            HPEN hPen = CreatePen(PS_SOLID, 5, get_color());

            HBRUSH hBrush = CreateSolidBrush(get_color());

            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);

            ::Ellipse(hdc, 400, 240, 470, 310);

            DeleteObject(hPen);
            DeleteObject(hBrush);

            ReleaseDC(hwnd, hdc);
        }
        void info()const override
        {
            cout << typeid(*this).name() << endl;
            cout << "Радиус " <<get_rad()<< endl;
            Shape::info();
        }
    };
    

}

void main()
{
    setlocale(LC_ALL, "Russian");
    Geometry::Square square(50, 300, 50, 5, Geometry::Color::YELLOW);    square.info();
   Geometry:: Rectangle rect(80, 200, 500, 50, 3, Geometry::Color::BLUE);
   rect.info();
   Geometry::Circle circle(10, Geometry::Color::GREEN);
   circle.info();
}