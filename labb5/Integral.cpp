#include "Integral.h"
#include <cmath>
#include "system.h"

double methodTrap(double a, double b, double e, int& count) {
	double h = 0.1;
	double integral = 0, integral_prev = 0, sum = 0;
	int n = (b - a)/h;
	do {
		integral_prev = integral;
		integral = func(a) + func(b);
		sum = 0;
		
		for (int i = 1; i < n; i++) {
			sum += 2 * func(a + i * h);
		}
		integral += sum;
		integral *= h / 2;
		count++;
		h /= 2;
		n *= 2;
	} while (abs(integral_prev - integral) >= 3 * e);
	return integral;
}


double methodSimpson(double a, double b, double e, int& count) {
	double h = 0.1;
	double integral = 0.0, integral_prev = 0.0, sum = 0.0;
	int n = (b - a) / h;
	do {
		integral_prev = integral;
		integral = func(a) + func(b);
		sum = 0;
		for (int i = 1; i < n; i++) {
			if (i % 2 != 0) {
				sum += 4 * func(a + i * h);
			}
			else {
				sum += 2 * func(a + i * h);
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

double cubeSimpson(double a1, double a2 , double b1, double b2) {
	double hx = 0.01, hy = 0.01;
	int m = (b2-b1) / (2*hy), n = (a2 - a1) / (2*hx);
	double integral = 0.0, sum = 0.0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += func2(a1 + 2 * hx * i, b1 + 2 * hy * j);
			sum += 4 * func2(a1 + (2 * i + 1)* hx, b1 + 2*j*hy);
			sum += func2(a1 + (2 * i  + 2) * hx, b1 + (2 * j) * hy);
			sum += 4 * func2(a1 + (2 * i) * hx, b1 + (2 * j + 1) * hy);
			sum += 16 * func2(a1 + (2 * i + 1) * hx, b1 + (2 * j + 1) * hy);
			sum += 4 * func2(a1 + (2 * i + 2) * hx, b1 + (2 * j + 1) * hy);
			sum += func2(a1 + (2 * i) * hx, b1 + (2 * j + 2) * hy);
			sum += 4 * func2(a1 + (2 * i + 1) * hx, b1 + (2 * j + 2) * hy);
			sum += func2(a1 + (2 * i + 2) * hx, b1 + (2 * j + 2) * hy);
		}
	}
	integral += sum;
	integral *= (hx * hy / 9);
	return integral;
}