#include <iostream>
#include <cmath> // Para usar la constante M_PI y funciones matemáticas

using namespace std;

// Definir la clase Circulo
class Circulo {
private:
    double radio; // Atributo privado

public:
    // Constructor: Inicializa el radio del círculo
    Circulo(double r) {
        radio = r;
    }

    // Método público: Calcular el área
    double area() {
        return M_PI * radio * radio;
    }

    // Método público: Calcular el perímetro
    double perimetro() {
        return 2 * M_PI * radio;
    }

    // Método público: Obtener el radio
    double getRadio() {
        return radio;
    }

    // Método público: Establecer el radio
    void setRadio(double r) {
        if (r > 0) {
            radio = r;
        }
    }
};

int main() {
    // Crear un objeto de la clase Circulo con un radio de 5
    Circulo c1(5);

    // Llamar a los métodos del objeto
    cout << "Área del círculo: " << c1.area() << endl;
    cout << "Perímetro del círculo: " << c1.perimetro() << endl;

    // Cambiar el radio usando el setter
    c1.setRadio(10);
    cout << "Nuevo radio: " << c1.getRadio() << endl;
    cout << "Nueva área del círculo: " << c1.area() << endl;

    return 0;
}
