#include "funcs.h"

double f(double x)
{
	return (x*(x + 5) + 3 - exp(x));
}
double f_prime(double x)
{
	return ((x + 5) + x - exp(x));
}
int main(void)
{
	double eps = 1e-5;
	double a = 4;
	double b = 0.1;
	double c = -5;
	double n_iter_newton = 0;
	double x1 = newton(f, f_prime, a, eps, n_iter_newton);
	double x2 = newton(f, f_prime, b, eps, n_iter_newton);
	double x3 = newton(f, f_prime, c, eps, n_iter_newton);

	
	cout << "x_1 : " << x1 << " n_iter : " << n_iter_newton << endl;
	cout << "x_2 : " << x2 << " n_iter : " << n_iter_newton << endl;
	cout << "x_3 : " << x3 << " n_iter : " << n_iter_newton << endl;

	ofstream data("data.txt");
	data << "point    n_iterations    result" << endl;
	for (double point = -5.0; point <= 5.0; point += 0.1)
	{
		cout << "sdf" <<endl;
		x1 = newton(f, f_prime, point, eps, n_iter_newton);
		data << point << "    " << n_iter_newton << "     " << x1 << endl;
	}
}