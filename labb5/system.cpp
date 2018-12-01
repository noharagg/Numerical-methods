#include "system.h"
#include <cmath>

double func(double x) {
	return (sin(x)*sin(x)) / pow(1 + x * x*x, 0.5);
}

double func2(double x, double y ) {
	return sin(x*x + y * y) / (1 + x + y);
}

double func3(double x, double y) {
	return	7 - x * x - y * y;
}