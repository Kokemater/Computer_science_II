#include "funcs.h"
void newton_raphson_non_linear(matrix <double(*)(double, double)> funciones, matrix < double(*)(double, double)> jacobiano, matrix <double> x1, double eps, double &n_iterations_newton, matrix <double> &solution)
{
	matrix <double> x_prev(2,1);
	matrix <double> x_next(2,1);
	matrix <double> F(2,1);
	matrix <double> J(2,2);
	matrix <double> dist(2,1);
	x_prev = x1;
	n_iterations_newton = 0;
	while(true)
	{
		for (int i = 0; i < 2; i++)
		{
			F(i,0) = funciones(i,0)(x_prev(0,0), x_prev(1,0));
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				J(i,j) = jacobiano(i,j)(x_prev(0,0), x_prev(1,0));
			}
		}
		n_iterations_newton++;
		x_next = x_prev - !J * F;
		dist = x_prev - x_next;
		if (dist.Norm(1) <= eps)
		{
			solution = x_next;
			return ;
		}

		x_prev = x_next;
	}
}


void Broyden_non_linear(matrix <double (*)(double, double)> funciones, matrix <double> x1, matrix <double> x2, matrix <double> A_0, double eps, double &n_iterations_sec, matrix <double> &solution)
{
	matrix <double> x_prev(2,1), x_curr(2,1), x_next(2,1), s(2,1);
	matrix <double> F_curr(2,1), F_prev(2,1);
	matrix <double> A(2,2);
	matrix <double> A_prev(2,2);
	x_prev = x1;
	x_curr = x2;
	A_prev = A_0;

	n_iterations_sec = 0;
	while(true)
	{

		s = x_curr - x_prev;
		for(int i = 0; i < 2; i++)
		{
			F_curr(i, 0) = funciones(i,0)(x_curr(0,0), x_curr(1,0)); 
		}

		for(int i = 0; i < 2; i++)
		{
			F_prev(i,0) = funciones(i,0) (x_prev(0,0), x_prev(1,0));
		}
		A = A_prev + ((F_curr - F_prev - A_prev * s)/(~s*s ))* ~s;
		x_next = x_curr - !A * F_curr;
		n_iterations_sec++;
		if (s.Norm(1) <= eps)
		{
			solution = x_next;
			return ;
		}
		x_prev = x_curr;
		x_curr = x_next;
		A_prev = A;
	}
}