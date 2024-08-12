#pragma once
#include"Shape.h"

namespace Geometry
{
	class Circle :public Shape
	{
		double rad;
	public:
		Circle(double rad, SHAPE_TAKE_PARAMETERS);
		double get_rad()const;
		void set_rad(double rad);
		~Circle();
		double get_diameter()const;
		double get_area()const override;
		double get_perimeter()const override;
		void draw()const override;
		void info()const override;
	};


}
