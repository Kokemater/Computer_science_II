#include "funcs.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double z_anal(double x) {
    return (4.0 / 77.0) * exp(-x / 2.0) * (7.0 - 7.0 * exp(x) * cos(sqrt(7.0 * x) / 2.0) + 2.0 * sqrt(7.0) * exp(x) * sin(sqrt(7.0 * x) / 2.0));
}

// Derivada de z(x), es decir, z'(x)
double z_prime(double x) {
    return (2.0 / 77.0) * exp(-x / 2.0) * (-7.0 + 7.0 * exp(x) * cos(sqrt(7.0 * x) / 2.0) + 9.0 * sqrt(7.0) * exp(x) * sin(sqrt(7.0 * x) / 2.0));
}

// Funciones para las derivadas
double z1_prime(double z1, double z2, double x) {
    return z2;
}

double z2_prime(double z1, double z2, double x) {
    return z2 - 2 * z1 + exp(-x / 2);
}

// Método de Euler para un paso
void euler_one_step(matrix<double>& Z_prime, double& x, matrix<double>& cond_iniciales, double h) 
{
    // Extraemos las condiciones iniciales
    double z1 = cond_iniciales(0, 0);
    double z2 = cond_iniciales(1, 0);

    // Calculamos las derivadas
    Z_prime(0, 0) = z1_prime(z1, z2, x);
    Z_prime(1, 0) = z2_prime(z1, z2, x);

    // Actualizamos las variables dependientes con el método de Euler
    cond_iniciales(0, 0) += h * Z_prime(0, 0); // z1_new = z1 + h * z1'
    cond_iniciales(1, 0) += h * Z_prime(1, 0); // z2_new = z2 + h * z2'

    // Avanzamos x un paso
    x += h;

    // Imprimimos resultados
    std::cout << "Después de un paso:\n";
    std::cout << "x = " << x << "\n";
    std::cout << "z(x) = " << cond_iniciales(0, 0) << "\n";
    std::cout << "z'(x) = " << cond_iniciales(1, 0) << "\n";
}
// Método de Runge-Kutta 2º orden (RK2)
void runge_kutta_2(matrix<double>& Z_prime, double& x, matrix<double>& cond_iniciales, double h) 
{
    // Extraemos las condiciones iniciales
    double z1 = cond_iniciales(0, 0);
    double z2 = cond_iniciales(1, 0);

    // Calculamos la derivada en el punto (x_n, z_n)
    Z_prime(0, 0) = z1_prime(z1, z2, x);
    Z_prime(1, 0) = z2_prime(z1, z2, x);

    // Calculamos la derivada en el punto (x_n + h, z_n + h * k1)
    double z1_next = z1 + h * Z_prime(0, 0); 
    double z2_next = z2 + h * Z_prime(1, 0); 

    // Calculamos el valor de la derivada en el siguiente paso (k2)
    double k1_z1 = z1_prime(z1, z2, x);
    double k1_z2 = z2_prime(z1, z2, x);
    double k2_z1 = z1_prime(z1_next, z2_next, x + h);
    double k2_z2 = z2_prime(z1_next, z2_next, x + h);

    // Actualizamos las condiciones iniciales usando el promedio de los dos pasos
    cond_iniciales(0, 0) += h * (k1_z1 + k2_z1) / 2; // z1_new
    cond_iniciales(1, 0) += h * (k1_z2 + k2_z2) / 2; // z2_new

    // Avanzamos x un paso
    x += h;
}

// Método de Runge-Kutta 4º orden (RK4)
void runge_kutta_4(matrix<double>& Z_prime, double& x, matrix<double>& cond_iniciales, double h) 
{
    // Extraemos las condiciones iniciales
    double z1 = cond_iniciales(0, 0);
    double z2 = cond_iniciales(1, 0);

    // Calculamos k1
    double k1_z1 = z1_prime(z1, z2, x);
    double k1_z2 = z2_prime(z1, z2, x);

    // Calculamos k2
    double k2_z1 = z1_prime(z1 + 0.5 * h * k1_z1, z2 + 0.5 * h * k1_z2, x + 0.5 * h);
    double k2_z2 = z2_prime(z1 + 0.5 * h * k1_z1, z2 + 0.5 * h * k1_z2, x + 0.5 * h);

    // Calculamos k3
    double k3_z1 = z1_prime(z1 + 0.5 * h * k2_z1, z2 + 0.5 * h * k2_z2, x + 0.5 * h);
    double k3_z2 = z2_prime(z1 + 0.5 * h * k2_z1, z2 + 0.5 * h * k2_z2, x + 0.5 * h);

    // Calculamos k4
    double k4_z1 = z1_prime(z1 + h * k3_z1, z2 + h * k3_z2, x + h);
    double k4_z2 = z2_prime(z1 + h * k3_z1, z2 + h * k3_z2, x + h);

    // Actualizamos las condiciones iniciales usando una combinación ponderada de k1, k2, k3 y k4
    cond_iniciales(0, 0) += (h / 6.0) * (k1_z1 + 2 * k2_z1 + 2 * k3_z1 + k4_z1);
    cond_iniciales(1, 0) += (h / 6.0) * (k1_z2 + 2 * k2_z2 + 2 * k3_z2 + k4_z2);

    // Avanzamos x un paso
    x += h;
}

double error(double analitico, double numerico)
{
	return (abs(analitico - numerico));
}


int main() {
	
	double z_analitico, z_prime_analitico, z_numerico, z_prime_numerico;

    // Definimos las matrices
    matrix<double> Z_prime(2, 1);        // Almacena z1' y z2'
    matrix<double> cond_iniciales(2, 1); // Condiciones iniciales: z(0) y z'(0)

    // Inicializamos las condiciones iniciales
    cond_iniciales(0, 0) = 0.0; // z(0) = 0
    cond_iniciales(1, 0) = 0.0; // z'(0) = 0

    // Variables iniciales
    double x0 = 0.0; // x inicial
    double h;
    cout << "Valor de h: ";
    cin >> h;  // Tamaño del paso

    int i = 0;
	bool euler_method = true;
	if (euler_method)
	{
		//ofstream euler("euler01.txt");
		ofstream euler_error("euler_error0001.txt");
		// Bucle para realizar los pasos de Euler
		while(x0 < 3) // El bucle se detendrá cuando x0 llegue a 3
		{
			euler_one_step(Z_prime, x0, cond_iniciales, h);
			//euler << x0 << " " << cond_iniciales(0, 0) << " " << cond_iniciales(1, 0) << endl;
			z_analitico = z_anal(x0);
			z_prime_analitico = z_prime(x0);
			z_numerico = cond_iniciales(0, 0);
			z_prime_numerico = cond_iniciales(1,0);
			euler_error << x0 << " " << log10(error(z_analitico, z_numerico)) << " " << log10(error(z_prime_analitico, z_prime_numerico)) << endl;
		}
		euler_error.close();
	}
	bool rk2_method = false;
	if (rk2_method)
	{
	//ofstream rk2("rk_20001.txt");
	ofstream rk2_error("rk_2_error0001.txt");
    // Bucle para realizar los pasos de Runge-Kutta 2
    while (x0 < 3) // El bucle se detendrá cuando x0 llegue a 3
    {
        runge_kutta_2(Z_prime, x0, cond_iniciales, h);  // Realizamos un paso de RK2
        //rk2 << x0 << " " << cond_iniciales(0, 0) << " " << cond_iniciales(1, 0) << endl; // Escribimos los resultados
		z_analitico = z_anal(x0);
		z_prime_analitico = z_prime(x0);
		z_numerico = cond_iniciales(0, 0);
		z_prime_numerico = cond_iniciales(1,0);
		rk2_error << x0 << " " << log10(error(z_analitico, z_numerico)) << " " << log10(error(z_prime_analitico, z_prime_numerico)) << endl;
		
    }
    rk2_error.close(); // Cerrar el archivo de salida
	}

	bool rk4_method = false;
	if (rk4_method)
	{
    //ofstream rk4("rk_40001.txt");
	ofstream rk4_error("rk_4_error0001.txt");

    // Bucle para realizar los pasos de Runge-Kutta 4
    while (x0 < 3) // El bucle se detendrá cuando x0 llegue a 3
    {
        runge_kutta_4(Z_prime, x0, cond_iniciales, h);  // Realizamos un paso de RK4
        //rk4 << x0 << " " << cond_iniciales(0, 0) << " " << cond_iniciales(1, 0) << endl; // Escribimos los resultados
		z_analitico = z_anal(x0);
		z_prime_analitico = z_prime(x0);
		z_numerico = cond_iniciales(0, 0);
		z_prime_numerico = cond_iniciales(1,0);
		rk4_error << x0 << " " << log10(error(z_analitico, z_numerico)) << " " << log10(error(z_prime_analitico, z_prime_numerico)) << endl;
    }
    rk4_error.close(); // Cerrar el archivo de salida
	}

    return 0;
}
