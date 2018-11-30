#include <functional>
typedef std::function<double(double)> function;

typedef std::function<double(double, double, double ,std::function<double(double)>)> method;

double solutionIntegral(method , function, double a, double b, double e, int& count, int coef);

double methodTrap(double a, double b, double h, function f);

double methodSimpson(double a, double b, double h, function);

double cubeSimpson(double a, double a1, double b1, double b);
