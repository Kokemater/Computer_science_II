#include <string.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "matrix.h"

using namespace math;
using namespace std;

pair<matrix<double>, matrix<double>> eigen(matrix<double> A, double eps)
{
    if (!(A.IsSquare()))
    {
        cout<<"Error: Non square matrix"<<endl;
        return make_pair(matrix<double>(0, 0), matrix<double>(0,0));
    }
    if (!(A.IsSymmetric()))
    {
        cout<<"Error: Non symetric matrix"<<endl;
        return make_pair(matrix<double>(0, 0), matrix<double>(0,0));
    }
    else
    {
        double alf,pi;
        pi = atan(1)*4;
        int n = A.RowNo();
        int x_max, y_max;
        double maxim = 0;
        matrix<double> R(n,n), B(n,n), U(n,n);
        U.Unit();
        int iter = 0;
        while (true)
        {
            x_max = 0;
            y_max = 0;
            maxim = 0;
            iter++;
            for (int i=0; i < n - 1; i++)
            {
                for(int j=i+1; j < n; j++)
                {
                    if (abs(A(i,j)) > maxim)
                    {
                        maxim = abs(A(i,j));
                        x_max = i;
                        y_max = j;
                    }
                }
            }
        if (A(x_max,x_max)==A(y_max,y_max))
        {
            alf = pi/4;
        }
        else
        {
            alf = 0.5*atan(2*A(x_max,y_max)/(A(x_max,x_max)-A(y_max,y_max)));
        }
        R.Unit();
        R(x_max,x_max)= cos(alf);
        R(x_max,y_max)= -sin(alf);
        R(y_max,x_max)= sin(alf);
        R(y_max,y_max)= cos(alf);
        if (abs(A(x_max,y_max))<eps)
        {break;}
        B = ~ R * A * R;
        A = B;
        U = U*R;
        }
        return make_pair(A, U);
    }
    return make_pair(matrix<double>(0, 0), matrix<double>(0,0));
}