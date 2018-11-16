#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Galaxy.h"
#include "mnk.h"


const int m = 1;
const double c = 3e8;

void convert(double* solution);

int main() {
	std::ifstream in("galaxies.csv");
	std::ofstream out("solution.txt");
	if (!in.is_open()) {
		out << "File undefined";
		return 0;
	}
	std::string line;
	std::vector<Galaxy> myVector;
	int count = 0;
	double d = 0;
	int n = 0;
	while (std::getline(in, line))
	{
		std::stringstream lineStream(line);
		std::string cell;
		while (std::getline(lineStream, cell, ','))
		{
			Galaxy galaxy(cell);
			std::getline(lineStream, cell, ',');
			d = atof(cell.c_str());
			galaxy.setBias(d);
			std::getline(lineStream, cell, ',');
			d = atof(cell.c_str());
			galaxy.setDistance(d);
			myVector.push_back(galaxy);
			n++;
		}
	}
	double* solution = mnk(myVector, n, m);
	if (out.is_open()) {
			out << "dev = " << deviation(myVector, solution, n, m) << std::endl;
	}
	convert(solution);
	for (int i = 0; i < m + 1; i++) {
		out << "a[" << i << "] = " << solution[i] << std::endl;
	}
	//out << "b = " << solution[0] << std::endl << "H = " << solution[1] << std::endl;
	out.close();
	delete[] solution;
	return 0;
}

void convert(double* solution) {
	solution[1] = pow(solution[1]/c, -1);
	solution[0] *= -1 * solution[1];
}