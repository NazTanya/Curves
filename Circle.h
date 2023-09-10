#pragma once
#include"Ellipse.h"


class Circle : public Ellipse {
public:
	Circle(Point3D center, double radius);

	void Accept(IParametricCurveVisitor* visitor);
};