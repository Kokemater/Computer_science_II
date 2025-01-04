#include "all_functions/math_stuff.h"
#include "all_functions/computation_II.h"

double z1_prime(matrix <double> cond_inic, double x)
{
	double z1 = cond_inic(0,0);
	double z2 = cond_inic(1,0);
	return z2;
}
double z2_prime(matrix <double> cond_inic, double x)
{
	double z1 = cond_inic(0,0);
	double z2 = cond_inic(1,0);
	return z2*x + (1 - x*x)*z1 + exp(-pow(x,2));
}
///////////////

double p ( double x ) {
 return x;
}
double q ( double x ) {
 return 1 - x*x;
}
double r ( double x ) {
 return std::exp(-x*x);
} 





int main ()
{
	double a, b, ua, ub,h;
	a = 0;
	b = 1;
	ua = 40;
	ub = 40;

	h = 0.1;
	diferencias_finitas(h, a, b, ua, ub);
	rk4_con_metodo_del_disparo(h, a, b, ua, ub);
	h = 0.01;
	diferencias_finitas(h, a, b, ua, ub);
	rk4_con_metodo_del_disparo(h, a, b, ua, ub);
	h = 0.001;
	diferencias_finitas(h, a, b, ua, ub);
	rk4_con_metodo_del_disparo(h, a, b, ua, ub);

	return 0;
}
