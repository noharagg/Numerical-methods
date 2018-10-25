#include <vector>

typedef double(*func)(double, double);

const double alpha = 0.4;
const double betta = 0.01;
const double gamma = 0.3;
const double sigma = 0.005;

double model_for_x(double x, double y);

double model_for_y(double x, double y);

std::vector<func> model_system();