#pragma once
#include"Shape.h"

namespace Geometry
{
	class Triangle :public Shape
	{
	public:
		virtual double get_height()const = 0;
		Triangle(SHAPE_TAKE_PARAMETERS);
		~Triangle();
		void info()const override;
	};
}
