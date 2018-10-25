#include <iostream>
#include <vector>
#include <fstream>
#include "model.h"

#ifndef _system_slover_h
#define _system_slover_h
double const h = 0.15;

typedef double(*func)(double,double);

void method_euler(std::vector<double> &x, std::vector<double> &y, int end, std::vector<func>, int);
#endif