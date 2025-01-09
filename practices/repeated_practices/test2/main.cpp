#include "../all_functions/computation_II.h"

void rk4_con_metodo_del_disparo(double a, double b, double ua, double ub, matrix <double(*)(matrix <double>, double)> Z_derivatives, double h, double eps);

double f1(matrix <double> cond_inic, double x)
{
	return cond_inic(1,0);
}

double f2(matrix <double> cond_inic, double x)
{
	return cos(x) - cond_inic(0,0)*cond_inic(1,0) + sin(x)*cond_inic(0,0)*cond_inic(0,0);
}

int main(void)
{
	double a = 0; double ua = 10;
	double b = 10; double ub = 10;
	double eps = 1e-5;
	double h = 0.01;
	matrix <double(*)(matrix <double>, double)> Z_derivatives = {{f1}, {f2}};
	
	rk4_con_metodo_del_disparo(a, b,ua,ub, Z_derivatives, h,eps);
}