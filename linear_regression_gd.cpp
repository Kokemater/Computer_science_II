#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// linear regression equation
double predict(double x, double m, double b) {
    return m * x + b;  // y = mx + b
}

//(MSE)
double mean_squared_error(const vector<double>& x, const vector<double>& y, double m, double b) {
    double totalError = 0.0;
    int N = x.size();
    
    for (int i = 0; i < N; i++) {
        double y_pred = predict(x[i], m, b);
        totalError += pow(y_pred - y[i], 2);
    }
    return totalError / N;
}

// Función de descenso por gradiente
void gradient_descent(const vector<double>& x, const vector<double>& y, double& m, double& b, double learning_rate, int iterations) {
    int N = x.size();
    
    for (int i = 0; i < iterations; i++) {
        double m_gradient = 0.0;
        double b_gradient = 0.0;
        // calculate gradient        
        for (int j = 0; j < N; j++) {
            double y_pred = predict(x[j], m, b);
            m_gradient += (2.0 / N) * x[j] * ( y_pred - y[j]);
            b_gradient += (2.0 / N) * (y_pred- y[j]);
        }
        // move in the opposite direction of the gradient
        m -= learning_rate * m_gradient;
        b -= learning_rate * b_gradient;

        // (Opcional) Imprime el error en cada iteración
        if (i % 100 == 0) {
            cout << "Iteración " << i << ": Error = " << mean_squared_error(x, y, m, b) << endl;
        }
    }
}

int main() {
    // Datos de ejemplo (x: valores de entrada, y: valores objetivo)
    vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> y = {2.0, 4.0, 6.0, 8.0, 10.0};  // Relación lineal y = 2x
    
    // Inicializa los parámetros (pendiente m y término independiente b)
    double m = 0.0;  // Pendiente
    double b = 0.0;  // Intersección
    
    // Parámetros de configuración para el descenso por gradiente
    double learning_rate = 0.001;
    int iterations = 1000;
    
    // Ejecuta el descenso por gradiente
    gradient_descent(x, y, m, b, learning_rate, iterations);
    
    // Muestra los parámetros finales
    cout << "Parámetros finales: m = " << m << ", b = " << b << endl;

    return 0;
}
