#include <iostream>
#include <fstream>
#include "matrix.h"
using namespace std;
using namespace math;

int main(void)
{
	ifstream file("mat_text.txt"); 
	if (!file)
	{
		cout << "No file";
		return 1;
	}
	matrix<double> a(3,3);
	file >> a;
	cout << a;
}