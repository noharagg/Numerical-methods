#include <iostream>
#include "Integral.h"
#include "system.h"
void main() {
	double a = 1;
	double b = 3;
	double h = 0.1;
	double solutionTrap = methodTrap(a, b, h, getFunc());
	double solutionSimpson = methodSimpson(a, b, h, getFunc());
	std::cout << solutionTrap << std::endl;
	std::cout << solutionSimpson << std::endl;
	system("pause");
}