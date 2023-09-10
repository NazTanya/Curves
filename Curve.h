#pragma once
#define _USE_MATH_DEFINES
#include"Point3D.h"
#include"Vector3D.h"
#include<cmath>

class IParametricCurveVisitor;

class IParametricCurve {
public:
	virtual ~IParametricCurve() = default;
	virtual Point3D GetPoint(double t ) = 0;
	virtual Vector3D GetDerivative(double t) = 0;
	
	virtual void Accept(IParametricCurveVisitor* visitor) = 0;
};