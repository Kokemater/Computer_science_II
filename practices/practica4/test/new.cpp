#include <iostream>
using namespace std;

// Función que toma dos enteros y devuelve un entero
int sumar(int a, int b) {
    return a + b;
}

// Función que toma un puntero a otra función como parámetro
int operar(int x, int y, int (*operacion)(int, int)) {
    return operacion(x, y);  // Aplica la operación a x e y
}

int main() {
    int resultado = operar(5, 3, sumar);  // Llamamos a 'operar' pasando 'sumar' como parámetro
    cout << "El resultado es: " << resultado << endl;  // Imprime: El resultado es: 8
    return 0;
}
