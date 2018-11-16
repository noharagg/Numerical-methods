#include "mnk.h"
#include "sle_solver.h"

double** copy(std::vector<std::vector<double>> matrix, int n);
double* copy(std::vector<double> matrix, int n);
void garbage_collector(double **matrix, int size);

double* mnk(std::vector<Galaxy> myVector, int n, int m) {
	double** copyA = new double*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		copyA[i] = new double[m + 1];
	}
	double* copyB = new double[m + 1];
	std::vector<std::vector<double>> A(m + 1, std::vector<double>(m + 1));
	std::vector<double> B(m + 1);
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			A[i][j] = 0;
		}
	}
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			for (int k = 0; k < n; k++) {
				A[i][j] += pow(myVector[k].getBias(), i + j);
			}
		}
	}
	A[0][0] = n;
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n; j++)
			B[i] += myVector[j].getDistance() * pow(myVector[j].getBias(), i);
	}

	copyA = copy(A, m + 1);
	copyB = copy(B, m + 1);
	double *solution = method_gaus(m + 1, copyA, copyB);
	garbage_collector(copyA, m + 1);
	delete[] copyB;
	return solution;
}

double** copy(std::vector<std::vector<double>> matrix, int n) {
	double** matrix2 = new double*[n];
	for (int i = 0; i < n; i++) {
		matrix2[i] = copy(matrix[i], n);
	}
	return matrix2;
}

double* copy(std::vector<double> matrix, int n) {
	double* matrix2 = new double[n];
	for (int i = 0; i < n; i++) {
		matrix2[i] = matrix[i];
	}
	return matrix2;
}



double deviation(std::vector<Galaxy> vect, double *solution, double n, double m) {
	double value = 0, temp;
	for (int i = 0; i < n; i++) {
		temp = vect[i].getDistance();
		for (int j = 0; j < m + 1; j++)
			temp -= solution[j] * pow(vect[i].getBias(), j);
		value += temp * temp;
	}
	return pow(value / (n - m - 1),0.5);
}

void garbage_collector(double **matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}