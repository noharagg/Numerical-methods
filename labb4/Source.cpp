#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Galaxy.h"
#include "mnk.h"


const int m = 1;
const double c = 3e8;

void convert(double* solution);
double getDistance(double bias, double habl, double b);
std::vector<Galaxy> readFile(std::ifstream &in, int &n);
void convertForE(double* solution);

int main() {
	std::ifstream in("galaxies.csv");
	std::ofstream out("solution.txt");
	if (!in.is_open()) {
		out << "File undefined";
		return 0;
	}
	int n = 0;
	std::vector<Galaxy> myVector = readFile(in,n);
	double* solution = mnk(myVector, n, m);
	if (out.is_open()) {
			out << "dev = " << deviation(myVector, solution, n, m) << std::endl;
	}
	convert(solution);
	for (int i = 0; i < m + 1; i++) {
		out << "a[" << i << "] = " << solution[i] << std::endl;
	}
	//out << "b = " << solution[0] << std::endl << "H = " << solution[1] << std::endl;
	out << " distance for OGC 02716 = " << getDistance(0.00127, solution[1], solution[0]) << std::endl;
	out << " distance for OGC 9357 = " << getDistance(0.01325, solution[1], solution[0]) << std::endl;

	//Часть Е
	out << " Часть E " << std::endl;
	std::ifstream in2("e.csv");
	if (!in.is_open()) {
		out << "File undefined";
		delete[] solution;
		return 0;
	}
	n = 0;
	std::vector<Galaxy> myVector2 = readFile(in2, n);

	for (int i = 0; i < n; i++) {
		myVector2[i].setDistance(log(myVector2[i].getDistance()));
	}

	double* solution2 = mnk(myVector2, n, m);
	if (out.is_open()) {
		out << "dev = " << deviation(myVector2, solution2, n, m) << std::endl;
	}
	convertForE(solution2);
	for (int i = 0; i < m + 1; i++) {
		out << "a[" << i << "] = " << solution2[i] << std::endl;
	}
	out.close();
	delete[] solution;
	delete[] solution2;
	return 0;
}

void convert(double* solution) {
	solution[1] = pow(solution[1]/c, -1);
	solution[0] *= -1 * solution[1];
}

void convertForE(double* solution) {
	solution[1] = -solution[1];
	solution[0] = exp(solution[0]);
}

 double getDistance(double bias, double habl, double b) {
	 double distance = 0;
	 return (c*bias - b)/habl;
}

 std::vector<Galaxy> readFile(std::ifstream &in,int &n) {
	 std::string line;
	 std::vector<Galaxy> myVector;
	 int count = 0;
	 double d = 0;
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
	 return myVector;
 }