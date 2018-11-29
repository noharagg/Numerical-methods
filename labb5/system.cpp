#include "system.h"
#include <cmath>

double func(double x) {
	return (sin(x)*sin(x)) / pow(1 + x * x*x, 0.5);
}

double func2(double x, double y ) {
	return sin(x*x + y * y) / (1 + x + y);
}
