#include <iostream>
#include "functions.h"

void square(int &a)
{
    a = a*a;
}
void square_1(int *a)
{
    *a = (*a) * (*a);
}
int square_2(int a)
{
    return a*a;
}
int main() {
    double theta;
    double r = polares(5.0, 5.2, theta);  // Aquí intentas pasar un puntero
    std::cout << "r = " << r << "  " << "theta = " << theta << std::endl;
    int a = 2;
    square(a);
    square_1(&a);
    a = square_2(a);
    std::cout << a <<std::endl;
}