#include "funcs.h"

int main(void)
{
	int rows = 10000; // Change this to the matrix size
	int cols = 7; // Change this to the matrix size
	matrix <double> A1(rows, cols);
	matrix <double> A01(rows, cols);
	matrix <double> A10(rows, cols);

	ifstream omega1("rk4_data.txt");
	ifstream omega01("rk4_data_01.txt");
	ifstream omega10("rk4_data_10.txt");

	ofstream omega1_max1("max_1_1.txt");
	ofstream omega1_max2("max_1_2.txt");
	ofstream omega1_max3("max_1_3.txt");

	ofstream omega01_max1("max_01_1.txt");
	ofstream omega01_max2("max_01_2.txt");
	ofstream omega01_max3("max_01_3.txt");

	ofstream omega10_max1("max_10_1.txt");
	ofstream omega10_max2("max_10_2.txt");
	ofstream omega10_max3("max_10_3.txt");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			omega1 >> A1(i,j);
			omega01 >> A01(i,j); 
			omega10 >> A10(i,j);
		}
	}

	for (int i = 0; i < rows - 1; i++)
	{
		// x1
		if (A1(i,2) * A1(i + 1 ,2) < 0)
			omega1_max1 << A1(i,0) << " " << A1(i, 1) << endl;
		// x2
		if (A1(i,4) * A1(i + 1 ,4) < 0)
			omega1_max2 << A1(i,0) << " " << A1(i, 3) << endl;
		// x3
		if (A1(i,4) * A1(i + 1 ,4) < 0)
			omega1_max3 << A1(i,0) << " " << A1(i, 5) << endl;

		////////////////////////
		// x1
		if (A01(i,2) * A01(i + 1 ,2) < 0)
			omega01_max1 << A01(i,0) << " " << A01(i, 1) << endl;
		// x2
		if (A01(i,4) * A01(i + 1 ,4) < 0)
			omega01_max2 << A01(i,0) << " " << A01(i, 3) << endl;
		// x3
		if (A01(i,4) * A01(i + 1 ,4) < 0)
			omega01_max3 << A01(i,0) << " " << A01(i, 5) << endl;

		/////////////
		// x1
		if (A10(i,2) * A10(i + 1 ,2) < 0)
			omega10_max1 << A10(i,0) << " " << A10(i, 1) << endl;
		// x2
		if (A10(i,4) * A10(i + 1 ,4) < 0)
			omega10_max2 << A10(i,0) << " " << A10(i, 3) << endl;
		// x3
		if (A10(i,4) * A10(i + 1 ,4) < 0)
			omega10_max3 << A10(i,0) << " " << A10(i, 5) << endl;
	}
}