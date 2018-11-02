#include "sle_solver.h"
#include <cmath>

double sum(double** matrix, double* x, int k, int  n, int l);
const double eps = 1e-10;

double sum(double** matrix, double* x, int k, int  n, int l) {
	double sum = 0;
	for (int i = k + 1; i < n; i++) {
		sum += matrix[l][i] * x[i];
	}
	return sum;
}

double*  method_gaus(int n, double** matrix, double* b) {
	double akk, amain;
	int l, m = 0, p = 0;
	double* x = nullptr;
	x = new double[n];
	int* ior = new int[n];
	for (int i = 0; i < n; i++) {
		ior[i] = i;
	}

	for (int k = 0; k < n; k++) {
		akk = 0;
		for (int i = k; i < n; i++) {
			l = ior[i];
			if (abs(matrix[l][k]) <= akk) {
				continue;
			}
			m = l;
			p = i;
			akk = abs(matrix[l][k]);
		}
		if (p != k) {
			ior[p] = ior[k];
			ior[k] = m;
		}

		amain = matrix[m][k];
		if (abs(amain) < eps) {
			return nullptr;
		}

		for (int i = k; i < n; i++) {
			matrix[m][i] /= amain;
		}
		b[m] /= amain;
		for (int i = k + 1; i < n; i++) {
			l = ior[i];
			for (int j = k + 1; j < n; j++) {
				matrix[l][j] -= (matrix[l][k] * matrix[m][j]);

			}
			b[l] -= (matrix[l][k] * b[m]);
		}

	}

	if (matrix[l][n - 1] < eps) {
		return nullptr;
	}
	l = ior[n - 1];
	b[l] /= matrix[l][n - 1];
	x[n - 1] = b[l];

	for (int k = n - 2; k >= 0; k--) {
		l = ior[k];
		x[k] = b[l] - sum(matrix, x, k, n, l);
	}
	return x;
}
