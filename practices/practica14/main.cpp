#include "funcs.h"

double f(double x)
{
	return ((x*x - x + 1) * sin(x)*sin(x));
}



int main(void)
{
	double a = -6.0;
	double b = 6.0;
	double exact_solution = 78 - 3*cos(12) - 73*sin(12)/4;
	// Apartado a)
	double ans = gauss_6(f, a, b);
	cout << "ans = " << ans << "  exact_sol" << exact_solution<< endl;

	// Apartado b)
	double err = abs(exact_solution - ans);
	cout << "gauss error: " << err << endl;

	// Apartado c)
	double n_partitions = 1;
	double tau;
	double simp_err;

	tau = (b - a)/n_partitions;
	simp_err = abs(exact_solution - simpson(f, a, b, tau));
	while(simp_err > err)
	{
	n_partitions++;
	tau = (b - a)/n_partitions;
	simp_err = abs(exact_solution - simpson(f, a, b, tau));
	}
	cout << "It was necessary in simpson: " << n_partitions << "partitions" <<endl;

	cout << "---------------------" << endl;
	cout << "ONE INTEGRAL [-6, 6]" <<endl;
	cout << "fraction simpson/Gauss : " << (int) n_partitions/6<< endl;
	cout << "---------------------" << endl;

	n_partitions = 1;
	double trap_err;
	tau = (b - a)/n_partitions;
	trap_err = abs(exact_solution - trapezoidal(f, a, b, tau));
	while(trap_err > err)
	{
	n_partitions++;
	tau = (b - a)/n_partitions;
	trap_err = abs(exact_solution - trapezoidal(f, a, b, tau));
	}
	cout << "It was necessary in trapezoidal: " << n_partitions << "partitions" <<endl;

	cout << "---------------------" << endl;
	cout << "ONE INTEGRAL [-6, 6]" <<endl;
	cout << "fraction trapecio/gauss : " << (int) n_partitions/6<< endl;
	cout << "---------------------" << endl;



	// Apartado d)
	double I = gauss_6(f, a, 0.) + gauss_6(f, 0., b);
	err = abs(I - exact_solution);
	cout << "gauss error with 2 parts:" << err << endl;
	n_partitions = 1;

	tau = (b - a)/n_partitions;
	simp_err = abs(exact_solution - simpson(f, a, b, tau));
	while(simp_err > err)
	{
	n_partitions++;
	tau = (b - a)/n_partitions;
	simp_err = abs(exact_solution - simpson(f, a, b, tau));
	}
	cout << "It was necessary in simpson: " <<  n_partitions << "partitions" <<endl;

	cout << "---------------------" << endl;
	cout << "TWO INTEGRALS [-6, 0] + [0, 6]" <<endl;
	cout << "fraction simpson/gauss : " << (int) n_partitions/12 << endl;
	cout << "---------------------" << endl;
	n_partitions = 1;
	tau = (b - a)/n_partitions;
	trap_err = abs(exact_solution - trapezoidal(f, a, b, tau));
	while(trap_err > err)
	{
	n_partitions++;
	tau = (b - a)/n_partitions;
	trap_err = abs(exact_solution - trapezoidal(f, a, b, tau));
	}
	cout << "It was necessary in trapezoidal: " << n_partitions << "partitions" <<endl;
	cout << "---------------------" << endl;
	cout << "TWO INTEGRALS [-6, 0] + [0, 6]" <<endl;
	cout << "fraction simpson/gauss : " << (int) n_partitions/12<< endl;
	cout << "---------------------" << endl;

}