#include "funcs.h"

double potential(double r)
{
    double r0 = 1.5e-15;
    double V0 = 50;
    return (-V0 * r0 / r) * exp(-r / r0);
}

double force(double r)
{
    double r0 = 1.5e-15;
    double V0 = 50;
    return ((-V0 * r0) * (pow(r0, 2) / pow(r, 2) + r0 / r) * exp(-r / r0));
}

double f(double x)
{
    double r0 = 1.5e-15;
    double r = x * r0;  // Cambio de variable x = r/r0
    return (force(r0*x) - 0.01 * force(r0));  // 0.01 * fuerza en r0
}

double f_prime(double x)
{
	double r0 = 1.5e-15;
    double V0 = 50;
	return (-V0*r0*(-1/x*x - 2/pow(x,3))*exp(-x) + V0*r0*(1/x + pow(x,-2))*exp(-x));
}

int main(void)
{
    ////////////////// Ejercicio (1) /////////////////////

    double eps = 1e-5;
    double n_iterations_newton = 0;
    double n_iterations_secant = 0;
    double n_iterations_bisection = 0;

    double a_n = 3.5;  // Punto inicial para Newton (a_n = 3.5)
    // Newton: Se necesitaría la derivada de la fuerza, potencial, o su función derivada
    double newton_x = newton(f, f_prime, a_n, eps, n_iterations_newton); // Debes definir f_prime

    double a_s = 3.4;  // Punto inicial para Secante (cercano a 3.5)
    double b_s = 3.6;  // Punto final para Secante
    double secante_x = secante(f, a_s, b_s, eps, n_iterations_secant);

    double a_b = 3.4;  // Punto inicial para Bisección
    double b_b = 3.6;  // Punto final para Bisección
    double biseccion_x = biseccion(f, a_b, b_b, eps, n_iterations_bisection);

    cout << "newton: " << newton_x << " " << n_iterations_newton << endl;
    cout << "secant: " << secante_x << " " << n_iterations_secant << endl;
    cout << "bisection: " << biseccion_x << " " << n_iterations_bisection << endl;
	ofstream n_iter("n_iter.txt");
    for (double eps = 1e-3; eps > 1e-12; eps *= 0.1)
    {
        double newton_x = newton(f, f_prime, a_n, eps, n_iterations_newton);
        double biseccion_x = biseccion(f, a_b, b_b, eps, n_iterations_bisection);
        double secante_x = secante(f, a_s, b_s, eps, n_iterations_secant);
        cout << "PRECISION " << eps << endl;
		n_iter << eps << " " << n_iterations_newton << " " << n_iterations_secant << " " << n_iterations_bisection << endl;
    }


    return 0;
}
