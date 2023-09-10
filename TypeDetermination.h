#pragma once
#include"Visitor.h"

class Ellipse;
class Circle;
class Helix;

enum class CurveType { Ellipse = 1, Circle = 2, Helix = 3 };

class TypeDetermintion : public IParametricCurveVisitor {

	CurveType m_type;

	void Visit(Ellipse& ellipse) override;
	void Visit(Circle& circle) override;
	void Visit(Helix& helix) override;
public:
	CurveType getType() const;
};