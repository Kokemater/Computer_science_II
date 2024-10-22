double my_integral(double (*func)(double), double a, double b, double h)
{
	double total_area = 0;
	for (double x = a; x < b; x++)
	{
	total_area += h * (func(x) + func(x+h))/2;
	}
	return total_area;
}