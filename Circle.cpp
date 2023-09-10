#include"Circle.h"
#include"Visitor.h"

Circle:: Circle(Point3D center, double radius) : Ellipse(center, radius, radius) {
}

void Circle::Accept(IParametricCurveVisitor* visitor) {
	visitor->Visit(*this);
}
