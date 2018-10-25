#include<vector>
#include"sle_solver.h"
#include"nonlinear_system.h"
#ifndef _nonlinear_solver_h
#define _nonlinear_solver_h
typedef double(*func)(std::vector<double>);

double derivative(func, std::vector<double>, int);

bool nonlinear_solver(std::vector<func> &, std::vector<double> &, int &, double &);

double norm_vector(std::vector<func>, std::vector<double>);

double norm_change(std::vector<double> &, std::vector<double>);
#endif 

