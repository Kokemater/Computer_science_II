#include "../all_functions/computation_II.h"

double f1(double x, double y)
{
	return (x - x*x - x*y);
}
double f2(double x, double y)
{
	return (3*y - x*y - 2*y*y);
}

double f1_x(double x, double y)
{
	return (1 - 2*x - y);
}

double f1_y(double x, double y)
{
	return (-x);
}

double f2_x(double x, double y)
{
	return (-y);
}
double f2_y(double x, double y)
{
	return (3 - 4*y);
}

int main(void)
{
	matrix <double> solution(2,1);
	matrix<double (*)(double, double)> jacobiano = {{f1_x, f1_y}, {f2_x, f2_y}};
	matrix<double (*)(double, double)> funciones = {{f1} , {f2}};
	matrix <double> x1 = {{0}, {1.3}};

	double eps = 1e-6;
	double iter = 0;


	newton_non_linear(funciones, jacobiano, x1, eps, iter, solution);
	cout << solution << " iter = " << iter << endl;
}