
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

#include "../../functions/matrix.h"
using namespace math;

// import data import_data import matrix_import read_file read_txt
int main(void)
{
	int rows = 3; // Change this to the matrix size
	int cols = 5; // Change this to the matrix size
	matrix <double> A(rows, cols);
	ifstream file("matrix.txt");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			file >> A(i,j); 
		}
	}
	A *= 2;
	
	cout << A;
}