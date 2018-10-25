#include "system_slover.h"

void get_start(std::vector<double>& vector_x, std::vector<double>& vector_y);

int main(int argc, char* argv[]) {
	int end = 52;
	int size = (int)(end / h) + 1;
	std::ofstream out("solution.txt");
	std::vector<double> vector_x(size);
	std::vector<double> vector_y(size);
	get_start(vector_x, vector_y);
	method_euler(vector_x, vector_y, end, model_system(),size);
	double t = 0;
	for (int i = 0; i < vector_x.size(); i++) {
		if (out.is_open()) {
			out <<"T = " <<  t << " X = " <<  vector_x[i] << " Y =  " << vector_y[i] << std::endl;
		}
		t += h;
	}

	return 0;
}

void get_start(std::vector<double>& vector_x, std::vector<double>& vector_y) {
	vector_x[0] = 70;
	vector_y[0] = 50;
}


