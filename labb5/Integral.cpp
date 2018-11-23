#include "Integral.h"
#include <cmath>

const double e = 1e-7;


double methodTrap(double a, double b, double h,func f,int& count) {
	double integral = 0, integral_prev = 0, sum = 0;
	int n = (b - a)/h;
	do {
		integral_prev = integral;
		integral = f(a) + f(b);
		sum = 0;
		
		for (int i = 1; i < n; i++) {
			sum += 2 * f(a + i * h);
		}
		integral += sum;
		integral *= h / 2;
		count++;
		h /= 2;
		n *= 2;
	} while (abs(integral_prev - integral) >= 3 * e);
	return integral;
}


double methodSimpson(double a, double b, double h, func f,int& count) {
	double integral = 0.0, integral_prev = 0.0, sum = 0.0;
	int n = (b - a) / h;
	do {
		integral_prev = integral;
		integral = f(a) + f(b);
		sum = 0;
		for (int i = 1; i < n; i++) {
			if (i % 2 != 0) {
				sum += 4 * f(a + i * h);
			}
			else {
				sum += 2 * f(a + i * h);
			}
		}
		integral += sum;
		integral *= h / 3;
		count++;
		h /= 2;
		n *= 2;
	} while (abs(integral_prev - integral) >= 15 * e);
	return integral;
}