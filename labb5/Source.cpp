#include <iostream>
#include <fstream>
#include "Integral.h"
#include "system.h"
void main(int argc, char* argv[]) {
	std::ofstream out("solution.txt");
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
	double solutionTrap = methodTrap(a, b, e, getFunc(),countTrap);
	double solutionSimpson = methodSimpson(a, b, e, getFunc(), countSimpson);
	out << "Trap = " << solutionTrap << " Count iteration = " << countTrap<<  std::endl;
	out << "Simpson = " << solutionSimpson << " Count iteration = " << countSimpson<<  std::endl;
	out.close();
	std::cout << e;
}