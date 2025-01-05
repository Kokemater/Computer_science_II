#include "../all_functions/computation_II.h"

double z1_prime(matrix <double> cond_inic, double x)
{
	double z1 = cond_inic(0,0);
	return (x*z1 - z1*x*x)/pow(x,2);
}

void runge_kutta_4(double& x, matrix<double>& cond_iniciales, double h, matrix <double(*)(matrix <double>, double)> Z_derivatives);

int main(void)
{
	matrix <double> cond_iniciales(1,1);
	matrix <double(*)(matrix <double>, double)> Z_derivatives(1,1);
	cond_iniciales(0,0) = 2;
	double x0 = 1;
	double x = x0;
	Z_derivatives(0,0) = z1_prime;
	double h = 0.5;
	runge_kutta_4(x, cond_iniciales, h, Z_derivatives);
	cout << x << " " << cond_iniciales(0,0) << endl;
}