#pragma once
#include"Triangle.h"

namespace Geometry
{
    class Isoscelestriangle :public Triangle
    {
        double base_side;
        double side;
    public:
        Isoscelestriangle(double side, double base_side, SHAPE_TAKE_PARAMETERS);
        double get_base_side()const;
        void set_base_side(double base_side);
        double get_side()const;
        void set_side(double side);
        double get_height()const override;
        double get_area()const override;
        double get_perimeter()const override;
        ~Isoscelestriangle();
        void draw()const override;
        void info()const override;

    };
}
