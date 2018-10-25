#include "model.h"

double model_for_x(double x, double y) {
	return (alpha - betta * y)*x;
}

double model_for_y(double x, double y) {
	return (-gamma + sigma * x)*y;
}

std::vector<func> model_system() {
	std::vector<func> snle;
	snle.push_back(&model_for_x);
	snle.push_back(&model_for_y);
	return snle;
}