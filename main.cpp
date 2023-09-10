#include"Curve.h"
#include"Circle.h"
#include"Ellipse.h"
#include"Helix.h"
#include"TypeDetermination.h"

#include<iostream>
#include <memory>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
#include<omp.h>
#include<fstream>
#include<iomanip>


int main(){
	double sumOfRadii = 0.0;
	double lowerBound = -1000.0;
	double upperBound = 1000.0;
	std::vector<std::shared_ptr<IParametricCurve>> curves;
	std::uniform_real_distribution<double> unif(lowerBound, upperBound);
	std::uniform_int_distribution<int> unii(1, 3);
	std::random_device rd;
	std::default_random_engine re{ rd() };
	for (int i = 0; i < 10000; i++) {
		switch ( static_cast<CurveType>(unii(re))) {
		case CurveType::Ellipse: {
				Point3D tmpPoint;
				double rad, extra;
				tmpPoint.x = unif(re);
				tmpPoint.y = unif(re);
				tmpPoint.z  = 0.0;
				rad = abs(unif(re));
				extra = abs(unif(re));
				curves.emplace_back(std::make_shared<Ellipse>(tmpPoint, rad, extra));
				break;
			}
		case CurveType::Circle: {	
				Point3D tmpPoint;
				double rad;
				tmpPoint.x = unif(re);
				tmpPoint.y = unif(re);
				tmpPoint.z = 0.0;
				rad = abs(unif(re));
				curves.emplace_back(std::make_shared<Circle>(tmpPoint, rad));
				break; 
			}
		case CurveType::Helix: {
				Point3D tmpPoint;
				double step;
				tmpPoint.x = unif(re);
				tmpPoint.y = unif(re);
				tmpPoint.z = unif(re);
				step = unif(re);
				curves.emplace_back(std::make_shared<Helix>(tmpPoint, step));
				break; 
			}
		default: {
				break;
			}
		}
	}

	std::vector<std::shared_ptr<Circle>> circles;
	TypeDetermintion td;
	std::ofstream fout("out.txt");
	fout.clear();
	for (const auto& curve : curves) {
		const Point3D point = curve->GetPoint(M_PI_4);;
		const Vector3D derivative = curve->GetDerivative(M_PI_4);
		fout << std::setw(10) << point.x
			<< std::setw(10) << point.y
			<< std::setw(10) << point.z <<
			"\t\t" << std::setw(10)<< derivative.x
			<< std::setw(10) << derivative.y
			<< std::setw(10) << derivative.z << std::endl;
		curve->Accept(&td);
		if (td.getType() == CurveType::Circle) {
			circles.emplace_back(std::dynamic_pointer_cast<Circle>(curve));
		}
	}
	fout.close();

	std::sort(circles.begin(), circles.end(), 
		[](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {return a->GetMainRadius() < b->GetMainRadius(); });

#pragma omp parallel
	{  
		double threadSum = 0.0;
#pragma omp for
		for (int i = 0; i < circles.size(); i++) {
			threadSum += circles[i]->GetMainRadius();
		}
#pragma omp atomic
		sumOfRadii += threadSum;
	}

	double sequenceSum = 0.0;
	for (int i = 0; i < circles.size(); i++) {
		sequenceSum = sequenceSum + circles[i]->GetMainRadius();
	}
	return 0;
} 