#include "computation_II.h"


int Gauss_Seidel(matrix<double> A, matrix<double> b, matrix<double> &x, double eps)
{
    x.Null(); 
    int iterations = 0;
    double sum_1, sum_2;
    matrix<double> x_old = x; 
    int n = A.RowNo(); 
    do {
        x_old = x;
        iterations++;
        
        for (int i = 0; i < n; i++)
        {
            sum_1 = 0.0;
            for (int j = 0; j < i; j++)
            {
                sum_1 += A(i, j) * x(j, 0);
            }

            sum_2 = 0.0;
            for (int j = i + 1; j < n; j++) 
            {
                sum_2 += A(i, j) * x_old(j, 0);
            }

            x(i, 0) = (1.0 / A(i, i)) * (b(i, 0) - sum_1 - sum_2);
        }
    } while ((x - x_old).Norm() > eps);  // Criterio de convergencia basado en la norma

    return iterations;
}

int Jacobi(matrix <double> A, matrix <double> b, matrix <double> &x, double eps)
{
	x.Null();
	matrix <double> x_next(b.RowNo(), 1);
	double sum;
	int iterations = 1;
	for (int i = 0; i < A.RowNo(); i++)
	{
		sum = 0;
		for (int j = 0; j < A.RowNo(); j++)
		{
			if (j != i)
				sum += A(i,j)*x(j,0);
		}
		x_next(i,0) = 1/A(i,i) * (b(i,0) - sum); 
	}

	matrix <double> dist = x-x_next;
	while ((x - x_next).Norm() > eps)
	{
		x = x_next;
		for (int i = 0; i < A.RowNo(); i++)
		{
			sum = 0;
			for (int j = 0; j < A.ColNo(); j++)
			{
				if (j != i)
					sum += A(i,j)*x(j,0);
			}
			x_next(i,0) = 1/A(i,i) * (b(i,0) - sum); 
		}
		iterations++;
	}
	return iterations;
}

void insert_rands_in_matrix(matrix <double> &A, double min, double max, bool dominancia_diagonal)
{
	srand(42);
	double rand_v;
    double random_number;
	for(int i = 0; i < A.RowNo(); i++)
	{
		for (int j = 0; j < A.ColNo(); j++)
		{
			rand_v = rand();
			A(i,j) = min + (rand_v / RAND_MAX) * (max - min);
			if (i != j && dominancia_diagonal == true)
				A(i,j) = A(i,j)/1000;
		}
	}
}
void LU(matrix <double> A, matrix <double> &L, matrix <double> &U)
{
	L.Null();
	U.Null();
	if (A.RowNo() != A.ColNo())
	{
		cout << "A is not a square matrix" << endl;
		return ;
	}
	double sum;
	for (int i = 0; i < A.RowNo(); i++)
	{
		for (int j = 0; j < A.ColNo();j++)
		{
			if (i < j)
			{
				sum = 0;
				for (int k = 0; k < i; k++)
				{
					sum += L(i,k)*U(k,j);
				}
				L(i,j) = 0;
				U(i,j) = A(i,j) - sum;
			}
			else if (i == j)
			{
				sum = 0;
				for(int k = 0; k < i; k++)
				{
					sum += L(i,k) * U(k,j);
				}
				L(i,j) = 1;
				U(i,j) = A(i,j) - sum;
			}
			else
			{	
				sum = 0;
				for(int k = 0; k < j; k++)
				{
					sum += L(i,k) * U(k,j);
				}
				U(i,j) = 0;
				L(i,j) = 1/U(j,j) * (A(i,j) - sum);
			}
		}
	}
}
void solve_LU(matrix<double> L, matrix<double> U, matrix<double> b, matrix<double>& x) {
    int n = b.RowNo();
    matrix<double> z(n, 1);
    
    // Sustitución hacia adelante para resolver Lz = b
    z(0, 0) = b(0, 0);
    double sum;
    for (int i = 1; i < n; i++) {
        sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L(i, j) * z(j, 0);
        }
        z(i, 0) = b(i, 0) - sum;
    }

    // Sustitución hacia atrás para resolver Ux = z
    x(n - 1, 0) = z(n - 1, 0) / U(n - 1, n - 1);
    for (int i = n - 2; i >= 0; i--) {
        sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U(i, j) * x(j, 0);
        }
        x(i, 0) = (z(i, 0) - sum) / U(i, i);
    }
}


void LU_tri(matrix <double> d, matrix <double> ds, matrix <double> df, matrix <double> b, int size, matrix <double> &delta_f, matrix <double> &delta, matrix <double> &delta_s, matrix <double> &z, matrix <double> &x)
{
	delta_s = ds;
	delta(0,0) = d(0,0);
	for (int i = 1; i < size; i++)
	{
		delta_f(0,i-1) = df(0,i-1) / delta(0,i-1);
		delta(0,i) = d(0,i) - delta_f(0,i-1) * ds(0,i-1);
	}
	z(0,0) = b(0,0);
	for (int i = 1; i < size; i++)
	{
		z(0,i) = b(0,i) - delta_f(0,i-1)*z(0,i-1);
	}
	x(0, size-1) = z(0,size-1)/delta(0,size-1);
	for (int i = size-2; i >= 0; i--)
	{
		x(0,i) = (z(0,i) - ds(0,i)*x(0,i+1))/delta(0,i);
	}
}

math::matrix<double> solveTrid (
 math::matrix<double> mid, math::matrix<double> lower,
math::matrix<double> upper ,
 math::matrix<double> b ) {
 int n = mid.RowNo();
 math::matrix<double> delta(n,1);
 math::matrix<double> delta_f(n,1);
 math::matrix<double> z(n,1);
 delta(0,0) = mid(0,0);
 delta_f(0,0) = 0;
 z(0,0) = b(0,0);
 for( int i = 1; i < n; i++ ){
 delta_f(i,0) = lower(i,0)/delta(i-1,0);
 delta(i,0) = mid(i,0) - delta_f(i,0)*upper(i-1,0);
 z(i,0) = b(i,0) - delta_f(i,0)*z(i-1,0);
 }
 math::matrix<double> x(n,1);
 x(n-1,0) = z(n-1,0)/delta(n-1,0);
 for ( int i = n - 2 ; i >= 0; i-- ){
 x(i,0) = ( z(i,0) - upper(i,0) * x(i+1,0) ) / delta(i,0);
 }

 return x;
 } 


double error(matrix <double> A, matrix <double>b, matrix <double>x)
{
	matrix <double>error_vec =  b - A*x;
	double error = error_vec.Norm();
	return error;
}