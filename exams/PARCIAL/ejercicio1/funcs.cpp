#include "funcs.h"



long double biseccion(long double (*f)(long double), long double a, long double b, long double eps, long double &n_iterations) {
    n_iterations = 0;
    long double x_med;
	if (f(a) * f(b) > 0)
	{
		cout << "f(a) y f(b) tienen el mismo signo." << endl;
		return (-1);
	}
    while (b - a > eps)
	{
        x_med = (a + b) / 2.0;
        n_iterations++;
        if (f(a) * f(x_med) < 0)
            b = x_med; 
        else
            a = x_med;
    }
    return (a + b) / 2.0; 
}
long double secante(long double (*f) (long double), long double x1, long double x2, long double eps, long double &n_iterations_sec)
{
	long double x_prev = x1;
	long double x_curr = x2;
	long double x_next;

	n_iterations_sec = 0;
	while(true)
	{
	
		n_iterations_sec++;

        x_next = x_curr - f(x_curr) * (x_curr - x_prev) / (f(x_curr) - f(x_prev));
		if (abs(x_next - x_prev) <= eps)
			return x_next;
		x_prev = x_curr;
		x_curr = x_next;
	}
}

long double newton(long double (*f)(long double), long double (*f_prime)(long double), long double x1, long double eps, long double &n_iterations_newton)
{
	long double x_prev = x1;
	long double x_next;

	n_iterations_newton = 0;
	while(true)
	{
		if (f_prime(x_prev) == 0)
        {
            cout << "Error: La derivada se anuló en x = " << x_prev << ". Método fallido." << endl;
            return NAN;  
        }
		n_iterations_newton++;

		x_next = x_prev - f(x_prev)/f_prime(x_prev);
		if (abs(x_next - x_prev) <= eps)
			return x_next;
		x_prev = x_next;
	}
}