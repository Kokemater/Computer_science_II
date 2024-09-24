#include <iostream>
#include <fstream>

using namespace std;

int main() 
{

       ifstream inputFile("numeros_guardados.txt");
       int numero, suma = 0, limite = 100;

       if (!inputFile) 
     {

	        cerr << "No se pudo abrir el archivo." << endl;
	        return 1;
     }


       while (inputFile >> numero) 
     {

	        suma += numero;
	        if (suma > limite) 
	  {

	                 break;
	  }

     }


       inputFile.close();

       cout << "La suma total es: " << suma << endl;

       return 0;
}

