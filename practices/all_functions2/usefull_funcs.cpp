#include "math_stuff.h"

matrix <double> file_to_matrix(string filename, int rows, int cols)
{
	matrix <double> solution (rows, cols);
	ifstream file(filename);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			file >> solution(i,j);
		}
	}
	return (solution);
}


void matrix_to_file(string filename, const matrix<double>& A, double eps) 
{
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << filename << " para escribir." << endl;
        return;
    }
	file << fixed << setprecision(-log10(eps));

    int rows = A.RowNo();
    int cols = A.ColNo();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file << A(i, j);
            if (j < cols - 1) {
                file << " "; 
            }
        }
        file << endl; 
    }

    file.close();
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

void set_precission(double precission)
{
    double cifras = abs(log10(precission));
    cout << fixed << setprecision(cifras);
}