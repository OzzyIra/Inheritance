#define _USE_MATH_DEFINES
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
        YELLOW = 0x0000FFFF,
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

        static const int MIN_START_X = 100;
        static const int MAX_START_X = 1000;
        static const int MIN_START_Y = 100;
        static const int MAX_START_Y = 500;
        static const int MIN_LINE_WIDTH = 1;
        static const int MAX_LINE_WIDTH = 32;
        static const int MIN_SIZE = 50;
        static const int MAX_SIZE = 550;
        static int count;
    public:
        Shape(SHAPE_TAKE_PARAMETERS) :color(color)
        {
            set_start_x(start_x);
            set_start_y(start_y);
            set_line_width(line_width);
            count++;
        }
        virtual ~Shape()
        {
            count--;
        }
        virtual double get_area()const = 0;
        virtual double get_perimeter()const = 0;
        virtual void draw()const = 0;
        static int get_count()
        {
            return count;
        }
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
            if (start_x < MIN_START_X)start_x = MIN_START_X;
            if (start_x > MAX_START_X)start_x = MAX_START_X;
            this->start_x = start_x;
        }
        void set_start_y(unsigned int start_y)
        {
            if (start_y < MIN_START_Y)start_y = MIN_START_Y;
            if (start_y > MAX_START_Y)start_y = MAX_START_Y;
            this->start_y = start_y;
        }
        void set_line_width(unsigned int line_width)
        {
            if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
            if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
            this->line_width = line_width;
        }
        double filter_size(double size)
        {
            if (size < MIN_SIZE)size = MIN_SIZE;
            if (size > MAX_SIZE)size = MAX_SIZE;
            return size;
        }

        virtual void info()const
        {
            cout << "Площадь фигуры " << get_area() << endl;
            cout << "Периметр фигуры " << get_perimeter() << endl;
            draw();
        }
    };
    int Shape::count = 0;

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
        Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
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
            this->width = filter_size(width);
        }
        void set_height(double height)
        {
            this->height = filter_size(height);
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
        Circle(double rad, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
        {
            set_rad(rad);
        }
        double get_rad()const
        {
            return rad;
        }
        void set_rad(double rad)
        {
            this->rad = filter_size(rad);
        }
        ~Circle() {}
        double get_diameter()const
        {
            return 2 * rad;
        }
        double get_area()const override
        {
            return ((rad * rad) * M_PI);
        }
        double get_perimeter()const override
        {
            return M_PI * get_diameter();;
        }
        void draw()const override
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
        void info()const override
        {
            cout << typeid(*this).name() << endl;
            cout << "Радиус " << get_rad() << endl;
            Shape::info();
        }
    };

    class Triangle :public Shape
    {
    public:
        virtual double get_height()const = 0;
        Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}
        ~Triangle() {}
        void info()const override
        {
            cout << "Высота треугольника: " << get_height() << endl;
            Shape::info();
        }
    };
    class EquilateralTriangle :public Triangle
    {
        double side;
    public:
        double get_side()const
        {
            return side;
        }
        void set_side(double side)
        {
            this->side = filter_size(side);
        }
        double get_height()const override
        {
            return sqrt(side * side - side / 2 * side / 2);
        }
        double get_area()const override
        {
            return side / 2 * get_height();
        }
        double get_perimeter()const override
        {
            return side * 3;
        }
        void draw()const override
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

        EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
        {
            set_side(side);
        }
        ~EquilateralTriangle() {}
        void info()const override
        {
            cout << typeid(*this).name() << endl;
            cout << "Длина стороны:\t" << side << endl;
            Triangle::info();
        }
    };
    class Isoscelestriangle :public Triangle
    {
        double base_side;
        double side;
    public:
        double get_base_side()const
        {
            return base_side;
        }
        void set_base_side(double base_side)
        {
            this->base_side = filter_size(base_side);
        }
        double get_side()const
        {
            return side;
        }
        void set_side(double side)
        {
            this->side = filter_size(side);
        }
        double get_height()const override
        {
            return sqrt(side * side - base_side / 2 * base_side / 2);
        }
        double get_area()const override
        {
            return base_side / 2 * get_height();
        }
        double get_perimeter()const override
        {
            return base_side + side * 2;
        }
        void draw()const override
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

        Isoscelestriangle(double side, double base_side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
        {
            set_side(side);
            set_base_side(base_side);
        }
        ~Isoscelestriangle() {}
        void info()const override
        {
            cout << typeid(*this).name() << endl;
            cout << "Длина стороны:\t" << side << endl;
            cout << "Длина основания:\t" << base_side << endl;
            Triangle::info();
        }
    };
    class RightTriangle :public Triangle
    {
        double leg1;
        double leg2;
    public:
        double get_leg1()const
        {
            return leg1;
        }
        void set_leg1(double leg1)
        {
            this->leg1 = filter_size(leg1);
        }
        double get_leg2()const
        {
            return leg2;
        }
        void set_leg2(double leg2)
        {
            this->leg2 = filter_size(leg2);
        }
        double get_height()const override
        {
            return (leg1 * leg2)/ get_hypotenuse();
        }
        double get_area()const override
        {
            return (leg1 * leg2) / 2;
        }
        double get_hypotenuse()const
        {
           return sqrt(leg1 * leg1 + leg2 * leg2);
        }
        double get_perimeter()const override
        {
            return  get_hypotenuse() + leg1 + leg2;
        }
        void draw()const override
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
        RightTriangle(double leg1, double leg2, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
        {
            set_leg1(leg1);
            set_leg2(leg2);
        }
        ~RightTriangle() {};
        void info()const override
        {
            cout << typeid(*this).name() << endl;
            cout << "Длина катета1:\t" << leg1 << endl;
            cout << "Длина катета2:\t" << leg2 << endl;
            Triangle::info();
        }
    };
};
    



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