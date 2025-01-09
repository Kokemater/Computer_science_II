#include "../all_functions/computation_II.h"

double g = 1.8;
double l = 20;
double phi = M_PI/4;
double w = 7.29e-5;
double k = sqrt(g/l);
void runge_kutta_4(double& x, matrix<double>& cond_iniciales, double h, matrix <double(*)(matrix <double>, double)> Z_derivatives);

double z1_prime(matrix <double> cond_inic, double t)
{
	double z1 = cond_inic(0,0);	double z2 = cond_inic(1,0);
	double z3 = cond_inic(2,0); double z4 = cond_inic(3,0);
	return (z2);
}
double z2_prime(matrix <double> cond_inic, double t)
{
	double z1 = cond_inic(0,0);	double z2 = cond_inic(1,0);
	double z3 = cond_inic(2,0); double z4 = cond_inic(3,0);
	return (2*w*sin(phi) *z4 - k*k*z1 );
}
double z3_prime(matrix <double> cond_inic, double t)
{
	double z1 = cond_inic(0,0);	double z2 = cond_inic(1,0);
	double z3 = cond_inic(2,0); double z4 = cond_inic(3,0);
	return (z4);
}
double z4_prime(matrix <double> cond_inic, double t)
{
	double z1 = cond_inic(0,0);	double z2 = cond_inic(1,0);
	double z3 = cond_inic(2,0); double z4 = cond_inic(3,0);
	return (-2*w*sin(phi) *z4 - k*k*z3 );
}

int main(void)
{
	double t0 = 0;
	double eps = 1e-6;
	double h = pow(eps, 1.0/4.0);
	matrix <double> cond_iniciales (4,1);
	matrix <double(*)(matrix <double>, double)> Z_derivatives(4,1);

	cond_iniciales(0,0) = 5; //z1(0)
	cond_iniciales(1,0) = 0; //z2(0)
	cond_iniciales(2,0) = 0; //z3(0)
	cond_iniciales(3,0) = 0; //z4(0)

	Z_derivatives(0,0) = z1_prime;
	Z_derivatives(1,0) = z2_prime;
	Z_derivatives(2,0) = z3_prime;
	Z_derivatives(3,0) = z4_prime;
	double t = t0;

	cout << t << " " << cond_iniciales(0,0) << " " << cond_iniciales(1,0) << " " << cond_iniciales(2,0) << cond_iniciales(3,0) << endl;


	runge_kutta_4(t, cond_iniciales, h, Z_derivatives);
	cout << t << " " << cond_iniciales(0,0) << " " << cond_iniciales(1,0) << " " << cond_iniciales(2,0) << cond_iniciales(3,0) << endl;
}