#include <iostream>
#include <limits>


int main() {
    std::cout << "El valor más pequeño positivo de double: "
              << std::numeric_limits<double>::min() << std::endl;
	std::cout << "El número de dígitos : " 
			  << std::numeric_limits<double>::max_digits10 << std::endl;

	std::cout << "La precisión más baja"
			<<std::numeric_limits<double>::epsilon()
    return (0);
}