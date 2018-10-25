#include <vector>
#ifndef _nonlinear_system_h
#define _nonlinear_ststem_h
std::vector<double(*)(std::vector<double>)> nonlinear_system();

std::vector<double> get_initial_approximation();
#endif

