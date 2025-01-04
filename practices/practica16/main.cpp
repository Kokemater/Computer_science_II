#include <cmath>      
#include <fstream>     
#include <iostream>    
#include <limits>      // Para valores máximos y mínimos de tipos numéricos
using namespace std;

double f(double x) {
    return pow((pow(x, 2) + 1) / (3 * x - 1), 2);
}

double f_prime_prime(double x) {
    return (2 * (9 * pow(x, 4) - 12 * pow(x, 3) + 6 * pow(x, 2) + 12 * x + 29)) /
           (81 * pow(x, 4) - 108 * pow(x, 3) + 54 * pow(x, 2) - 12 * x + 1);
}

double f_prime_prime_prime(double x) {
    return -(240 * x + 720) /
           (243 * pow(x, 5) - 405 * pow(x, 4) + 270 * pow(x, 3) - 90 * pow(x, 2) + 15 * x - 1);
}

double diferencia_centrada_2(double (*f)(double), double x, double h) {
    return (f(x + h) - 2 * f(x) + f(x - h)) / pow(h, 2);
}

double diferencia_centrada_3(double (*f)(double), double x, double h) {
    return (f(x + 2 * h) - 2 * f(x + h) + 2 * f(x - h) - f(x - 2 * h)) / (2 * pow(h, 3));
}

double progresivas2(double (*f)(double), double x, double h) {
    return (f(x + 2 * h) - 2 * f(x + h) + f(x)) / pow(h, 2);
}

double progresivas3(double (*f)(double), double x, double h) {
    return (f(x + 3 * h) - 3 * f(x + 2 * h) + 3 * f(x + h) - f(x)) / pow(h, 3);
}

double regresivas2(double (*f)(double), double x, double h) {
    return (f(x) - 2 * f(x - h) + f(x - 2 * h)) / pow(h, 2);
}

double regresivas3(double (*f)(double), double x, double h) {
    return (f(x) - 3 * f(x - h) + 3 * f(x - 2 * h) - f(x - 3 * h)) / pow(h, 3);
}

double error_relativo(double dnumerica, double dteorica) {
    return fabs((dteorica - dnumerica) / dteorica);
}

int main(void) {
    double x = 1.0;
    double anal_solution_2 = f_prime_prime(x);
    double anal_solution_3 = f_prime_prime_prime(x);


	double h = 0.1;
	// Apartado (b)
	cout << "centrada2 : "<< error_relativo(diferencia_centrada_2(f, x, h),f_prime_prime(x)) << endl;
	cout << "centrada3 : "<< error_relativo(progresivas2(f, x, h),f_prime_prime(x))<< endl;
	cout << "progresiva2 : "<< error_relativo(regresivas2(f, x, h),f_prime_prime(x))<< endl;
	cout << "progresiva3 : "<< error_relativo(diferencia_centrada_3(f, x, h),f_prime_prime_prime(x))<< endl;
	cout << "regresiva2 : "<< error_relativo(progresivas3(f, x, h),f_prime_prime_prime(x))<< endl;
	cout << "regresiva3 : "<< error_relativo(regresivas3(f, x, h),f_prime_prime_prime(x))<< endl;

    ofstream error_diff_2("derivada2.txt");
    ofstream error_diff_3("derivada3.txt");

    // Variables para almacenar el mínimo error y su h correspondiente
    double min_err_cen_2 = numeric_limits<double>::max(), min_h_cen_2;
    double min_err_cen_3 = numeric_limits<double>::max(), min_h_cen_3;
    double min_err_prog_2 = numeric_limits<double>::max(), min_h_prog_2;
    double min_err_prog_3 = numeric_limits<double>::max(), min_h_prog_3;
    double min_err_reg_2 = numeric_limits<double>::max(), min_h_reg_2;
    double min_err_reg_3 = numeric_limits<double>::max(), min_h_reg_3;

    for (double h = 1e-1; h >= 1e-12; h *= 0.75) {
        // Derivadas
        double diff_cent_2 = diferencia_centrada_2(f, x, h);
        double prog_2 = progresivas2(f, x, h);
        double reg_2 = regresivas2(f, x, h);
        double diff_cent_3 = diferencia_centrada_3(f, x, h);
        double prog_3 = progresivas3(f, x, h);
        double reg_3 = regresivas3(f, x, h);

        // Errores relativos
        double err_cen_2 = error_relativo(diff_cent_2, anal_solution_2);
        double err_prog_2 = error_relativo(prog_2, anal_solution_2);
        double err_reg_2 = error_relativo(reg_2, anal_solution_2);
        double err_cen_3 = error_relativo(diff_cent_3, anal_solution_3);
        double err_prog_3 = error_relativo(prog_3, anal_solution_3);
        double err_reg_3 = error_relativo(reg_3, anal_solution_3);

        // Guardar errores en los archivos
        error_diff_2 << log10(h) << " " << log10(err_cen_2) << " " << log10(err_prog_2) << " " << log10(err_reg_2) << endl;
        error_diff_3 << log10(h) << " " << log10(err_cen_3) << " " << log10(err_prog_3) << " " << log10(err_reg_3) << endl;

        // Buscar mínimos
        if (err_cen_2 < min_err_cen_2) { min_err_cen_2 = err_cen_2; min_h_cen_2 = h; }
        if (err_cen_3 < min_err_cen_3) { min_err_cen_3 = err_cen_3; min_h_cen_3 = h; }
        if (err_prog_2 < min_err_prog_2) { min_err_prog_2 = err_prog_2; min_h_prog_2 = h; }
        if (err_prog_3 < min_err_prog_3) { min_err_prog_3 = err_prog_3; min_h_prog_3 = h; }
        if (err_reg_2 < min_err_reg_2) { min_err_reg_2 = err_reg_2; min_h_reg_2 = h; }
        if (err_reg_3 < min_err_reg_3) { min_err_reg_3 = err_reg_3; min_h_reg_3 = h; }
    }

	// Resultados de la interpolación
	double h_1 =(-10 - 0.66458) /2.04894; 
    double h_c_2 = pow(10, h_1);
    cout << "centradas 2 es:" << h_c_2 << endl;

    double h_min2 =(-10 - 0.394435) /0.911678;
    double h_p_2 = pow(10, h_min2);
    cout << "progresivas 2 es:" << h_p_2 << endl;

    double h_min3 =(-10 - 0.973532 ) /1.09715 ;
    double h_r_2 = pow(10, h_min3);
    cout << "regresivas 2 es:" << h_r_2 << endl;


    double h_min4 =(-10 - 0.67351) /1.81613;
    double h_c_3 = pow(10, h_min4);
    cout << "centradas 3 es:" << h_c_3 << endl;

    double h_min5 =(-10 - 0.423832 ) /0.793905; 
    double h_p_3 = pow(10, h_min5);
    cout << "progresivas 3 es:" << h_p_3 << endl;

    double h_min6 =(-10 - 1.78327 ) /1.1941  ; 
    double h_r_3 = pow(10, h_min6);
    cout << "regresivas 3 es:" <<h_r_3<<endl;

    // Imprimir mínimos encontrados
    cout << "Minimos encontrados:\n";
    cout << "Central 2: h = " << min_h_cen_2 << ", error_relativo = " << min_err_cen_2 << endl;
    cout << "Central 3: h = " << min_h_cen_3 << ", error_relativo = " << min_err_cen_3 << endl;
    cout << "Progresiva 2: h = " << min_h_prog_2 << ", error_relativo = " << min_err_prog_2 << endl;
    cout << "Progresiva 3: h = " << min_h_prog_3 << ", error_relativo = " << min_err_prog_3 << endl;
    cout << "Regresiva 2: h = " << min_h_reg_2 << ", error_relativo = " << min_err_reg_2 << endl;
    cout << "Regresiva 3: h = " << min_h_reg_3 << ", error_relativo = " << min_err_reg_3 << endl;

    return 0;
}
