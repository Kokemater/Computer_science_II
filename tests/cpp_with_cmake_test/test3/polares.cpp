#include <cmath>

double polares(double x, double y, double& theta) {
    // Función que calcula algo con x, y y asigna un valor a theta
    theta = atan2(y, x);  // Ejemplo de cálculo de ángulo polar
    return sqrt(x*x + y*y);  // Devuelve el radio
}