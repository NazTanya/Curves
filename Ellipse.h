#pragma once
#include"Curve.h"

class IParametricCurveVisitor;

class Ellipse : public IParametricCurve {
	Point3D m_center;
	double m_mainRadius;
	double m_extraRadius;

public:
	
	Ellipse(Point3D center, double r_x, double r_y);
	
	Point3D GetPoint(double t) override;
	Vector3D GetDerivative(double t) override;
	
	const Point3D& GetCenter() const;
	double GetMainRadius() const;
	double GetExtraRadius() const;

	void Accept(IParametricCurveVisitor* visitor);
};
