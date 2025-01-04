#include "funcs.h"


int main(void)
{
	matrix <double> A = {
		{0, -1,-5,0},
		{0,4,0,-5},
		{-1, 0,2,1},
		{0,1,0,-2}
	};
	matrix <double> b ={{1,-4,0,-1}};
	b = ~b;
	matrix <double> x (8,1);
	x = !A*b;
	cout << x;
}