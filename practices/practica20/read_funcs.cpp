#include "funcs.h"

// Función para calcular el número de filas en el archivo
int calculate_rows(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << file_name << endl;
        exit(EXIT_FAILURE);
    }

    int rows = 0;
    string line;
    while (getline(file, line)) {
        rows++;
    }

    file.close();
    return rows;
}

// Función para calcular el número de columnas en el archivo
int calculate_cols(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << file_name << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    getline(file, line);
    file.close();

    // Contamos el número de elementos separados por espacios en la primera línea
    int cols = 0;
    stringstream ss(line);
    string value;
    while (ss >> value) {
        cols++;
    }

    return cols;
}
matrix<double> read_matrix_from_file(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << file_name << endl;
        exit(EXIT_FAILURE);
    }

    // Determinar número de filas y columnas
    int rows = 0, cols = 0;
    string line;

    // Determinamos las filas y columnas
    while (getline(file, line)) {
        if (rows == 0) {
            stringstream ss(line);
            string value;
            while (ss >> value) cols++; // Contamos columnas en la primera fila
        }
        rows++;
    }

    file.clear();           // Limpiar los flags de lectura
    file.seekg(0, ios::beg); // Volver al inicio del archivo

    // Crear matriz e insertar los valores
    matrix<double> A(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(file >> A(i, j))) {
                cerr << "Error: Archivo contiene datos inválidos o insuficientes." << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    file.close();
    return A;
}
