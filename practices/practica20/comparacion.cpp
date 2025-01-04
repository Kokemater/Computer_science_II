#include "funcs.h"



int main() 
{
    string disparo01 = "disparo01.txt";
    string disparo001 = "disparo001.txt";
    string disparo0001 = "disparo0001.txt";

    string h01 = "h01.txt";
    string h001 = "h001.txt";
    string h0001 = "h0001.txt";

    // Leer la matriz usando la función simplificada
    matrix<double> D01 = read_matrix_from_file(disparo01);
    matrix<double> D001 = read_matrix_from_file(disparo001);
    matrix<double> D0001 = read_matrix_from_file(disparo0001);

    matrix<double> H01 = read_matrix_from_file(h01);
    matrix<double> H001 = read_matrix_from_file(h001);
    matrix<double> H0001 = read_matrix_from_file(h0001);

	ofstream error01("error01.txt"), error001("error001.txt"), error0001("error0001.txt");

    error01 << std::fixed << std::setprecision(15);
    error001 << std::fixed << std::setprecision(15);
    error0001 << std::fixed << std::setprecision(15);

	for (int i = 1; i < H01.RowNo();i++)
	{
		error01 << D01(i, 0) << " " << log10(abs(D01(i,1) - H01(i,1))/abs(H01(i,1))) << endl;
	}
	for (int i = 1; i < H001.RowNo();i++)
	{
		error001 << D001(i, 0) << " " << log10(abs(D001(i,1) - H001(i,1))/abs(H001(i,1)))<< endl;
	}
	for (int i = 1; i < D0001.RowNo();i++)
	{
		error0001 << H0001(i, 0) << " " << log10(abs(D0001(i,1) - H0001(i,1))/abs(H0001(i,1)))<< endl;
	}
    return (0);
}