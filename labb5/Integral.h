
typedef double(*func)(double);

double methodTrap(double a, double b, double h, func);

double methodSimpson(double a, double b, double h, func);