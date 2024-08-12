#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include<Windows.h>
using namespace std;

#define SHAPE_TAKE_PARAMETERS unsigned start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x,start_y,line_width,color

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
    };
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
        Shape(SHAPE_TAKE_PARAMETERS);
        virtual ~Shape();
        virtual double get_area()const = 0;
        virtual double get_perimeter()const = 0;
        virtual void draw()const = 0;
        static int get_count();
        Color get_color()const;
        void  set_color(Color color);
        unsigned int get_start_x()const;
        unsigned int get_start_y()const;
        unsigned int get_line_width()const;
        void set_start_x(unsigned int start_x);
        void set_start_y(unsigned int start_y);
        void set_line_width(unsigned int line_width);
        double filter_size(double size);
        virtual void info()const;
};
}
