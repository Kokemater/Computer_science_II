#include <iostream>
#include <fstream>

int main() {
    // Crear un archivo de datos
    std::ofstream dataFile("data.txt");

    if (!dataFile) {
        std::cerr << "Error al abrir el archivo de datos." << std::endl;
        return 1;
    }

    // Escribir datos en el archivo
    for (int x = 0; x <= 10; ++x) {
        dataFile << x << " " << x * x << std::endl;
    }

    dataFile.close();

    // Crear un script de gnuplot
    std::ofstream gnuplotScript("plot_script.gp");

    if (!gnuplotScript) {
        std::cerr << "Error al crear el script de gnuplot." << std::endl;
        return 1;
    }

    // Escribir el script de gnuplot
    gnuplotScript << "set terminal pngcairo\n";
    gnuplotScript << "set output 'plot.png'\n";
    gnuplotScript << "set title 'Gráfico de x^2'\n";
    gnuplotScript << "set xlabel 'x'\n";
    gnuplotScript << "set ylabel 'y'\n";
    gnuplotScript << "plot 'data.txt' with linespoints title 'x^2'\n";

    gnuplotScript.close();

    // Ejecutar el script de gnuplot
    system("gnuplot plot_script.gp");

    std::cout << "El gráfico se ha generado y guardado como plot.png." << std::endl;

    return 0;
}
