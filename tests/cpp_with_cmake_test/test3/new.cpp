#include <iostream>
#include <fstream>

int main(void)
{
    int x = 0;
    std::fstream fin;
    fin.open("Misdatos.txt", std::fstream::in);
    
    if (!fin.is_open()) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return 1;
    }

    int n = 0;
    // Contamos el número de datos en el archivo
    while (fin >> x) {
        n++;
    }
    std::cout << "n = " << n << std::endl;

    // Reposicionamos el puntero de archivo al principio
    fin.clear();  // Limpiamos las banderas de error
    fin.seekg(0, std::ios::beg);

    // Creamos un arreglo dinámico de tamaño n
    double* p = new double[n];

    // Leemos los valores y los almacenamos en el arreglo
    for (int i = 0; i < n; i++) {
        fin >> p[i];
    }

    // Cerramos el archivo
    fin.close();

    // Mostrar los valores del arreglo (opcional)
    for (int i = 0; i < n; i++) {
        std::cout << "p[" << i << "] = " << p[i] << std::endl;
    }

    // Liberamos la memoria asignada
    delete[] p;

    return 0;
}
