#include "funcs.h"

double f(double x)
{
	double i = x*x - x + 1;
	double h = cos(i);
	double g = sin(h);
	return (exp(g));
}

double f_prime(double x)
{
	double i = x*x - x + 1;
	double h = cos(i);
	double g = sin(h);
	double f = exp(g);
	return (f * cos(h) * (-sin(i)) * (2*x -1));
}

double diferencia_centrada_1(double (*f) (double), double x, double h)
{
	return ((f(x + h) - f(x-h))/(2*h));
}

double S(double (*f)(double), double x, double h)
{
	double num = 8*f(x+h) - 8*f(x-h) + f(x-2*h) - f(x+2*h);
	double den = 12 *h;
	return (num/den);
}

double H(double (*f)(double), double x, double h)
{
	return ((16*S(f,x,h) - S(f,x,2*h))/15);
}

int main(void)
{
	double x = -1.0;
	double anal_solution = f_prime(x);
	double error;
	cout << anal_solution << endl;
	ofstream error_1("error_1.txt");
	ofstream error_2("error_2.txt");
	ofstream error_3("error_3.txt");

	for(double h = 1e-5; h < 1e-1; h*=2)
	{
		double deriv_1 = diferencia_centrada_1(f,x, h);
		error = abs(deriv_1 - anal_solution);
		error_1 << log10(h) << " "<< log10(error) << endl;
	}

	for(double h = 1e-5; h < 1e-1; h*=2)
	{
		double deriv_2 = S(f,x, h);
		error = abs(deriv_2 - anal_solution);
		error_2 << log10(h) << " "<< log10(error) << endl;
	}

	for(double h = 1e-5; h < 1e-1; h*=2)
	{
		double deriv_3 = H(f,x, h);
		error = abs(deriv_3 - anal_solution);
		error_3 << log10(h) << " " << log10(error) << endl;
	}

	// Qué sucede cuándo usamos h = 1e-20
	double h = 1e-20;
	double deriv_1 = diferencia_centrada_1(f,x, h);
	double deriv_2 = S(f,x, h);
	double deriv_3 = H(f,x, h);

	double error1 = abs(deriv_1 - anal_solution);
	double error2 = abs(deriv_2 - anal_solution);
	double error3 = abs(deriv_3 - anal_solution);

	ofstream error_12("error_12.txt");
	ofstream error_22("error_22.txt");
	ofstream error_32("error_32.txt");
	cout << error1 << " " << error2 << " " << error3 << endl;

		for(double h = 1e-20; h < 1e-1; h*=2)
	{
		double deriv_1 = diferencia_centrada_1(f,x, h);
		error = abs(deriv_1 - anal_solution);
		error_12 << log10(h) << " "<< log10(error) << endl;
	}

	for(double h = 1e-20; h < 1e-1; h*=2)
	{
		double deriv_2 = S(f,x, h);
		error = abs(deriv_2 - anal_solution);
		error_22 << log10(h) << " "<< log10(error) << endl;
	}

	for(double h = 1e-20; h < 1e-1; h*=2)
	{
		double deriv_3 = H(f,x, h);
		error = abs(deriv_3 - anal_solution);
		error_32 << log10(h) << " " << log10(error) << endl;
	}

}