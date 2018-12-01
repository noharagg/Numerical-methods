#include <iostream>
#include <fstream>
#include "Integral.h"
#include "system.h"

typedef std::function<bool(double, double)> area;
bool area_1(double , double );
bool area_2(double , double );

void main(int argc, char* argv[]) {
	std::ofstream out("solution.txt");
	function f = func;
	method trap = methodTrap;
	method simpson = methodSimpson;
	functionDual fd = func2;
	functionDual functionForE = func3;
	area ar1 = area_1;
	area ar2 = area_2;
	double a = 1;
	double b = 3;
	double e ;
	if (argc < 2) {
		e = 1e-7;
	}
	else {
		e = atof(argv[1]);
	}
	int countTrap = 0, countSimpson = 0;
	double solutionTrap = solutionIntegral(trap,f,a,b,e,countTrap,3);
	double solutionSimpson = solutionIntegral(simpson, f, a, b, e, countSimpson, 15);
	double solutionDual = cubeSimpson(0, 1, 1, 2, fd, nullptr);
	double solutionPart_1 = cubeSimpson(-1, 1, -1, 1, functionForE,ar1);
	double solutionPart_2 = cubeSimpson(-sqrt(2),sqrt(2), -1, 1,functionForE,ar2);
	out << "Trap = " << solutionTrap << " Count iteration = " << countTrap<<  "Step =  "<< 0.1*pow(0.5,countTrap)<< std::endl;
	out << "Simpson = " << solutionSimpson << " Count iteration = " << countSimpson<< " Step =  " << 0.1*pow(0.5, countSimpson)<<  std::endl;
	out << "Dual = " << solutionDual << std::endl;
	out << "E(1) = " << solutionPart_1 << std::endl;
	out << "E(2) = " << solutionPart_2 << std::endl;
	out.close();
}

bool area_1(double x, double y) {
	double temp = x * x + y * y;
	if (temp < 1) {
		return true;
	}
	return false;
}

bool area_2(double x, double y) {
	double yForX = x * x - 1;
	if (y < 1 && y > yForX) {
		return true;
	}
	return false;
}

