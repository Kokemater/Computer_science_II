#include "funcs.h"
#include <fstream>
#include <iostream>

using namespace std;

void readMatrix(ifstream &file, matrix<double> &mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> mat(i, j);
        }
    }
}

void findExtrema(matrix<double> &mat, ofstream &max1, ofstream &max2, ofstream &max3, int rows) {
    for (int i = 0; i < rows - 1; i++) {
        // x1
        if (mat(i, 2) * mat(i + 1, 2) < 0)
            max1 << mat(i, 0) << " " << mat(i, 1) << endl;
        // x2
        if (mat(i, 4) * mat(i + 1, 4) < 0)
            max2 << mat(i, 0) << " " << mat(i, 3) << endl;
        // x3
        if (mat(i, 4) * mat(i + 1, 4) < 0)
            max3 << mat(i, 0) << " " << mat(i, 5) << endl;
    }
}

int main(void) {
    int rows = 10000; // Change this to the matrix size
    int cols = 7; // Change this to the matrix size
    matrix<double> A1(rows, cols);
    matrix<double> A01(rows, cols);
    matrix<double> A10(rows, cols);

    ifstream omega1("rk4_data.txt");
    ifstream omega01("rk4_data_01.txt");
    ifstream omega10("rk4_data_10.txt");

    ofstream omega1_max1("max_1_1.txt");
    ofstream omega1_max2("max_1_2.txt");
    ofstream omega1_max3("max_1_3.txt");

    ofstream omega01_max1("max_01_1.txt");
    ofstream omega01_max2("max_01_2.txt");
    ofstream omega01_max3("max_01_3.txt");

    ofstream omega10_max1("max_10_1.txt");
    ofstream omega10_max2("max_10_2.txt");
    ofstream omega10_max3("max_10_3.txt");

    readMatrix(omega1, A1, rows, cols);
    readMatrix(omega01, A01, rows, cols);
    readMatrix(omega10, A10, rows, cols);

    findExtrema(A1, omega1_max1, omega1_max2, omega1_max3, rows);
    findExtrema(A01, omega01_max1, omega01_max2, omega01_max3, rows);
    findExtrema(A10, omega10_max1, omega10_max2, omega10_max3, rows);

    return 0;
}