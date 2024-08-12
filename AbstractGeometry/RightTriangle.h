#pragma once
#include"Triangle.h"

namespace Geometry
{
	class RightTriangle :public Triangle
	{
		double leg1;
		double leg2;
	public:
		RightTriangle(double leg1, double leg2, SHAPE_TAKE_PARAMETERS);
		double get_leg1()const;
		void set_leg1(double leg1);
		double get_leg2()const;
		void set_leg2(double leg2);
		double get_height()const override;
		double get_area()const override;
		double get_hypotenuse()const;
		double get_perimeter()const override;
		void draw()const override;
		~RightTriangle();
		void info()const override;
	};
}
