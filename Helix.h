#pragma once
#include"Ellipse.h"

class IParametricCurveVisitor;

class Helix : public IParametricCurve {
	Point3D m_beginPoint;
	double m_step;
public:
	Helix(Point3D b_point, double step);
	Point3D GetPoint(double t) override;
	Vector3D GetDerivative(double t) override;
	void Accept(IParametricCurveVisitor* visitor);
};

