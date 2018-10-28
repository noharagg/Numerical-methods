#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
#include"nonlinear_solver.h"

int main(int argc, char* argv[]) {

	std::ofstream out("solution.txt");

	std::vector<func> system_matrix = nonlinear_system();
	std::vector<double> initial_approximation = get_initial_approximation();
	
	auto start = std::chrono::high_resolution_clock::now();
	int count_iterarion = 100;
	double  norm_x = 0;
	bool b = nonlinear_solver(system_matrix, initial_approximation, count_iterarion , norm_x);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Time - " << diff.count() << std::endl;
	std::cout << "Norm_Vector - " << norm_vector(system_matrix, initial_approximation) << std::endl;
	std::cout << "Norm_X - " << norm_x << std::endl;
	std::cout << "Count iteration  - " << count_iterarion << std::endl;

	if (b) {
		for (int i = 0; i < (int)initial_approximation.size(); i++) {
			out << initial_approximation[i] << " ";
		}
	}
	else {
		out << "UNDEFINED";
	}
	return 0;
}