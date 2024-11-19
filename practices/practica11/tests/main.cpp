#include <string.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "matrix.h"
#include "jaco_eig.cpp"
using namespace math;
using namespace std;
int main()
{
    int n = 6;
    double eps = 1e-7;
    matrix<double> A (n,n);
    A=
    {
        {4, -30, 60, -35, 112, -120},
        {-30, 44, 65, -234, 113, 211},
        {60, 65, 214, 345, 212, 114},
        {-35, -234, 345, 435, 23, 0},
        {112, 113, 212, 23, -312, 331},
        {-120, 211, 114, 0, 331, -234}
    };
    pair<matrix<double>, matrix<double>> result = eigen(A, eps);
    matrix<double> eigen_values = result.first;
    matrix<double> eigen_vectors = result.second;
    cout << fixed << setprecision(7);
    cout<<"Los autovalores son: \n"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j)
            {
                double ev = eigen_values(i,j);
                cout<<ev<<endl;
            }
        }
    }
    cout<<"\nLa matriz de autovectores es: \n"<<eigen_vectors<<endl;
    cout<<"\nComprobamos que el resultado es correcto realizando la operación Av - λv y comprobando que es igual al vector 0"<<endl;
    for (int i = 0; i < n; i++)
    {
        double autov = eigen_values(i, i);
        matrix<double> e_vec(n, 1);
        matrix<double> check(n, 1);
        for (int j = 0; j < n; j++)
        {
            e_vec(j, 0) = eigen_vectors(j, i);
        }
        check = A * e_vec - autov * e_vec;
        cout << check << endl;
    }
    return 0;
}