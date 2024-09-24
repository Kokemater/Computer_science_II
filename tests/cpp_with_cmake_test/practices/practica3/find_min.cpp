#include <iostream>
#include <cmath>
int find_min(int *array, int size)
{
    int min_index = 0;
    for (int i = 0; i < size; i++)
    {
        if (abs(array[i]) < abs(array[min_index]))
            min_index = i;
    }
    return array[min_index];
}

int main(void)
{
    int list[6]= {5,2,1,3,4,6};
    int min = find_min(list, 6);
    std::cout << "min = " << min << std::endl;
}
