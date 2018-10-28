#include <cmath>
#include "nonlinear_system.h"

typedef double(*func)(std::vector<double>);
using std::vector;

// |f0(x, y) = 0      | x^2 + y^3 + 7 = 0
// |f1(x, y) = 0      | x/y + 0.5 = 0
//
// solution: x = 1, y = -2

double f0(vector<double> x) {
	return x[0]*x[0] +1;
}

double f1(vector<double> x) {
	return x[1]*x[1] + 1;
}


vector<func> nonlinear_system() {
	vector<func> snle;
	snle.push_back(&f0);
	snle.push_back(&f1);
	return snle;
}

vector<double> get_initial_approximation() {
	return { 1, 1 };
}