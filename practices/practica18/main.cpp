#include "funcs.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double k = 1.;
const double f0 = 1.;
const double m = 1.;
const double omega = 10;
const double omega0 = k/m;

// Funciones para las derivadas
double z1_1prime(double z1_1, double z1_2, double z2_1, double z2_2, double z3_1, double z3_2, double t) {
    return z1_2;
}

double z1_2prime(double z1_1, double z1_2, double z2_1, double z2_2, double z3_1, double z3_2, double t) {
    return f0 / m * cos(omega * t) - 2 * pow(omega0, 2) * z1_1 + pow(omega0, 2) * z2_1;
}

double z2_1prime(double z1_1, double z1_2, double z2_1, double z2_2, double z3_1, double z3_2, double t) {
    return z2_2;
}

double z2_2prime(double z1_1, double z1_2, double z2_1, double z2_2, double z3_1, double z3_2, double t) {
    return pow(omega0, 2) * z1_1 - 2 * pow(omega0, 2) * z2_1 + pow(omega0, 2) * z3_1;
}

double z3_1prime(double z1_1, double z1_2, double z2_1, double z2_2, double z3_1, double z3_2, double t) {
    return z3_2;
}

double z3_2prime(double z1_1, double z1_2, double z2_1, double z2_2, double z3_1, double z3_2, double t) {
    return pow(omega0, 2) * z2_1 - 2 * pow(omega0, 2) * z3_1;
}

// Método de Runge-Kutta 4º orden (RK4)
void runge_kutta_4(matrix<double>& cond_iniciales, double& t, double h) {
    // Extraemos las condiciones iniciales
    double z1_1 = cond_iniciales(0, 0);
    double z1_2 = cond_iniciales(1, 0);
    double z2_1 = cond_iniciales(2, 0);
    double z2_2 = cond_iniciales(3, 0);
    double z3_1 = cond_iniciales(4, 0);
    double z3_2 = cond_iniciales(5, 0);

    // Variables para almacenar los incrementos k1, k2, k3, k4
    double k1[6], k2[6], k3[6], k4[6];

    // Calculamos k1
    k1[0] = z1_1prime(z1_1, z1_2, z2_1, z2_2, z3_1, z3_2, t);
    k1[1] = z1_2prime(z1_1, z1_2, z2_1, z2_2, z3_1, z3_2, t);
    k1[2] = z2_1prime(z1_1, z1_2, z2_1, z2_2, z3_1, z3_2, t);
    k1[3] = z2_2prime(z1_1, z1_2, z2_1, z2_2, z3_1, z3_2, t);
    k1[4] = z3_1prime(z1_1, z1_2, z2_1, z2_2, z3_1, z3_2, t);
    k1[5] = z3_2prime(z1_1, z1_2, z2_1, z2_2, z3_1, z3_2, t);

    // Calculamos k2
    k2[0] = z1_1prime(z1_1 + 0.5 * h * k1[0], z1_2 + 0.5 * h * k1[1], z2_1 + 0.5 * h * k1[2], z2_2 + 0.5 * h * k1[3], z3_1 + 0.5 * h * k1[4], z3_2 + 0.5 * h * k1[5], t + 0.5 * h);
    k2[1] = z1_2prime(z1_1 + 0.5 * h * k1[0], z1_2 + 0.5 * h * k1[1], z2_1 + 0.5 * h * k1[2], z2_2 + 0.5 * h * k1[3], z3_1 + 0.5 * h * k1[4], z3_2 + 0.5 * h * k1[5], t + 0.5 * h);
    k2[2] = z2_1prime(z1_1 + 0.5 * h * k1[0], z1_2 + 0.5 * h * k1[1], z2_1 + 0.5 * h * k1[2], z2_2 + 0.5 * h * k1[3], z3_1 + 0.5 * h * k1[4], z3_2 + 0.5 * h * k1[5], t + 0.5 * h);
    k2[3] = z2_2prime(z1_1 + 0.5 * h * k1[0], z1_2 + 0.5 * h * k1[1], z2_1 + 0.5 * h * k1[2], z2_2 + 0.5 * h * k1[3], z3_1 + 0.5 * h * k1[4], z3_2 + 0.5 * h * k1[5], t + 0.5 * h);
    k2[4] = z3_1prime(z1_1 + 0.5 * h * k1[0], z1_2 + 0.5 * h * k1[1], z2_1 + 0.5 * h * k1[2], z2_2 + 0.5 * h * k1[3], z3_1 + 0.5 * h * k1[4], z3_2 + 0.5 * h * k1[5], t + 0.5 * h);
    k2[5] = z3_2prime(z1_1 + 0.5 * h * k1[0], z1_2 + 0.5 * h * k1[1], z2_1 + 0.5 * h * k1[2], z2_2 + 0.5 * h * k1[3], z3_1 + 0.5 * h * k1[4], z3_2 + 0.5 * h * k1[5], t + 0.5 * h);

    // Calculamos k3
    k3[0] = z1_1prime(z1_1 + 0.5 * h * k2[0], z1_2 + 0.5 * h * k2[1], z2_1 + 0.5 * h * k2[2], z2_2 + 0.5 * h * k2[3], z3_1 + 0.5 * h * k2[4], z3_2 + 0.5 * h * k2[5], t + 0.5 * h);
    k3[1] = z1_2prime(z1_1 + 0.5 * h * k2[0], z1_2 + 0.5 * h * k2[1], z2_1 + 0.5 * h * k2[2], z2_2 + 0.5 * h * k2[3], z3_1 + 0.5 * h * k2[4], z3_2 + 0.5 * h * k2[5], t + 0.5 * h);
    k3[2] = z2_1prime(z1_1 + 0.5 * h * k2[0], z1_2 + 0.5 * h * k2[1], z2_1 + 0.5 * h * k2[2], z2_2 + 0.5 * h * k2[3], z3_1 + 0.5 * h * k2[4], z3_2 + 0.5 * h * k2[5], t + 0.5 * h);
    k3[3] = z2_2prime(z1_1 + 0.5 * h * k2[0], z1_2 + 0.5 * h * k2[1], z2_1 + 0.5 * h * k2[2], z2_2 + 0.5 * h * k2[3], z3_1 + 0.5 * h * k2[4], z3_2 + 0.5 * h * k2[5], t + 0.5 * h);
    k3[4] = z3_1prime(z1_1 + 0.5 * h * k2[0], z1_2 + 0.5 * h * k2[1], z2_1 + 0.5 * h * k2[2], z2_2 + 0.5 * h * k2[3], z3_1 + 0.5 * h * k2[4], z3_2 + 0.5 * h * k2[5], t + 0.5 * h);
    k3[5] = z3_2prime(z1_1 + 0.5 * h * k2[0], z1_2 + 0.5 * h * k2[1], z2_1 + 0.5 * h * k2[2], z2_2 + 0.5 * h * k2[3], z3_1 + 0.5 * h * k2[4], z3_2 + 0.5 * h * k2[5], t + 0.5 * h);

    // Calculamos k4
    k4[0] = z1_1prime(z1_1 + h * k3[0], z1_2 + h * k3[1], z2_1 + h * k3[2], z2_2 + h * k3[3], z3_1 + h * k3[4], z3_2 + h * k3[5], t + h);
    k4[1] = z1_2prime(z1_1 + h * k3[0], z1_2 + h * k3[1], z2_1 + h * k3[2], z2_2 + h * k3[3], z3_1 + h * k3[4], z3_2 + h * k3[5], t + h);
    k4[2] = z2_1prime(z1_1 + h * k3[0], z1_2 + h * k3[1], z2_1 + h * k3[2], z2_2 + h * k3[3], z3_1 + h * k3[4], z3_2 + h * k3[5], t + h);
    k4[3] = z2_2prime(z1_1 + h * k3[0], z1_2 + h * k3[1], z2_1 + h * k3[2], z2_2 + h * k3[3], z3_1 + h * k3[4], z3_2 + h * k3[5], t + h);
    k4[4] = z3_1prime(z1_1 + h * k3[0], z1_2 + h * k3[1], z2_1 + h * k3[2], z2_2 + h * k3[3], z3_1 + h * k3[4], z3_2 + h * k3[5], t + h);
    k4[5] = z3_2prime(z1_1 + h * k3[0], z1_2 + h * k3[1], z2_1 + h * k3[2], z2_2 + h * k3[3], z3_1 + h * k3[4], z3_2 + h * k3[5], t + h);

    // Actualizamos las condiciones iniciales usando una combinación ponderada de k1, k2, k3 y k4
    cond_iniciales(0, 0) += (h / 6.0) * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]);
    cond_iniciales(1, 0) += (h / 6.0) * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]);
    cond_iniciales(2, 0) += (h / 6.0) * (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]);
    cond_iniciales(3, 0) += (h / 6.0) * (k1[3] + 2 * k2[3] + 2 * k3[3] + k4[3]);
    cond_iniciales(4, 0) += (h / 6.0) * (k1[4] + 2 * k2[4] + 2 * k3[4] + k4[4]);
    cond_iniciales(5, 0) += (h / 6.0) * (k1[5] + 2 * k2[5] + 2 * k3[5] + k4[5]);

    // Avanzamos el tiempo un paso
    t += h;
}

int main() {
    // Definimos las matrices
    matrix<double> cond_iniciales(6, 1); // Condiciones iniciales: z(0) y z'(0)

    // Inicializamos las condiciones iniciales
    cond_iniciales(0, 0) = 0.0;
    cond_iniciales(1, 0) = 0.0;
    cond_iniciales(2, 0) = 0.0;
    cond_iniciales(3, 0) = 0.0;
    cond_iniciales(4, 0) = 0.0;
    cond_iniciales(5, 0) = 0.0;

    // Variables iniciales
    double t = 0.0; // Tiempo inicial
    double h = 0.01; // Paso

    // Archivo de salida
    ofstream rk4("rk4_data_10.txt");

    // Bucle para realizar los pasos de Runge-Kutta 4
    while (t < 100) {
        runge_kutta_4(cond_iniciales, t, h); // Realizamos un paso de RK4
		rk4 << t << " ";
        for (int i = 0; i < 6; i++) {
            rk4 << cond_iniciales(i, 0) << " ";
        }
        rk4 << endl;
    }

    rk4.close(); // Cerrar el archivo de salida
    return 0;
}
