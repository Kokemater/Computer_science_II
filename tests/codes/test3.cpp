#include <iostream>

using namespace std;

int main(void)
{
    int number;
    cout << "Write a number" << endl;
    cin >> number;
    if (number % 2 == 0)
    {
        cout << "PAR" << endl;
    }
    else
    {
        cout << "IMPAR" << endl;
    }
    return 0;
}