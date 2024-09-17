#include <iostream>
#include <vector>

using namespace std;

vector<int> perfect_numbers(const int N)
{
    int total;
    vector<int> vec;
    for (int i = 2; i < N; i++)
    {
        total = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                total += j;
            }
        }
        if (total == i)
        {
            vec.push_back(i);  // Inserta el número perfecto en el vector
        }
    }
    return vec;  // Devuelve el vector después de que finaliza el ciclo
}

int main(void)
{
    int N = 1000;
    vector<int> perfects = perfect_numbers(N);  // Almacena los números perfectos

    // Imprime los números perfectos encontrados
    cout << "Perfect numbers up to " << N << ": ";
    for (int num : perfects)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
