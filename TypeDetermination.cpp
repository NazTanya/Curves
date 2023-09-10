#include"TypeDetermination.h"
#include"Visitor.h"
#include"Circle.h"
#include"Ellipse.h"
#include"Helix.h"


void TypeDetermintion::Visit(Ellipse& ellipse) {
	m_type = CurveType::Ellipse;
}


void TypeDetermintion::Visit(Circle& circle) {
	m_type = CurveType::Circle;
}

void TypeDetermintion::Visit(Helix& helix) {
	m_type = CurveType::Helix;
}

CurveType TypeDetermintion::getType() const {
	return m_type;
}