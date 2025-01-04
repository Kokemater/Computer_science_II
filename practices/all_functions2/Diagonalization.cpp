#include "computation_II.h"


int my_find_max_abs(matrix <long double> A, int &row, int &col)
{
	row = 0;
	col = 1;
	for (int i = 0; i < A.RowNo(); i++)
	{
		for (int j = i + 1; j < A.ColNo(); j++)
		{
			if (abs(A(i,j)) > abs(A(row, col)))
			{
				row = i;
				col = j;
			}
		}
	}
	return A(row, col);
}

int Jacobi_eigen(matrix <long double> &A, matrix <long double> &U, long double &iter, long double eps) 
{
    int max_iter = 10000;
    int i_m, j_m;
    long double theta;
    matrix <long double> U_prev(A.RowNo(), A.ColNo());
    matrix <long double> R(A.RowNo(), A.ColNo());
	matrix <long double> I(A.RowNo(), A.ColNo());
	long double initial_tr = A.Traza();
    // Inicialización
    iter = 0;
	I.Unit();
    U.Unit();

    // Verificación de matriz cuadrada y simétrica
    if (!A.IsSquare()) {
        std::cout << "Non square matrix";
        return 1;
    }
    else if (!A.IsSymmetric()) {
        std::cout << "Non symmetric matrix";
        return 1;
    }

    while (true )
	{
		iter++;

        my_find_max_abs(A, i_m, j_m);
        R.Unit();
        if (A(i_m, i_m) == A(j_m, j_m))
            theta = M_PI / 4;
        else
            theta = 0.5 * atan(2 * A(i_m, j_m)/ (A(i_m, i_m) - A(j_m, j_m)));
        
        R(i_m, i_m) = cos(theta);
        R(j_m, j_m) = cos(theta);
        R(i_m, j_m) = -sin(theta);
        R(j_m, i_m) = sin(theta);

        A = ~R * A * R;
		if (abs(A.Traza() - initial_tr) > 1)
		{
			cout << "La traza no coincide";
			return 1;
		}
		my_find_max_abs(A, i_m, j_m);
		if (abs(A(i_m, j_m)) < eps)
			break;
        U = U * R;
		if  (iter > max_iter)
			return 1;
    }
    // Si no convergió
    if (iter >= max_iter) {
        std::cout << "El método de Jacobi no ha convergido en " << max_iter << " iteraciones." << std::endl;
        return 1;
    }

    return 0;
}

int Jacobi_eigen_for_Off_plot(matrix <long double> &A, matrix <long double> &U, long double &iter, long double eps, long double (*Off) (matrix <long double>), ofstream &outfile) 
{
	cout << "Matrix : " << endl << A <<endl;
    int max_iter = 10000;
    int i_m, j_m;
    long double theta;
    matrix <long double> U_prev(A.RowNo(), A.ColNo());
    matrix <long double> R(A.RowNo(), A.ColNo());
	matrix <long double> I(A.RowNo(), A.ColNo());
	long double initial_tr = A.Traza();
	long double first_off = Off(A);
	long double teorica;
	int n = A.RowNo();
    // Inicialización
    iter = 0;
	I.Unit();
    U.Unit();

    // Verificación de matriz cuadrada y simétrica
    if (!A.IsSquare()) {
        cout << "Non square matrix";
        return 1;
    }
    else if (!A.IsSymmetric()) {
        cout << "Non symmetric matrix";
        return 1;
    }

    while (true)
	{
        my_find_max_abs(A, i_m, j_m);

        R.Unit();
        
        if (A(i_m, i_m) == A(j_m, j_m))
            theta = M_PI / 4;
        else
            theta = 0.5 * atan(2 * A(i_m, j_m)/ (A(i_m, i_m) - A(j_m, j_m)));
        
        R(i_m, i_m) = cos(theta);
        R(j_m, j_m) = cos(theta);
        R(i_m, j_m) = -sin(theta);
        R(j_m, i_m) = sin(theta);

        A = ~R * A * R;
		outfile << iter << " " << log10(Off(A)/first_off) << endl; 
		
		if (abs(A.Traza() - initial_tr) > 1)
		{
			cout << "La traza no coincide";
			return 1;
		}
		my_find_max_abs(A, i_m, j_m);
		if (abs(A(i_m, j_m)) < eps)
			break;
        U = U * R;
        iter++;
		if  (iter > max_iter)
			return 1;
    }
    if (iter >= max_iter) {
        std::cout << "El método de Jacobi no ha convergido en " << max_iter << " iteraciones." << std::endl;
        return 1;
    }
	cout << "Resultado: "<< log10(Off(A)/first_off) << endl;
    return 0;
}

void set_precission(long double precission)
{
    long double cifras = abs(log10(precission));
    cout << fixed << setprecision(cifras);
}

matrix <long double> print_eigen_val(matrix <long double> A)
{
	matrix <long double> array(A.ColNo(), 1);
	for(int i = 0; i < A.ColNo(); i++)
	{
		array(i,0) = A(i,i);		
	}
	cout << "Eigenvalues: " << endl;
	cout << array << endl;
	return array;
}

matrix <long double> get_eigen_vect(matrix <long double> A, int pos)
{
	matrix <long double> array(A.ColNo(), 1);
	for(int i = 0; i < A.ColNo(); i++)
	{
		array(i,0) = A(i,pos);		
	}
	return array;
}

long double Off(matrix <long double> A)
{
	long double total = 0;
	for(int i = 0; i < A.RowNo(); i++)
	{
		for (int j = 0; j < A.ColNo(); j++)
		{
			if (i != j)
				total += (A(i,j) * A(i,j));
		}
	}
	return total;
}

