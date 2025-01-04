#include "funcs.h"

double f(double lambda)
{
	double K = 0.25 * 1e-3;
	double Re = 200000;
	double D = 0.3;
	return (2*log10((2.51)/(sqrt(lambda) *Re) + K/(3.71*D))+ 1/sqrt(lambda));
}
double f_prime(double lambda)
{
	double K = 0.25 * 1e-3;
	double Re = 200000;
	double D = 0.3;
	double A = -0.5*pow(lambda, -3./2.);
	double B = ((2.51)/(sqrt(lambda) *Re) + K/(3.71*D));
	return (2.0/log(10.0)*2.51*A/Re/B + A);
}

int main(void)
{
	double eps = 1e-5;
	double bis_x1 = 0.0001;
	double bis_x2 = 1;
	double newt_x = 0.0001;
	double bis_n_iter, newt_n_iter;
	double bis = biseccion(f, bis_x1, bis_x2, eps, bis_n_iter);
	//double sec = secante(f, bis_x1, bis_x2, eps, bis_n_iter);
	double newt = newton(f, f_prime, bis_x1, eps, newt_n_iter);
	eps = 1e-8;
	cout << fixed << setprecision(8);

	cout << bis << endl << bis_n_iter  << endl;
	cout << newt << endl << newt_n_iter  << endl;
}