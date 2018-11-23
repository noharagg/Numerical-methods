#include "Integral.h"
#include <cmath>

const double e = 1e-7;


double methodTrap(double a, double b, double h,func f) {
	double integral = 0, integral_prev = 0, sum = 0;
	do {
		integral_prev = integral;
		integral = f(a) + f(b);
		sum = 0;
		
		int index = 1;
		double k = a;
		while (k < b) {
			sum += 2 * f(a + index * h);
			k += h;
			index++;
		}
		integral += sum;
		integral *= h / 2;
	} while (abs(integral_prev - integral) >= 3 * e);
	return integral;
}


double methodSimpson(double a, double b, double h, func f) {
	double integral = 0.0, integral_prev = 0.0, sum = 0.0;

	do {
		integral_prev = integral;
		integral = f(a) + f(b);
		sum = 0;
		int index = 1;
		double k = a;
		while (k < b) {
			if (index % 2 != 0) {
				sum += 4 * f(a + index * h);
			}else {
				sum += 2 * f(a + index * h);
			}
			k += h;
			index++;
		}
		integral += sum;
		integral *= h / 3;
		
	} while (abs(integral_prev - integral) >= 15 * e);
	return integral;
}