#include"Helix.h"
#include"Visitor.h"

#include<iostream>


Helix::Helix(Point3D b_point, double step) : m_beginPoint{ b_point },m_step{ step } {} 

Vector3D Helix::GetDerivative(double t) {
	return { -sin(t),
			cos(t),
			m_step / (2 * M_PI) };
}

Point3D Helix::GetPoint(double t) {
	return { m_beginPoint.x + cos(t),
			m_beginPoint.y + sin(t),
			m_beginPoint.z + ((m_step * t) / (2 * M_PI)) };
}

void Helix::Accept(IParametricCurveVisitor* visitor) {
	visitor->Visit(*this);
}