#include <iostream>
#include "../../functions/matrix.h"
#include <cmath>

using namespace std;
using namespace math;

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

void insert_rands_in_matrix(matrix <double> &A, double min, double max)
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
		}
	}
}

double error(matrix <double> A, matrix <double>b, matrix <double>x)
{
	matrix <double>error_vec =  b - A*x;
	double error = error_vec.Norm();
	return error;
}