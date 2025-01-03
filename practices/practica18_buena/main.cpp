#include "funcs.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double F_0 = 1;
double m = 1;
double k = 1;
double w_0 = sqrt(k/m);
double w = 1;


// Funciones para las derivadas
double z1_prime(matrix <double> cond_in, double t) {
    return cond_in(1,0);
}
double z2_prime(matrix <double> cond_in, double t) {
    return F_0/m * cos(w*t) - 2*w_0*w_0 * cond_in(0,0) + w_0*w_0*cond_in(2,0);
}
double z3_prime(matrix <double> cond_in, double t) {
    return cond_in(3,0);
}
double z4_prime(matrix <double> cond_in, double t) {
    return w_0 * w_0 * cond_in(0,0) -2 *w_0 * w_0 * cond_in(2,0) + w_0 * w_0 * cond_in(4,0);
}
double z5_prime(matrix <double> cond_in, double t) {
    return cond_in(5,0);
}
double z6_prime(matrix <double> cond_in, double t) {
    return w_0* w_0 * cond_in(2,0) - 2* w_0 * w_0 * cond_in(4,0);
}
 
matrix<double> Z_prime_funcs(matrix <double> cond_iniciales, double x) {
    int order = cond_iniciales.RowNo();
    matrix<double> Z_prime(order, 1);

    // Calculamos las derivadas para cada orden
    Z_prime(0, 0) = z1_prime(cond_iniciales, x); // Primera derivada
    Z_prime(1, 0) = z2_prime(cond_iniciales, x); // Segunda derivada
    Z_prime(2, 0) = z3_prime(cond_iniciales, x); // Segunda derivada
    Z_prime(3, 0) = z4_prime(cond_iniciales, x); // Segunda derivada
    Z_prime(4, 0) = z5_prime(cond_iniciales, x); // Segunda derivada
    Z_prime(5, 0) = z6_prime(cond_iniciales, x); // Segunda derivada

    return Z_prime;
}

// Método de Euler para un paso
void euler_one_step(double& x, matrix<double>& cond_iniciales, double h) {
    int order = cond_iniciales.RowNo();

    matrix<double> Z_prime = Z_prime_funcs(cond_iniciales, x);

    // Actualizamos las variables dependientes con el método de Euler
    for (int i = 0; i < order; i++) {
        cond_iniciales(i, 0) += h * Z_prime(i, 0); // z_i_new = z_i + h * z_i'
    }
    // Avanzamos x un paso
    x += h;
}
// Método de Runge-Kutta 2º orden (RK2)
void runge_kutta_2(double& x, matrix<double>& cond_iniciales, double h) {
    int order = cond_iniciales.RowNo();

    matrix<double> k1(order, 1);
    matrix<double> k2(order, 1);

    // Calculamos k1 en el punto actual
    k1 = Z_prime_funcs(cond_iniciales, x);

    // Calculamos las condiciones intermedias usando k1
    matrix<double> cond_intermedias = cond_iniciales;
    for (int i = 0; i < order; i++) {
        cond_intermedias(i, 0) += h * k1(i, 0);
    }

    // Calculamos k2 en el punto intermedio
    k2 = Z_prime_funcs(cond_intermedias, x + h);

    // Actualizamos las condiciones iniciales usando el promedio de k1 y k2
    for (int i = 0; i < order; i++) {
        cond_iniciales(i, 0) += h * (k1(i, 0) + k2(i, 0)) / 2.0;
    }

    // Avanzamos x un paso
    x += h;
}

// Método de Runge-Kutta 4º orden (RK4)
void runge_kutta_4(double& x, matrix<double>& cond_iniciales, double h) {
    int order = cond_iniciales.RowNo();

    matrix<double> k1(order, 1);
    matrix<double> k2(order, 1);
    matrix<double> k3(order, 1);
    matrix<double> k4(order, 1);

    // Calculamos k1 en el punto actual
    k1 = Z_prime_funcs(cond_iniciales, x);

    // Calculamos las condiciones intermedias usando k1 para k2
    matrix<double> cond_intermedias = cond_iniciales;
    for (int i = 0; i < order; i++) {
        cond_intermedias(i, 0) += 0.5 * h * k1(i, 0);
    }
    k2 = Z_prime_funcs(cond_intermedias, x + 0.5 * h);

    // Calculamos las condiciones intermedias usando k2 para k3
    cond_intermedias = cond_iniciales;
    for (int i = 0; i < order; i++) {
        cond_intermedias(i, 0) += 0.5 * h * k2(i, 0);
    }
    k3 = Z_prime_funcs(cond_intermedias, x + 0.5 * h);

    // Calculamos las condiciones intermedias usando k3 para k4
    cond_intermedias = cond_iniciales;
    for (int i = 0; i < order; i++) {
        cond_intermedias(i, 0) += h * k3(i, 0);
    }
    k4 = Z_prime_funcs(cond_intermedias, x + h);

    // Actualizamos las condiciones iniciales usando una combinación ponderada de k1, k2, k3 y k4
    for (int i = 0; i < order; i++) {
        cond_iniciales(i, 0) += (h / 6.0) * (k1(i, 0) + 2 * k2(i, 0) + 2 * k3(i, 0) + k4(i, 0));
    }

    // Avanzamos x un paso
    x += h;
}

double error(double analitico, double numerico)
{
	return (abs(analitico - numerico));
}


int main()
{

	int order = 6;
	double x0 = 0.0;

    matrix <double> cond_iniciales(order, 1);
    matrix <double> Z_prime(order, 1);
	
	// Condiciones iniciales
    cond_iniciales(0, 0) = 0.0; // z(x0) 
    cond_iniciales(1, 0) = 0.0; // z'(x0)
    cond_iniciales(2, 0) = 0.0; // z'(x0)
    cond_iniciales(3, 0) = 0.0; // z'(x0)
    cond_iniciales(4, 0) = 0.0; // z'(x0)
    cond_iniciales(5, 0) = 0.0; // z'(x0)

    // Variables iniciales
	double h = 0.01;

    int i = 0;
	
	bool rk4_method = true;
	if (rk4_method)
	{
    ofstream rk4("rk_4w1.txt");

    while (x0 < 100) // El bucle se detendrá cuando x0 llegue a 3
    {
        runge_kutta_4(x0, cond_iniciales, h);  // Realizamos un paso de RK4
        rk4 << x0 << " " << cond_iniciales(0, 0) << " " << cond_iniciales(1, 0) << " " << cond_iniciales(2,0) << " " << cond_iniciales (3,0) << " " << cond_iniciales(4,0)<< " " << cond_iniciales (5,0) << endl; // Escribimos los resultados
    }
	}

    return 0;
}
