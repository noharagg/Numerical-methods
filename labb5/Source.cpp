#include <iostream>
#include <fstream>
#include "Integral.h"
#include "system.h"

void main(int argc, char* argv[]) {
	std::ofstream out("solution.txt");
	function f = func;
	method trap = methodTrap;
	method simpson = methodSimpson;
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
	double solutionDual = cubeSimpson(0, 1, 1, 2);
	out << "Trap = " << solutionTrap << " Count iteration = " << countTrap<<  "Step =  "<< 0.1*pow(0.5,countTrap)<< std::endl;
	out << "Simpson = " << solutionSimpson << " Count iteration = " << countSimpson<< " Step =  " << 0.1*pow(0.5, countSimpson)<<  std::endl;
	out << "Dual = " << solutionDual << std::endl;
	out.close();
	std::cout << e;
}