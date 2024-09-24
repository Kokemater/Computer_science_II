#include <iostream>
#include <fstream>

using namespace std;

int main() 
{

       ofstream outputFile("numeros_guardados.txt");
       int numero;

       if (!outputFile) 
     {

	        cerr << "No se pudo crear el archivo." << endl;
	        return 1;
     }


       cout << "Introduce números (negativo para terminar): " << endl;
       while (true) 
     {

	        cin >> numero;
	        if (numero < 0) 
	  {

	                 break;
	  }

	        outputFile << numero << endl;
     }


       outputFile.close();
       cout << "Números guardados en 'numeros_guardados.txt'." << endl;

       return 0;
}

