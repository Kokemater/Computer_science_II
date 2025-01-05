#ifndef COMPUTATION_II
#define COMPUTATION_II

#include "math_stuff.h"

// Find roots funcs
 double newton( double (*f)( double),  double (*f_prime)( double),  double x1,  double eps,  double &n_iterations_newton);
 double secante( double (*f) ( double),  double x1,  double x2,  double eps,  double &n_iterations_sec);
 double biseccion( double (*f)( double),  double a,  double b,  double eps,  double &n_iterations);

// Linear Equations
int Gauss_Seidel(matrix<double> A, matrix<double> b, matrix<double> &x, double eps);
int Jacobi(matrix <double> A, matrix <double> b, matrix <double> &x, double eps);
void LU(matrix <double> A, matrix <double> &L, matrix <double> &U);
void solve_LU(matrix<double> L, matrix<double> U, matrix<double> b, matrix<double>& x);
void LU_tri(matrix <double> d, matrix <double> ds, matrix <double> df, matrix <double> b, int size, matrix <double> &delta_f, matrix <double> &delta, matrix <double> &delta_s, matrix <double> &z, matrix <double> &x);
math::matrix<double> solveTrid ( math::matrix<double> mid, math::matrix<double> lower,math::matrix<double> upper , math::matrix<double> b );


// Non Linear Equations
void newton_non_linear(matrix < double(*)(double, double)> funciones, matrix < double(*)(double, double)> jacobiano, matrix <double> x1, double eps, double &n_iterations_newton, matrix <double> &solution);
void Broyden(matrix <double (*)(double, double)> funciones, matrix <double> x1, matrix <double> x2, matrix <double> A_0, double eps, double &n_iterations_sec, matrix <double> &solution);

// Diagonalization
int Jacobi_eigen(matrix < double> &A, matrix < double> &U,  double &iter,  double eps);
 double Off(matrix < double> A);
int Jacobi_eigen_for_Off_plot(matrix < double> &A, matrix < double> &U,  double &iter,  double eps,  double (*Off) (matrix < double>), ofstream &outfile);
matrix < double> print_eigen_val(matrix < double> A);
matrix < double> get_eigen_vect(matrix < double> A, int pos);

// Integration
double trapezoidal(double (*f)(double), double a, double b, double tau);
double simpson(double (*f) (double), double a, double b, double tau);
double gauss_6(double (*f)(double),double a, double b);

// Derivation
double diferencia_centrada_1(double (*f) (double), double x, double h);
double S(double (*f)(double), double x, double h);
double H(double (*f)(double), double x, double h);
double diferencia_centrada_2(double (*f)(double), double x, double h);
double diferencia_centrada_3(double (*f)(double), double x, double h);
double progresivas2(double (*f)(double), double x, double h);
double progresivas3(double (*f)(double), double x, double h);
double regresivas2(double (*f)(double), double x, double h);
double regresivas3(double (*f)(double), double x, double h);

// Edos
void runge_kutta_4(double& x, matrix<double>& cond_iniciales, double h);
void euler_one_step(double& x, matrix<double>& cond_iniciales, double h);
void runge_kutta_2(double& x, matrix<double>& cond_iniciales, double h);
void diferencias_finitas(double L, double T0, double TL, double dx);
double secant_method(double a, double b, double ua, double ub, double epsilon, double h);
void rk4_con_metodo_del_disparo(double h, double a, double b, double ua, double ub);
void diferencias_finitas(double h, double a, double b, double ua, double ub);

////////////////// General use ///////////////////////
// Matrix 
void insert_rands_in_matrix(matrix <double> &A, double min, double max, bool dominancia_diagonal);
int my_find_max_abs(matrix < double> A, int &row, int &col);
matrix <double> file_to_matrix(string filename, int rows, int cols);
void matrix_to_file(string filename, const matrix<double>& A, double eps);

// Precisision and error
void set_precission(double precission);
double error_relativo(double dnumerica, double dteorica);
double error(matrix <double> A, matrix <double>b, matrix <double>x); 

#endif