
#include <iostream>

int main(void)
{
    int *x = new int;
    *x = 1;
    int y;
    y = 1;
    std::cout << *(x) << "  " <<std::endl;
    std::cout << &(y) << "  " <<std::endl;

}
