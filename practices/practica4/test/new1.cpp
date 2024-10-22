#include <iostream>
using namespace std;

int sum(int a, int b)
{
	return a+b;
}

int apply_sum(int x, int y, int (*operacion)(int, int))
{
	return operacion(x,y);
}

int main(void)
{
	int a = apply_sum(2,3,sum);
	std::cout << a << std::endl;
}