#include "computation_II.h"

double z1_prime(matrix <double> cond_inic, double x);
double z2_prime(matrix <double> cond_inic, double x);

double p(double x);
double q(double x);
double r(double x);

matrix<double> Z_prime_funcs(matrix <double> cond_iniciales, double x) {
    int order = cond_iniciales.RowNo();
    matrix<double> Z_prime(order, 1);

    // Calculamos las derivadas para cada orden
    Z_prime(0, 0) = z1_prime(cond_iniciales, x); // Primera derivada
    Z_prime(1, 0) = z2_prime(cond_iniciales, x); // Segunda derivada

    return Z_prime;
}

// Método de Euler para un paso
void euler_one_step(double& x, matrix<double>& cond_iniciales, double h) {
    int order = cond_iniciales.RowNo();

    matrix<double> Z_prime = Z_prime_funcs(cond_iniciales, x);

    // Actualizamos las variables dependientes con el método de Euler
    for (int i = 0; i < order; i++) {
        cond_iniciales(i, 0) += h * Z_prime(i, 0); // z_i_new = z_i + h * z_i'
    }
    // Avanzamos x un paso
    x += h;
}
// Método de Runge-Kutta 2º orden (RK2)
void runge_kutta_2(double& x, matrix<double>& cond_iniciales, double h) {
    int order = cond_iniciales.RowNo();

    matrix<double> k1(order, 1);
    matrix<double> k2(order, 1);

    // Calculamos k1 en el punto actual
    k1 = Z_prime_funcs(cond_iniciales, x);

    // Calculamos las condiciones intermedias usando k1
    matrix<double> cond_intermedias = cond_iniciales;
    for (int i = 0; i < order; i++) {
        cond_intermedias(i, 0) += h * k1(i, 0);
    }

    // Calculamos k2 en el punto intermedio
    k2 = Z_prime_funcs(cond_intermedias, x + h);

    // Actualizamos las condiciones iniciales usando el promedio de k1 y k2
    for (int i = 0; i < order; i++) {
        cond_iniciales(i, 0) += h * (k1(i, 0) + k2(i, 0)) / 2.0;
    }

    // Avanzamos x un paso
    x += h;
}

// Método de Runge-Kutta 4º orden (RK4)
void runge_kutta_4(double& x, matrix<double>& cond_iniciales, double h) {
    int order = cond_iniciales.RowNo();

    matrix<double> k1(order, 1);
    matrix<double> k2(order, 1);
    matrix<double> k3(order, 1);
    matrix<double> k4(order, 1);

    // Calculamos k1 en el punto actual
    k1 = Z_prime_funcs(cond_iniciales, x);

    // Calculamos las condiciones intermedias usando k1 para k2
    matrix<double> cond_intermedias = cond_iniciales;
    for (int i = 0; i < order; i++) {
        cond_intermedias(i, 0) += 0.5 * h * k1(i, 0);
    }
    k2 = Z_prime_funcs(cond_intermedias, x + 0.5 * h);

    // Calculamos las condiciones intermedias usando k2 para k3
    cond_intermedias = cond_iniciales;
    for (int i = 0; i < order; i++) {
        cond_intermedias(i, 0) += 0.5 * h * k2(i, 0);
    }
    k3 = Z_prime_funcs(cond_intermedias, x + 0.5 * h);

    // Calculamos las condiciones intermedias usando k3 para k4
    cond_intermedias = cond_iniciales;
    for (int i = 0; i < order; i++) {
        cond_intermedias(i, 0) += h * k3(i, 0);
    }
    k4 = Z_prime_funcs(cond_intermedias, x + h);

    // Actualizamos las condiciones iniciales usando una combinación ponderada de k1, k2, k3 y k4
    for (int i = 0; i < order; i++) {
        cond_iniciales(i, 0) += (h / 6.0) * (k1(i, 0) + 2 * k2(i, 0) + 2 * k3(i, 0) + k4(i, 0));
    }

    // Avanzamos x un paso
    x += h;
}

double error(double analitico, double numerico)
{
	return (abs(analitico - numerico));
}

double secant_method(double a, double b, double ua, double ub, double epsilon, double h)
 {
    double v0_1 = -10.0, v0_2 = 10.0; // Valores iniciales para v(0)
    double u1_1, u1_2;

    // Primera integración usando Runge-Kutta
    double x = a;
    matrix<double> cond_iniciales(2, 1);
    cond_iniciales(0, 0) = ua; // z1(0) = u(0)
    cond_iniciales(1, 0) = v0_1; // z2(0) = u'(0)

    while (x < b) runge_kutta_4(x, cond_iniciales, h);
    u1_1 = cond_iniciales(0, 0) - ub; // Error en u(1)

    // Segunda integración con v0_2
    x = a;
    cond_iniciales(0, 0) = ua;
    cond_iniciales(1, 0) = v0_2;

    while (x < b) runge_kutta_4(x, cond_iniciales, h);
    u1_2 = cond_iniciales(0, 0) - ub;

    // Método de la secante iterativo
    while (fabs(u1_2) > epsilon)
	{
        double v0_new = v0_2 - u1_2 * (v0_2 - v0_1) / (u1_2 - u1_1);

        v0_1 = v0_2;
        u1_1 = u1_2;

        v0_2 = v0_new;

        x = a;
        cond_iniciales(0, 0) = ua;
        cond_iniciales(1, 0) = v0_2;

        while (x < 1.0) runge_kutta_4(x, cond_iniciales, h);

        u1_2 = cond_iniciales(0, 0) - ub;
    }
    return v0_2; // Retorna el valor ajustado de z2(0)
}


void diferencias_finitas(double h, double a, double b, double ua, double ub)
{
	/* El procedimiento es el siguiente:
	* Si hemos definifo n subintervalos, u debe tener n+1 elementos ( va
	* desde u0 hasta un ).
	* Como conocemos u_0 (ua) y u_n (ub), el sistema de la tridiagonal
	solo debe
	* resolverse para los valores de x desde x_1 hata x_n-1, es decir,
	* las matrices columna ccn las diagonales tendr·n n-1 elementos.
	*/
	// Determinamos las diagonales y la matriz b (B_aux).
	int n = (int) ( b - a )/h;
	math::matrix<double> inf(n-1,1);
	math::matrix<double> sup(n-1,1);
	math::matrix<double> princ(n-1,1);
	double x = a; // necesitamos los valores de x, que van desde a hasta b-h.
	math::matrix<double> B_aux(n-1,1);
	for ( int i = 0; i < n-1; i++ )
	{
		x = x + h;
		princ(i,0) = 2 + h * h * q(x);
		B_aux(i,0) = - h * h * r(x);
		sup(i,0) = 0.5 * h * p(x) - 1;
		inf(i,0) = - ( 0.5 * h * p(x) + 1 );
	}
	// corregimos los valores mal calculados en el bucle.
	B_aux(0,0) = - h * h * r(a+h) + ( 0.5 * h * p(a+h) + 1 ) * ua;
	B_aux(n-2,0) = - h * h * r(x) - ( 0.5 * h * p(x) - 1 ) * ub;
	sup(n-2,0) = 0;
	inf(0,0) = 0;
	// u_aux es el vector que va desde u_1 hasta u_n-2.
	// xu = vector con los valores de x
	math::matrix<double> u_aux(n-1,1), u(n+1,1), xu(n+1,1);
	u_aux = solveTrid ( princ, inf, sup, B_aux );
	// u = [ ua , u_aux, ub ]
	u(0,0) = ua;
	xu(0,0) = a;
	u(n,0) = ub;
	xu(n,0) = b; 
	for ( int i = 1; i < n; i++ ){
	xu(i,0) = a + i*h;
	u(i,0) = u_aux(i-1,0);
	} 
	string fnombre;
	std::ostringstream ss;
	ss << "diferencias_h_"<< h << ".txt";
	fnombre = ss.str();

	std::fstream F_datos;
	F_datos << fixed << setprecision(17);

	F_datos.open(fnombre.c_str(), std::fstream::out);
	for (int i = 0; i <= n; i++) {
		F_datos << xu(i, 0) << " " << u(i, 0) << std::endl;
	}
	F_datos.close();
}


void rk4_con_metodo_del_disparo(double h, double a, double b, double ua, double ub)
{
	double eps = 1e-17;
	double v_0 = secant_method(a, b, ua, ub, eps, h);

	matrix <double> cond_iniciales(2,1);
	cond_iniciales(0,0) = ua;
	cond_iniciales(1,0) = v_0;

	string fnombre;
	std::ostringstream ss;
	ss << "disparo_h_"<< h << ".txt";
	fnombre = ss.str();

	std::fstream F_datos;
	F_datos << fixed << setprecision(17);
	F_datos.open(fnombre.c_str(), std::fstream::out);
	double x = a;
	while(x < b)
	{
		runge_kutta_4(x, cond_iniciales, h);
		cout << cond_iniciales(0,0) << endl;
		F_datos << x << " " << cond_iniciales(0,0) << " " << cond_iniciales (1,0) << endl;
	}
}