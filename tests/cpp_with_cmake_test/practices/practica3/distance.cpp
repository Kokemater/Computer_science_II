#include "functions.h"

double distance(double *x1, double *x2, int n)
{
    double result = 0;
    for(int i = 0; i < n; i++)
    {
        result += (x1[i] - x2[i])*(x1[i] - x2[i]);
    }
    return sqrt(result);
}

int main(void)
{
    double x1[4] = {1,1,1,1};
    double x2[4] = {2,2,2,2};
    double d = distance(x1, x2, 4);
    std::cout <<"dist = " << d;
}