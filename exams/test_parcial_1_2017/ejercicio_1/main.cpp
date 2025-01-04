#include "funcs.h"

// Definición de funciones
double f(double x, double y) {
    return (pow(x,3) + 6*pow(y,2) - 76);
}

double g(double x, double y) {
    return (8 * pow(x,3)*pow(y,2) + x*y - 1024);
}

double fx(double x, double y) {
    return (3*x*x);
}

double fy(double x, double y) {
    return (12*y);
}

double gx(double x, double y) {
    return (24*x*x*y*y + y);
}

double gy(double x, double y) {
    return (16*x*x*x*y + x);
}


int main() {

    matrix <double (*)(double,double)> funciones = {
		{f},
		{g},
	};
	// For Newton
    matrix <double (*)(double,double)> Jacobiano = {
		{fx, fy},
		{gx, gy},
	};
	ofstream n_iter_1("n_iter_1.txt");
	ofstream n_iter_2("n_iter_2.txt");

	matrix <double> x1(2,1), x2(2,1);
	matrix <double> solution1(2,1), solution2(2,1), solution3(2,1), solution4(2,1);
	double precission = 1e-11;
	double n_iter;

	x1 = {{0.1},{0.1}};
	for (precission = 1e-3; precission >= 1e-11; precission*=0.1)
	{
		newton_raphson_non_linear(funciones, Jacobiano, x1, precission, n_iter, solution1);
		n_iter_1 << precission << " " << n_iter << endl;
	}

	x1 = {{10},{-10}};
	for (precission = 1e-3; precission >= 1e-11; precission*=0.1)
	{
		newton_raphson_non_linear(funciones, Jacobiano, x1, precission, n_iter, solution2);
		n_iter_2 << precission << " " << n_iter << endl;
	}
	// Extra : Encontrar todas las soluciones al sistema:
	// Para esto :
	// (1) graficar y ver visualmente los puntos
	// (2) buscar vectores apropiados para encontrar el punto (que estén cerca básicamente)

    cout << fixed << setprecision(11);

	// Ya hemos encontrado 2 soluciones :
	cout << solution1 << endl;
	cout << solution2 << endl;

	// Las 2 que quedan :
	x1 = {{4}, {-2}};
	newton_raphson_non_linear(funciones, Jacobiano, x1, precission, n_iter, solution3);
	x1 = {{4}, {2}};

	newton_raphson_non_linear(funciones, Jacobiano, x1, precission, n_iter, solution4);

	cout << solution3 << endl;
	cout << solution4 << endl;

	// Extra : Encontrar una de las soluciones por broyden
	x1 = {{3.8},{1.8}};
	x2 = {{4}, {2}};
	matrix <double> A0 = {{1,0},{0,1}};
	Broyden_non_linear(funciones,x1,x2, A0, precission,n_iter, solution4);
	cout << "n_iter = " << n_iter << endl;
	cout << "sol = " << endl << solution4;


    return 0;
}
