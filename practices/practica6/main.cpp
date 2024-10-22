#include "find_roots.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;



double f(double x)
{
	return pow(x,2) - 5*sin(2*M_PI*x)*cos(4*x);
}
double f_frime(double x)
{
	return 2*x -10*M_PI*cos(2*M_PI*x)*cos(4*x) + 20*sin(2*M_PI*x)*sin(4*x);
}

int main(void)
{
	double x_0_bis, x_0_newt, x_0_sec;
	double n_iter_bisec, n_iter_newton, n_iter_sec;

    double estimations_for_bisection[6][2] = {
        {-0.5, -0.42}, 
        {-0.42, -0.32}, 
        {-0.1, 0.1}, 
        {0.3, 0.4},
		{0.5, 0.6},
		{0.8, 1.0}
    };
	double estimation_for_sec[6][2] = {
        {-0.5, -0.51}, 
        {-0.42, -0.41}, 
        {-0.1, -0.09}, 
        {0.3, 0.31},
		{0.5, 0.51},
		{0.8, 0.81}
    };
	double estimation_for_newton[6] =
	{
		 -0.5, -0.42, -0.1, 0.3, 0.45, 0.8
	};

    ofstream outfile("roots.txt");

    if (!outfile) {
        cout << "Error al abrir el archivo roots.txt" << endl;
        return -1;
    }

    for (double precision = 1e-6; precision >= 1e-12; precision = precision * 1e-5)
    {
        outfile << "------------- PRECISIÓN ---------- " << precision << " -----------\n";
        cout << "PRECISIÓN = " << precision << endl;
        double cifras = abs(log10(precision));
        cout << setprecision(cifras);
        outfile << fixed << setprecision(cifras);

        outfile << "BISECTION:\n";
        cout << "BISECTION:" << endl;
        for (int i = 0; i < 6; i++)
        {
            x_0_bis = biseccion(f, estimations_for_bisection[i][0], estimations_for_bisection[i][1], precision, n_iter_bisec);
            cout << "x_0_bis = " << x_0_bis << " ||  n_iters = " << n_iter_bisec << endl;
            outfile << "x_0_bis = " << x_0_bis << " || n_iters = " << n_iter_bisec << "\n";
        }

        outfile << "NEWTON:\n";
        cout << "NEWTON:" << endl;
        for (int i = 0; i < 6; i++)
        {
            x_0_newt = newton(f, f_frime, estimation_for_newton[i], precision, n_iter_newton);
            cout << "x_0_new = " << x_0_newt << " || n_iters = " << n_iter_newton << endl;
            outfile << "x_0_new = " << x_0_newt << " || n_iters = " << n_iter_newton << "\n";
        }

        outfile << "SECANT:\n";
        cout << "SECANT: " << endl;
        for (int i = 0; i < 6; i++)
        {
            x_0_sec = secante(f, estimation_for_sec[i][0], estimation_for_sec[i][1], precision, n_iter_sec);
            cout << "x_0_sec = " << x_0_sec << " || n_iters = " << n_iter_sec << endl;
            outfile << "x_0_sec = " << x_0_sec << " || n_iters = " << n_iter_sec << "\n";
        }

        outfile << "\n";
    }

    // Cerrar el archivo después de terminar de escribir los datos
    outfile.close();
    cout << "Resultados guardados en roots.txt" << endl;

    return 0;

}