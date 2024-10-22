#include <iostream>
#include <cmath>

using namespace std;

double integrate(double(*f)(double), double start, double end)
{
	int n = 100000;
	double total = 0;
	double step_size = (end - start)/n;
	for (int i = 0; i < n; i++)
	{
		total += f(start + i*step_size);
	}
	return total * step_size;
}
double f(double x)
{
	return 3*sin(x);
}
double f_integral(double x)
{
	return - 3 * cos(x);
}
int main(void)
{
	double result = integrate(f, 0, M_PI/2);
	cout << result << "==" << f_integral(M_PI/2) - f_integral(0) << endl;
}