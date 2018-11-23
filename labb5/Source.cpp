#include <iostream>
#include <fstream>
#include "Integral.h"
#include "system.h"
void main() {
	std::ofstream out("solution.txt");
	double a = 1;
	double b = 3;
	double h ;
	std::cin >> h;
	int countTrap = 0, countSimpson = 0;
	double solutionTrap = methodTrap(a, b, h, getFunc(),countTrap);
	double solutionSimpson = methodSimpson(a, b, h, getFunc(), countSimpson);
	out << "Trap = " << solutionTrap << " Count iteration = " << countTrap<<  std::endl;
	out << "Simpson = " << solutionSimpson << " Count iteration = " << countSimpson<<  std::endl;
	out.close();
}