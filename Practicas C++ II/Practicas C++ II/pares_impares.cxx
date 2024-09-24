#include <iostream>
#include <fstream>

using namespace std;

int main() 
{

       ifstream inputFile("numeros_guardados.txt");
       int numero, pares = 0, impares = 0;

       if (!inputFile) 
     {

	        cerr << "No se pudo abrir el archivo." << endl;
	        return 1;
     }


       while (inputFile >> numero) 
     {

	        if (numero % 2 == 0) 
	  {

	                 pares++;
	  }
	 else 
	  {

	                 impares++;
	  }

     }


       inputFile.close();

       cout << "Números pares: " << pares << endl;
       cout << "Números impares: " << impares << endl;

       return 0;
}

