#pragma once
#include"Ellipse.h"
#include"Circle.h"
#include"Helix.h"

class IParametricCurveVisitor
{
public:
	virtual ~IParametricCurveVisitor() = default;

	virtual void Visit(Ellipse& ellipse) = 0;
	virtual void Visit(Circle& circle) = 0;
	virtual void Visit(Helix& helix) = 0;
};

