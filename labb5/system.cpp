#include "system.h"
#include <cmath>

double function(double x) {
	return (sin(x)*sin(x)) / pow(1 + x * x*x, 0.5);
}

func getFunc() {
	return function;
}