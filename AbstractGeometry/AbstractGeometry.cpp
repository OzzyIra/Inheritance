#include"AbstractGeometry.h"

Geometry::Shape(SHAPE_TAKE_PARAMETERS) :color(color)
        {
            set_start_x(start_x);
            set_start_y(start_y);
            set_line_width(line_width);
            count++;
        } }