#include <iostream>
#include <fstream> // Para manejar archivos
#include <iomanip> // Para las cifras significativas
#include "funcs.h"
using namespace std;

double square(double x) {
    return x * x;
}

double square_derivative(double x) {
    return 2 * x;
}


int main(void) {
    double x_min, x_max, dx;
	cin >> x_min;
	cin >> x_max;
	dx = 0.01;

    ofstream output_file("results.txt");
	output_file <<fixed << setprecision(6);
    cout << fixed << setprecision(6); 

	if (!output_file) {
        cerr << "Error al abrir el archivo." << endl;
        return 1; // Salida con error
    }

    for (double x = x_min; x < x_max; x += dx) {
		double sq = square(x);
        double deriv = square_derivative(x);
        double my_deriv = derivada(square, x, 0.000000001);
        // Imprime los resultados en consola
        cout << "x = " << x << " " << deriv << " | " << my_deriv << endl;
        // Guarda los resultados en el archivo
        output_file << x << " " << sq <<" "<< my_deriv << endl;
    }

    output_file.close();
    return 0;
}
