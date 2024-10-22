#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;
using namespace math;

int main(void)
{
	int n, m, h;

	matrix<double> A(m,n);
	matrix<double> b(h,1);
	matrix<double> x(h,1);
	ifstream file_A("A.txt");
	ifstream file_b("b.txt");
	file_A >> n;
	file_A >> m;
	h << file_b;

	cout <<"b= " << endl << b;
	if (!A.IsSingular())
	{
		x = !A * b;
		cout << "x= " << endl << x;
	}
	else
	{
		cout << "Error, non invertible matrix !!" << endl;
	}

	return 0;
}