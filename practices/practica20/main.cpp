#include "funcs.h" // Se asume que tienes una implementación de "matrix" ya disponible


using namespace std;

// Declaración de tus funciones
void LU_tri(matrix<double> d, matrix<double> ds, matrix<double> df, matrix<double> b, int size, matrix<double>& delta_f, matrix<double>& delta, matrix<double>& delta_s, matrix<double>& z, matrix<double>& x);
void diferencias_finitas(int N, double h, matrix<double>& u);

double diferencia_relativa(double a, double b) {
    return abs(a - b) / abs(b);
}


int main() {
    // Configuramos los valores de h
    double h_list[] = {0.1, 0.01, 0.001};

    // Creamos archivos de salida
    ofstream h01("h01.txt"), h001("h001.txt"), h0001("h0001.txt");
    ofstream diff01("diff01.txt"), diff001("diff001.txt");

	h01<< fixed << setprecision(15);
	h001<< fixed << setprecision(15);
	h0001<< fixed << setprecision(15);
    matrix<double> u01, u001, u0001;

    // Resolvemos para cada valor de h
    for (double h : h_list) {
        int N = static_cast<int>(1.0 / h);
        matrix<double> u(1, N + 1); // Matriz para la solución actual
        diferencias_finitas(N, h, u);

        for (int i = 0; i <= N; ++i) {
            double x = i * h;
            if (h == 0.1) {
                h01 << x << " " << u(0, i) << endl;
                u01 = u; 
            }
            if (h == 0.01) {
                h001 << x << " " << u(0, i) << endl;
                u001 = u; 
            }
            if (h == 0.001) {
                h0001 << x << " " << u(0, i) << endl;
                u0001 = u;
            }
        }
    }

    // Calculamos las diferencias relativas
    double h = 0.1;
    int N01 = static_cast<int>(1.0 / h);
    for (int i = 0; i <= N01; ++i) {
        double x = i * h;
        diff01 << x << " " << diferencia_relativa(u01(0, i), u0001(0, i)) << endl;
    }

    h = 0.01;
    int N001 = static_cast<int>(1.0 / h);
    for (int i = 0; i <= N001; ++i) {
        double x = i * h;
        diff001 << x << " " << diferencia_relativa(u001(0, i), u0001(0, i)) << endl;
    }

    // Cerramos los archivos
    h01.close();
    h001.close();
    h0001.close();
    diff01.close();
    diff001.close();

    return 0;
}
