#include "system_slover.h"

void method_euler(std::vector<double> &x, std::vector<double> &y, int end , std::vector<func> model_system, int size) {
	for (double i = 0; i < size - 1; i ++){
		x[i + 1] = model_system[0](x[i], y[i])*h + x[i];
		y[i + 1] = model_system[1](x[i], y[i])*h + y[i];
	}
}

