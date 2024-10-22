#include <iostream>
using namespace std;

// Definición de la plantilla de la clase Rectangle
template <class T>
class Rectangle
{
public:
    T width, heigth;  // Ancho y altura del rectángulo, de tipo genérico T

    // Método para establecer los valores del ancho y la altura
    void set_values(T x, T y)
    {
        width = x;
        heigth = y;
    }

    // Método para calcular el área, con tipo de retorno T
    T calculate_area(void)
    {
        return heigth * width;
    }

    // Método para calcular el perímetro, con tipo de retorno T
    T calculate_perimeter(void)
    {
        return 2 * heigth + 2 * width;
    }

    // Método para imprimir el área y el perímetro
    void print_data(void)
    {
        cout << "Area= " << calculate_area() << " Perimeter= " << calculate_perimeter() << endl;
    }
};

int main(void)
{
    Rectangle<float> rect;  // Crear un objeto de la clase Rectangle con el tipo de datos `float`

    rect.set_values(3.5, 4.2);  // Establecer valores decimales para width y heigth
    rect.print_data();  // Imprimir el área y el perímetro

    return 0;
}
