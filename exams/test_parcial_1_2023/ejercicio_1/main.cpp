#include "funcs.h"

double h(double V)
{
	double k = 1.3806503e-23;
	double N = 1000;
	double T = 300;
	
	double P = 3.5e7;
	double a = 0.401;
	double b = 42.7e-6;
	return (P + a*pow(N/V, 2) * (V - N*b) - k*N*T);
}
int main(void)
{
	double n_iter = 0;
	double eps = 1e-12;
	double a = 0.005;
	double b = 0.02;
	double x = biseccion(h,a,b, eps, n_iter);
	cout << fixed << setprecision(12);
	cout << x << endl ;
}