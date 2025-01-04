#include "all_functions/math_stuff.h"
#include "all_functions/computation_II.h"

matrix <double> text_to_matrix(string filename, int rows, int cols)
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
double diferencia_relativa(double x_real, double x_numerica)
{
	return (abs(x_real - x_numerica)/x_numerica);
}
int main(void)
{

	// Importamos todos los datos
	int cols_dif = 2;
	int cols_disp = 3;
	int row01 = 10, row001 = 100, row0001 = 1000;
	matrix <double> dif01 = text_to_matrix("diferencias_h_0.1.txt", row01, 2);
	matrix <double> dif001 = text_to_matrix("diferencias_h_0.01.txt", row001, 2);
	matrix <double> dif0001 = text_to_matrix("diferencias_h_0.001.txt", row0001, 2);

	matrix <double> disparo01 = text_to_matrix("disparo_h_0.1.txt", row01, 3);
	matrix <double> disparo001 = text_to_matrix("disparo_h_0.01.txt", row001, 3);
	matrix <double> disparo0001 = text_to_matrix("disparo_h_0.001.txt", row0001, 3);

	// Pregunta 2
	ofstream comp_01_0001("comp1.txt");
	ofstream comp_001_0001("comp2.txt");

	comp_001_0001 << fixed << setprecision(10);
	comp_01_0001 << fixed << setprecision(10);

	int iter01 = 0;
	int iter001 = 0;
	for (int iter0001= 0; iter0001 < row0001; iter0001++)
	{
		if (iter01 < row01 && dif01(iter01,0) == dif0001(iter0001,0))
		{
			comp_01_0001 << dif0001(iter0001, 0) << " " << diferencia_relativa(dif0001(iter0001, 1), dif01(iter01,1)) << endl;
			iter01++;
		}
		if (iter001 < row001 && dif001(iter001,0) == dif0001(iter0001,0))
		{
			comp_001_0001 << dif0001(iter0001, 0) << " " << diferencia_relativa(dif0001(iter0001, 1), dif001(iter001,1)) << endl;
			iter001++;
		}
	}
	// Pregunta 3
	ofstream c01("c01.txt");
	ofstream c001("c001.txt");
	ofstream c0001("c0001.txt");

	for (int i = 0; i < row01-1; i++)
	{
		cout << "dif " << dif01(i+1,0) << " " << dif01(i+1,1) << endl;
		cout << "disparo " << disparo01(i,0) << " " << disparo01(i,1) << endl;
		cout << "----" << endl;
		c01 << dif01(i+1,0) << " " << abs (dif01(i+1,1) - disparo01(i,1)) << endl;
	}
	for (int i = 0; i < row001-1; i++)
	{
		c001 << dif001(i+1,0) << " " << abs(dif001(i+1,1) - disparo001(i,1)) << endl;
	}
		for (int i = 0; i < row0001-1; i++)
	{
		c0001 << dif0001(i+1,0) << " " << abs(dif0001(i+1,1) - disparo0001(i,1)) << endl;
	}

}