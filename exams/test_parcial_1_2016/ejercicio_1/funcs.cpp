#include "funcs.h"


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

void insert_rands_in_matrix(matrix <double> &A, double min, double max, bool dominancia_diagonal = false)
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


double error(matrix <double> A, matrix <double>b, matrix <double>x)
{
	matrix <double>error_vec =  b - A*x;
	double error = error_vec.Norm();
	return error;
}
