#include <iostream>
#include "matrix.h"
using namespace math;
using namespace std;

int main(void)
{
	matrix<double> a(2,2);
	matrix<double> a_inv(2,2);
	a(0,0) = 0;
	a(0,1) = 1;
	a(1,0) = 2;
	a(1,1) = 3;
	cout << a <<endl;
	a_inv = !a;
	cout << a_inv*a;
}
