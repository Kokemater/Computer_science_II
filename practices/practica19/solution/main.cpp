#include <iostream>
#include <vector>
#include <cmath>

// Parámetros globales
const double X0 = 0.0;       // Límite inicial
const double X1 = 1.0;       // Límite final
const double U0 = 40.0;      // u(0) = 40
const double UF = 40.0;      // u(1) = 40
const double EPSILON = 1e-5; // Precisión para método de la secante
const double H = 0.001;      // Paso para Runge-Kutta 4

using namespace std;

// Función del sistema de ecuaciones: y[0] = u, y[1] = v
vector<double> system(double x, vector<double> y, double gamma) {
    double u = y[0], v = y[1];
    return {v, x * v + (1 - x * x) * pow(u, gamma) + exp(-x * x)};
}

// Método de Runge-Kutta 4 para resolver el sistema
vector<double> runge_kutta4(double gamma, double v0) {
    double x = X0;
    vector<double> y = {U0, v0}; // y[0] = u, y[1] = v
    
    while (x < X1) {
        vector<double> k1 = system(x, y, gamma);
        vector<double> k2 = system(x + H / 2, {y[0] + H * k1[0] / 2, y[1] + H * k1[1] / 2}, gamma);
        vector<double> k3 = system(x + H / 2, {y[0] + H * k2[0] / 2, y[1] + H * k2[1] / 2}, gamma);
        vector<double> k4 = system(x + H, {y[0] + H * k3[0], y[1] + H * k3[1]}, gamma);

        y[0] += H / 6 * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]);
        y[1] += H / 6 * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]);
        x += H;
    }
    return y; // Devuelve el estado final {u(1), v(1)}
}

// Método de la secante para ajustar v(0)
double secant_method(double gamma) {
    double v0_prev = -10.0, v0 = 10.0; // Valores iniciales de prueba
    double u1_prev, u1;

    u1_prev = runge_kutta4(gamma, v0_prev)[0] - UF;
    u1 = runge_kutta4(gamma, v0)[0] - UF;

    while (fabs(u1) > EPSILON) {
        double v_temp = v0 - u1 * (v0 - v0_prev) / (u1 - u1_prev);
        v0_prev = v0;
        v0 = v_temp;
        u1_prev = u1;
        u1 = runge_kutta4(gamma, v0)[0] - UF;
    }
    return v0;
}

int main() {
    vector<double> gammas = {0.5, 1.0, 1.5};

    for (double gamma : gammas) {
        cout << "Solución para gamma = " << gamma << ":\n";
        double v0 = secant_method(gamma);
        cout << "  v(0) = " << v0 << "\n";

        // Obtener y mostrar u(x) y u'(x)
        double x = X0;
        vector<double> y = {U0, v0};

        while (x <= X1) {
            printf("x = %.3f, u(x) = %.6f, u'(x) = %.6f\n", x, y[0], y[1]);

            // Runge-Kutta para un paso
            vector<double> k1 = system(x, y, gamma);
            vector<double> k2 = system(x + H / 2, {y[0] + H * k1[0] / 2, y[1] + H * k1[1] / 2}, gamma);
            vector<double> k3 = system(x + H / 2, {y[0] + H * k2[0] / 2, y[1] + H * k2[1] / 2}, gamma);
            vector<double> k4 = system(x + H, {y[0] + H * k3[0], y[1] + H * k3[1]}, gamma);

            y[0] += H / 6 * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]);
            y[1] += H / 6 * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]);
            x += H;
        }
        cout << "-------------------------\n";
    }
    return 0;
}
