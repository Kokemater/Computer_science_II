#include "funcs.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double z_anal(double x) {
    return (4.0 / 77.0) * exp(-x / 2.0) * (7.0 - 7.0 * exp(x) * cos(sqrt(7.0 * x) / 2.0) + 2.0 * sqrt(7.0) * exp(x) * sin(sqrt(7.0 * x) / 2.0));
}

double z_prime(double x) {
    return (2.0 / 77.0) * exp(-x / 2.0) * (-7.0 + 7.0 * exp(x) * cos(sqrt(7.0 * x) / 2.0) + 9.0 * sqrt(7.0) * exp(x) * sin(sqrt(7.0 * x) / 2.0));
}

// Funciones para las derivadas
double z1_prime(matrix <double> cond_iniciales, double x) {
    return cond_iniciales(1,0);
}

double z2_prime(matrix <double> cond_iniciales, double x) {
    return cond_iniciales(1,0) - 2 * cond_iniciales(0,0) + exp(-x / 2);
}

matrix<double> Z_prime_funcs(matrix <double> cond_iniciales, double x) {
    int order = cond_iniciales.RowNo();
    matrix<double> Z_prime(order, 1);

    // Calculamos las derivadas para cada orden
    Z_prime(0, 0) = z1_prime(cond_iniciales, x); // Primera derivada
    Z_prime(1, 0) = z2_prime(cond_iniciales, x); // Segunda derivada

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

	int order = 2;
	double x0 = 0.0;

    matrix <double> cond_iniciales(order, 1);
    matrix <double> Z_prime(order, 1);
	
	// Condiciones iniciales
    cond_iniciales(0, 0) = 0.0; // z(x0) 
    cond_iniciales(1, 0) = 0.0; // z'(x0)


    // Variables iniciales
    double h;
    cout << "Valor de h: ";
    cin >> h;  // Tamaño del paso

    int i = 0;
	bool euler_method = false;
	if (euler_method)
	{
		ofstream euler("euler01.txt");

		while(x0 < 3) 
		{
			euler_one_step(x0, cond_iniciales, h);
			euler << x0 << " " << cond_iniciales(0, 0) << " " << cond_iniciales(1, 0) << endl;
		}
	}
	bool rk2_method = false;
	if (rk2_method)
	{
	ofstream rk2("rk_20001.txt");
    // Bucle para realizar los pasos de Runge-Kutta 2
    while (x0 < 3) // El bucle se detendrá cuando x0 llegue a 3
    {
        runge_kutta_2(x0, cond_iniciales, h);  // Realizamos un paso de RK2
        rk2 << x0 << " " << cond_iniciales(0, 0) << " " << cond_iniciales(1, 0) << endl; // Escribimos los resultados	
    }
	}

	bool rk4_method = false;
	if (rk4_method)
	{
    ofstream rk4("rk_40001.txt");

    // Bucle para realizar los pasos de Runge-Kutta 4
    while (x0 < 3) // El bucle se detendrá cuando x0 llegue a 3
    {
        runge_kutta_4(x0, cond_iniciales, h);  // Realizamos un paso de RK4
        rk4 << x0 << " " << cond_iniciales(0, 0) << " " << cond_iniciales(1, 0) << endl; // Escribimos los resultados
    }
	}

    return 0;
}
