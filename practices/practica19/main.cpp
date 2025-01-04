#include "funcs.h"

double gamma_val;

double z1_prime(double z1, double z2, double x) {
    return z2;
}

// Función z2' = x z2 + (1 - x^2) z1^gamma + e^(-x^2)
double z2_prime(double z1, double z2, double x) {
    return x * z2 + (1 - x * x) * pow(z1, gamma_val) + exp(-x * x);
}
// Método de Runge-Kutta 4º orden (RK4)
void runge_kutta_4(double& x, matrix<double>& cond_iniciales, double h) 
{
    // Extraemos las condiciones iniciales
    double z1 = cond_iniciales(0, 0);
    double z2 = cond_iniciales(1, 0);

    // Calculamos k1
    double k1_z1 = z1_prime(z1, z2, x);
    double k1_z2 = z2_prime(z1, z2, x);

    // Calculamos k2
    double k2_z1 = z1_prime(z1 + 0.5 * h * k1_z1, z2 + 0.5 * h * k1_z2, x + 0.5 * h);
    double k2_z2 = z2_prime(z1 + 0.5 * h * k1_z1, z2 + 0.5 * h * k1_z2, x + 0.5 * h);

    // Calculamos k3
    double k3_z1 = z1_prime(z1 + 0.5 * h * k2_z1, z2 + 0.5 * h * k2_z2, x + 0.5 * h);
    double k3_z2 = z2_prime(z1 + 0.5 * h * k2_z1, z2 + 0.5 * h * k2_z2, x + 0.5 * h);

    // Calculamos k4
    double k4_z1 = z1_prime(z1 + h * k3_z1, z2 + h * k3_z2, x + h);
    double k4_z2 = z2_prime(z1 + h * k3_z1, z2 + h * k3_z2, x + h);

    // Actualizamos las condiciones iniciales usando una combinación ponderada de k1, k2, k3 y k4
    cond_iniciales(0, 0) += (h / 6.0) * (k1_z1 + 2 * k2_z1 + 2 * k3_z1 + k4_z1);
    cond_iniciales(1, 0) += (h / 6.0) * (k1_z2 + 2 * k2_z2 + 2 * k3_z2 + k4_z2);

    // Avanzamos x un paso
    x += h;
}


double secant_method(double target, double epsilon, double h) {
    double v0_1 = -10.0, v0_2 = 10.0; // Valores iniciales para v(0)
    double u1_1, u1_2;

    // Primera integración usando Runge-Kutta
    double x = 0.0;
    matrix<double> cond_iniciales(2, 1);
    cond_iniciales(0, 0) = 40.0; // z1(0) = u(0)
    cond_iniciales(1, 0) = v0_1; // z2(0) = u'(0)

    while (x < 1.0) runge_kutta_4(x, cond_iniciales, h);
    u1_1 = cond_iniciales(0, 0) - target; // Error en u(1)

    // Segunda integración con v0_2
    x = 0.0;
    cond_iniciales(0, 0) = 40.0;
    cond_iniciales(1, 0) = v0_2;

    while (x < 1.0) runge_kutta_4(x, cond_iniciales, h);
    u1_2 = cond_iniciales(0, 0) - target;

    // Método de la secante iterativo
    while (fabs(u1_2) > epsilon) {
        double v0_new = v0_2 - u1_2 * (v0_2 - v0_1) / (u1_2 - u1_1);

        // Actualizamos valores
        v0_1 = v0_2;
        u1_1 = u1_2;

        v0_2 = v0_new;

        x = 0.0;
        cond_iniciales(0, 0) = 40.0;
        cond_iniciales(1, 0) = v0_2;

        while (x < 1.0) runge_kutta_4(x, cond_iniciales, h);
        u1_2 = cond_iniciales(0, 0) - target;
    }

    return v0_2; // Retorna el valor ajustado de z2(0)
}

int main() {
    // Parámetros iniciales
    double h = 1e-5;
    double epsilon = 1e-15;    
    double target = 40.0;

	ofstream data05("data05.txt");
	ofstream data1("data1.txt");
	ofstream data15("data15.txt");

    // Valores de gamma a resolver
    double gammas[] = {0.5, 1.0, 1.5};

    for (double gamma : gammas) {
        gamma_val = gamma;
        cout << "Resolviendo para gamma = " << gamma << "...\n";

        // Encontramos z2(0) usando el método de la secante
        double v0 = secant_method(target, epsilon, h);
        cout << "  v(0) ajustado = " << v0 << "\n";

        // Integración final para obtener u(x) y u'(x)
        double x = 0.0;
        matrix<double> cond_iniciales(2, 1);
        cond_iniciales(0, 0) = 40.0; // z1(0)
        cond_iniciales(1, 0) = v0;   // z2(0)

        cout << "  x\t\tu(x)\t\tu'(x)\n";
        while (x < 1.0 + h) {
			if (gamma == 0.5)
            	data05 << x << " " <<  cond_iniciales(0, 0)<< " "<< cond_iniciales(1, 0) << endl;
			else if(gamma == 1)
				data1 << x << " " <<  cond_iniciales(0, 0)<< " "<< cond_iniciales(1, 0) << endl;
			else if(gamma == 1.5)
				data15 << x << " " <<  cond_iniciales(0, 0)<< " "<< cond_iniciales(1, 0) << endl;

            runge_kutta_4(x, cond_iniciales, h);
        }
        cout << "-----------------------------\n";
    }

	gamma_val = 1;
	// Pregunta 5
	ofstream data15_h01("disparo01.txt");
	ofstream data15_h001("disparo001.txt");
	ofstream data15_h0001("disparo0001.txt");

	data15_h01<< fixed << setprecision(15);
	data15_h001<< fixed << setprecision(15);
	data15_h0001<< fixed << setprecision(15);

	double h_list[] = {0.1, 0.01, 0.001};
    for (double h_val : h_list) {
        double v0 = secant_method(target, epsilon, h_val);
        double x = 0.0;

        matrix<double> cond_iniciales(2, 1);
        cond_iniciales(0, 0) = 40.0;
        cond_iniciales(1, 0) = v0;

        while (x < 1.0 + h_val) {
			if (h_val == 0.1)
            	data15_h01 << x << " " <<  cond_iniciales(0, 0)<< " "<< cond_iniciales(1, 0) << endl;
			else if(h_val == 0.01)
				data15_h001 << x << " " <<  cond_iniciales(0, 0)<< " "<< cond_iniciales(1, 0) << endl;
			else if(h_val == 0.001)
				data15_h0001 << x << " " <<  cond_iniciales(0, 0)<< " "<< cond_iniciales(1, 0) << endl;

            runge_kutta_4(x, cond_iniciales, h_val);
        }
        cout << "-----------------------------\n";
    }
    return 0;
}
