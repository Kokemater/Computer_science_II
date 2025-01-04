#include "funcs.h"

long double f(long double x)
{
	return (3*M_PI*M_PI - 6*M_PI*x + M_PI*M_PI*x + 3*x*x - 2*M_PI*x*x + x*x*x);
}

long double f_prime(long double x)
{
	return (-6*M_PI + M_PI*M_PI + 6*x - 4*M_PI*x + 3*x*x);
}

long double f_prime_prime(long double x)
{
	return (6 - 4*M_PI + 6*x);
}
long double u(long double x)
{
	return (f(x)/f_prime(x));
}

long double u_prime(long double x)
{
	return ((f_prime(x)*f_prime(x) - f(x)*f_prime_prime(x))/(f_prime(x)*f_prime(x)));
}

int main(void)
{
	cout << fixed << setprecision(7);

	//////////////// Ejercicio (1) /////////////////////
	long double eps = 1e-7;
	long double n_iterations_newton = 0;
	long double n_iterations_secant = 0;
	long double n_iterations_bisection = 0;

	// Apartado (a)
	long double a_n = 0;
	long double newton_x = newton(f, f_prime, a_n, eps, n_iterations_newton);

	cout << "Apartado (a): Se necesitan " << n_iterations_newton << " para encontrar una raíz" << endl;
	cout << "La raíz es x= " << newton_x << endl; 
	cout << "-----------------------" << endl << endl;
	// Apartado (b)
	cout << "Apartado (b) : Depende de qué raíz busquemos. " << endl <<
	 "Al ver la gráfica generada por gnuplot, visualmente podemos comprobar que existe un valor a de la función f(x) tal que f(a)<0 y otro valor b tal que f(b) > 0 y puesto que la función es continua, por el teorema del valor intermedio entonces podemos garantizar que existe una raíz en ese intervalo y la función converge. Esto sucede por ejemplo para el intervalo [-4, 0]"
	 << endl <<" Pero sin embargo, la raíz obtenida por el método de Newton nunca la podremos alcanzar a partir del método de bisección puesto que por ejemplo para un intervalo como [0, 5], los valores de f(0) > 0 y f(5) > 0, esto ocurre con cualquier intervalo que veamos ya que la raíz es un mínimo local" << endl;
	cout << "-----------------------" << endl << endl;

	// Apartado (c) 
	a_n = 0;
	n_iterations_newton = 0;
	newton_x = newton(u, u_prime, a_n, eps, n_iterations_newton);
	cout << "La raíz es x= " << newton_x << endl; 
	cout << "-----------------------" << endl << endl;

	// Apartado (d)
	long double a_b = 0;
	long double b_b = 5;
	long double biseccion_x = biseccion(u, a_b, b_b, eps, n_iterations_bisection);
	cout << "Apartado (c): Se necesitan " << n_iterations_bisection << " para encontrar una raíz" << endl;
	cout << "La raíz es x= " << biseccion_x << endl; 

	cout << "-----------------------" << endl << endl;
	cout << endl << endl << endl << endl;

	return (0);
}