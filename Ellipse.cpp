#include"Ellipse.h"
#include"Visitor.h"

#include<iostream>

Ellipse::Ellipse(Point3D center,double r_x, double r_y):
	m_center{ center }, m_mainRadius{ r_x }, m_extraRadius{ r_y } {};

Vector3D Ellipse::GetDerivative(double t) {
	return { -m_mainRadius * sin(t),
			m_extraRadius * cos(t),
			0 };
}

Point3D Ellipse::GetPoint(double t) {
	return { m_center.x + m_mainRadius * cos(t),
			m_center.y + m_extraRadius * sin(t),
			m_center.z };
}

const Point3D& Ellipse::GetCenter() const {
	return  m_center;
}

double Ellipse::GetMainRadius() const {
	return m_mainRadius;
}

double Ellipse::GetExtraRadius() const {
	return m_extraRadius;
}

void Ellipse::Accept(IParametricCurveVisitor* visitor) {
	visitor->Visit(*this);
}