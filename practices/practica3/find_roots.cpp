#include "functions.h"

void  find_roots(double a, double b, double c, double &result1, double &result2)
{
    result1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    result2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
}

int main(void)
{
    double res1, res2;
    find_roots(4,6,1,res1, res2);
    std::cout << "result: " << res1 << res2;
}