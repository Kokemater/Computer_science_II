#include <iostream>
#include <fstream>

void func_1(void)
{
    std::fstream fin;
    fin.open("Misdatos.txt", std::fstream::in);
    int x;
    int n = 0;
    while(fin >> x)
        n++;
    fin.close();
    fin.open("Misdatos.txt", std::fstream::in);
    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> p[i]; 
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "p[" << i << "] = " << p[i]  <<std::endl;
    }
    fin.close();
}