#include "funcs.h"

double f(double x)
{
	return ((x*x - x + 1) * sin(x)*sin(x));
}

double trapezoidal(double (*f)(double), double a, double b, double tau)
{
	double sum = 0;	
	int n = (b - a)/ tau;
	tau = (b - a) / n;
	for(double i = a + tau; i < b; i += tau)
	{
		sum += f(i);
	}
	return ((b - a) * (f(a) + 2*sum + f(b))/ (2 * n));
}

double simpson(double (*f) (double), double a, double b, double tau)
{
	double sum_odd = 0;
	double sum_even = 0;
	int n = (int) ((b - a)/ tau);
	tau = (b - a) / n;

	if (n % 2 != 0)
		n++;
	for (double i = a + tau; i < b; i += (2*tau))
	{
		sum_odd += f(i);
	}
	for (double j = a + 2*tau; j < b ; j += (2*tau))
	{
		sum_even += f(j);
	}
    return (b - a) * (f(a) + 4 * sum_odd + 2 * sum_even + f(b)) / (3 * n);
}
int main(void)
{
	int	a = -6;
	int b = 6;
	double exact_solution = 78 - 3*cos(12) - 73*sin(12)/4;
	double tau = 1e-6;
	double trapezoidal_sol = trapezoidal(f, a, b, tau);
	double simpson_sol = simpson(f, a, b, tau);
	cout << "exact solution : " << exact_solution << endl;
	cout << "trapezoidal solution :" << trapezoidal_sol << endl;
	cout << "simpson solution :" << simpson_sol << endl;
	double tr_err, simp_err;

	ofstream trap_data("trap_data.txt");
	ofstream simp_data("simp_data.txt");
	for (double tau = 1; tau > 1e-7; tau /= 2)
	{
		tr_err = abs(exact_solution - trapezoidal(f, a, b, tau));
		simp_err = abs(exact_solution -  simpson(f, a, b, tau));
		trap_data << log10(tau) << " " << log10(tr_err) << endl;
		simp_data << log10(tau) << " " << log10(simp_err) << endl;	
	}
}