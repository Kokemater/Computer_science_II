#include <iostream>

using namespace std;

double bisection_root(double (*f)(double), double beg, double end)
{
	int n_iterations = 1000;
	double mid;
	for (int i = 0; i < n_iterations; i++)
	{
		mid = (beg + end)/2;
		if (f(mid) == 0)
			break;
		if (f(beg) * f(mid) < 0)
			end = mid;
		else
			beg = mid;
	}
	return mid;
}

double func(double x)
{
	return x + 1;
}
int main(void)
{
	double root =bisection_root(func, -10,10);
	cout << root << endl;
}