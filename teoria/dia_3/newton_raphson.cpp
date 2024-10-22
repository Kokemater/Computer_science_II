#include <iostream>

double newton_raphson(double (*f)(double), double (*f_prime) (double), double x_0, double tolerancia= 1e-6, double max_iter = 1000)
{
	double x_1;
	for (int i = 0; i < max_iter; i++)
	{
		double f_val = f(x_0);
		double f_prime_val = f_prime(x_0);
		x_1 = x_0 - f_val / f_prime_val;
		if (x_1 - x_0 < tolerancia )
			break;
		if (x_1 == 0)
			break;
	}
	return x_1;
}
double f(double x)
{
	return x + 1;
}
double f_prime(double x)
{
	return 1;
}

int main(void)
{
	double root = newton_raphson(f, f_prime, -10);
	std::cout << root << std::endl;
}