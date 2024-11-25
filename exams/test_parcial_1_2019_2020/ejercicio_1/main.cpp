#include "funcs.h"

double potential(double r)
{
	double sigma = 1e-9;
	double V0 = 1;
	return (V0 * (pow(sigma/r, 6) -exp(-r/sigma)));
}

double potential_deriv(double r)
{
	double sigma = 1e-9;
	double V0 = 1;

	return (V0*(-6*pow(sigma,6)/pow(r,7) + 1/sigma * exp(-r/sigma)));
}

int main(void)
{

	//////////////// Ejercicio (1) /////////////////////
	double eps = 1e-10;
	double n_iterations_newton = 0;
	double n_iterations_secant = 0;
	double n_iterations_bisection = 0;

	double a_n = 1e-9;
	double newton_x = newton(potential, potential_deriv, a_n, eps, n_iterations_newton);

	double a_s = 1e-9;
	double b_s = 1.05e-9;
	double secante_x = secante(potential, a_s, b_s, eps, n_iterations_secant);

	double a_b = 1e-9;
	double b_b = 2e-9;
	double biseccion_x = biseccion(potential, a_b, b_b, eps, n_iterations_bisection);

	cout << "newton : " << newton_x << endl;
	cout << "secant : " << secante_x << endl;
	cout << "bisection " << biseccion_x << endl;

	for (double eps = 1e-3; eps > 1e-12; eps *= 0.1)
	{
		double newton_x = newton(potential, potential_deriv, a_n, eps, n_iterations_newton);
		double biseccion_x = biseccion(potential, a_b, b_b, eps, n_iterations_bisection);
		double secante_x = secante(potential, a_s, b_s, eps, n_iterations_secant);
	cout << "PRECISSION " << eps << endl;
	cout << "newton_iterations : " << n_iterations_newton << endl;
	cout << "secant_iterations : " << n_iterations_secant << endl;
	cout << "bisection_iterations : " << n_iterations_bisection << endl;
	}

	cout << endl << endl << endl << endl;

	return (0);
}