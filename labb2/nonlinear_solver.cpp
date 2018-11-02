#include"nonlinear_solver.h"
#include"nonlinear_system.h"
#include"sle_solver.h"
#include"sle_solver.h"

double* copy(double* matrix, int n);
double* copy(std::vector<double> matrix, int n);
double** copy(std::vector<std::vector<double>> matrix, int n);
double** copy(double** matrix, int n);
void garbage_collector(double **matrix, int size);

double derivative(func f, std::vector<double> x, int numberCoordinate) {
	std::vector<double> copyXplus = x;
	std::vector<double> copyXminus = x;
	const double e = 1e-9;
	copyXplus[numberCoordinate] += e;
	copyXminus[numberCoordinate] -= e;
	return ((f(copyXplus) - f(copyXminus)) / (2 * e));
}

bool nonlinear_solver(std::vector<func> &nonlinear_system, std::vector<double> &initial_approx, int &limited_iteration, double &norm_x) {
	const double e = 1e-9;
	int n = initial_approx.size();
	int count_iteration = 0;
	std::vector<double> previos_approx = initial_approx;
	double **partial_matrix = new double*[n];
	for (int i = 0; i < n; i++) {
		partial_matrix[i] = new double[n];
	}
	double* b = new double[n];
	double* solution = nullptr;
	double** copy_matrix = new double*[n];
	for (int i = 0; i < n; i++) {
		copy_matrix[i] = new double[n];
	}
	double* copy_b = new double[n];
	do {
		if (count_iteration == limited_iteration) {
			garbage_collector(partial_matrix, n);
			garbage_collector(copy_matrix, n);
			delete[] copy_b;
			delete[] b;
			delete[] solution;
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				partial_matrix[i][j] = derivative(nonlinear_system[i], initial_approx, j);
			}
			b[i] = nonlinear_system[i](initial_approx);
		}

		double** copy_matrix = copy(partial_matrix , n);
		double* copy_b = copy(b, n);
		solution = method_gaus(n, copy_matrix, copy_b);
		if (solution == nullptr) {
			garbage_collector(partial_matrix, n);
			garbage_collector(copy_matrix, n);
			delete[] copy_b;
			delete[] b;
			delete[] solution;
			return 0;
		}
		for (int i = 0; i < n; i++) {
			initial_approx[i] -= solution[i];
		}
		norm_x = norm_change(previos_approx,initial_approx);
		count_iteration++;
		previos_approx = initial_approx;
	} while (!(abs(norm_x) < e  && abs(norm_vector(nonlinear_system, initial_approx)) < e));
	limited_iteration = count_iteration;
	garbage_collector(partial_matrix, n);
	garbage_collector(copy_matrix, n);
	delete[] copy_b;
	delete[] b;
	delete[] solution;
	return 1;
}

double norm_vector(std::vector<func> nonlinearSystems, std::vector<double> initial_approx) {
	double max = 0;
	for (int i = 0; i < (int)initial_approx.size(); i++) {
		if (abs(max) < abs(nonlinearSystems[i](initial_approx))) {
			max = nonlinearSystems[i](initial_approx);
		}
	}
	return max;
}

double** copy(std::vector<std::vector<double>> matrix, int n) {
	double** matrix2 = new double*[n];
	for (int i = 0; i < n; i++) {
		matrix2[i] = copy(matrix[i], n);
	}
	return matrix2;
}

double** copy(double** matrix, int n) {
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

double* copy(double* matrix, int n) {
	double* matrix2 = new double[n];
	for (int i = 0; i < n; i++) {
		matrix2[i] = matrix[i];
	}
	return matrix2;
}

double norm_change(std::vector<double> &previos_approx, std::vector<double> approx) {
	double max = 0;
	for (int i = 0; i < approx.size(); i++) {
		if (abs(max) < abs(approx[i] - previos_approx[i]) && approx[i] <= 1) {
			max = approx[i] - previos_approx[i];
		}
		else if (abs(max) < (abs(approx[i] - previos_approx[i])/approx[i]) && approx[i] > 1) {
			max = (approx[i] - previos_approx[i]) / approx[i];
		}
	}
	return max;
}

void garbage_collector(double **matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete matrix;
}