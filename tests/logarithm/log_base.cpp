#include <iostream>
#include <cmath>

double logBase(double x, double base) {
    return std::log(x) / std::log(base);
}

int main() {
    double x = 32.0;    // Número al que calcular el logaritmo
    double base = 2.0;  // Base deseada

    double result = logBase(x, base);

    std::cout << "Logaritmo de " << x << " en base " << base << " es: " << result << std::endl;

    return 0;
}