#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "funcs.h"

// Definición de funciones
double f(double x, double y) {
    return (2 * x * x * x + 10 * x * x - 8 * y * y + x * y + 1);
}

double g(double x, double y) {
    return (x * x + y * y - 3 * y - 1);
}

double fx(double x, double y) {
    return (6 * x * x + 20 * x + y);
}

double fy(double x, double y) {
    return (-16 * y + x);
}

double gx(double x, double y) {
    return (2 * x);
}

double gy(double x, double y) {
    return (2 * y - 3);
}

// Evaluar función en (0, 0)
double evaluate_in_cero(double (*func)(double, double)) {
    return func(0,0); // Evalúa la función en 0
}

void newton(matrix < double(*)(double, double)> funciones, matrix < double(*)(double, double)> jacobiano, matrix <double> x1, double eps, double &n_iterations_newton, matrix <double> &solution)
{
	matrix <double> x_prev(2,1);
	matrix <double> x_next(2,1);
	matrix <double> F(2,1);
	matrix <double> J(2,2);
	matrix <double> dist(2,1);
	x_prev = x1;
	n_iterations_newton = 0;
	while(true)
	{
		for (int i = 0; i < 2; i++)
		{
			F(i,0) = funciones(i,0)(x_prev(0,0), x_prev(1,0));
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				J(i,j) = jacobiano(i,j)(x_prev(0,0), x_prev(1,0));
			}
		}
		n_iterations_newton++;
		x_next = x_prev - !J * F;
		dist = x_prev - x_next;
		if (dist.Norm(1) <= eps)
		{
			solution = x_next;
			return ;
		}

		x_prev = x_next;
	}
}


void Broyden(matrix <double (*)(double, double)> funciones, matrix <double> x1, matrix <double> x2, matrix <double> A_0, double eps, double &n_iterations_sec, matrix <double> &solution)
{
	matrix <double> x_prev(2,1), x_curr(2,1), x_next(2,1), s(2,1);
	matrix <double> F_curr(2,1), F_prev(2,1);
	matrix <double> A(2,2);
	matrix <double> A_prev(2,2);
	x_prev = x1;
	x_curr = x2;
	A_prev = A_0;

	n_iterations_sec = 0;
	while(true)
	{

		s = x_curr - x_prev;
		for(int i = 0; i < 2; i++)
		{
			F_curr(i, 0) = funciones(i,0)(x_curr(0,0), x_curr(1,0)); 
		}

		for(int i = 0; i < 2; i++)
		{
			F_prev(i,0) = funciones(i,0) (x_prev(0,0), x_prev(1,0));
		}
		A = A_prev + ((F_curr - F_prev - A_prev * s)/(~s*s ))* ~s;
		x_next = x_curr - !A * F_curr;
		n_iterations_sec++;
		if (s.Norm(1) <= eps)
		{
			solution = x_next;
			return ;
		}
		x_prev = x_curr;
		x_curr = x_next;
		A_prev = A;
	}
}

int main() {

    matrix <double (*)(double,double)> funciones = {
		{f},
		{g},
	};
	// For Newton
    matrix <double (*)(double,double)> Jacobiano = {
		{fx,fy},
		{gx, gy},
	};
	matrix <double> x1 = {{-1},{1}};
	matrix <double> x2 = {{2},{2}};
	matrix <double> solution1(2,1), solution2(2,1);
	// For Broyden
	matrix <double> sol_broyden1(2,1), sol_broyden2(2,1);
	matrix <double> A_0 = {{1,0},{0,1}};
	matrix <double> x1br_1 = {{-1},{1}};
	matrix <double> x2br_1 = {{-1.8},{1.5}};
	matrix <double> x1br_2 = {{1},{2}};
	matrix <double> x2br_2 = {{1.5},{2.3}};
	double n_iterations_newton1, n_iterations_newton2, n_iter_broyden1, n_iter_broyden2;

	// Precission
	double precission = 1e-8;
	cout << "PRECISIÓN = " << precission << endl;
    double cifras = abs(log10(precission));
    cout << setprecision(cifras);

	newton(funciones, Jacobiano, x1, precission, n_iterations_newton1, solution1);
	newton(funciones, Jacobiano, x2, precission, n_iterations_newton2, solution2);

	cout << "Solución 1 (Newton) : " <<endl;
	cout << "N_iterations : "<< n_iterations_newton1 <<endl;
	cout << solution1 <<endl;

	cout << "Solución 2 : (Newton) " <<endl;
	cout << "N_iterations : "<< n_iterations_newton2 <<endl;
	cout << solution2 <<endl;
	
	Broyden(funciones, x1br_1, x2br_1, A_0, precission, n_iter_broyden1, sol_broyden1);
	Broyden(funciones, x1br_2, x2br_2, A_0, precission, n_iter_broyden2, sol_broyden2);

	cout << "Solución 1 (Broyden) : " <<endl;
	cout << "N_iterations : " << n_iter_broyden1 <<endl;
	cout << sol_broyden1 <<endl;

	cout << "Solución 2 (Broyden) : " <<endl;
	cout << "N_iterations : " << n_iter_broyden2 <<endl;
	cout << sol_broyden2 <<endl;
	

    return 0;
}
