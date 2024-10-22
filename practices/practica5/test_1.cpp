#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "matrix.h"
using namespace math;

int main(){
  //Definicion de matriz 3x3 con elementos de tipo double
  matrix<double> A(3,3);

  //Asignacion de valores a cada elemento de la matriz
  A(0,0)=9;
  A(0,1)=1;
  A(0,2)=1;
  A(1,0)=2;
  A(1,1)=10;
  A(1,2)=3;
  A(2,0)=3;
  A(2,1)=4;
  A(2,2)=11;


   
  //Imprime los elementos de la matriz
  cout<<"Imprime Elementos de matriz A"<<endl;
  cout<<A<<endl;

  //Definicion de matriz 3x1 con elementos de tipo double
  matrix<double> x(3,1);

  //Asignacion de valores a cada elemento de la matriz
  x(0,0)=1;
  x(1,0)=0;
  x(2,0)=0;

  //Multiplicacion de matriz A por matriz x.
  cout <<"Multiplicacion de matriz A por matriz x."<<endl;
  matrix<double> b(3,1);
  b=A*x;
  cout<<" b = A * x "<<endl;
  cout<<b<<endl;

  //Matriz inversa y resolucion de sistemas

 cout << "Matriz inversa y resolucion de sistemas"<<endl;
   
  b(0,0)=10;
  b(1,0)=19;
  b(2,0)=0;
  x = !A * b;
  cout<<" Solucion x de la ecuacion Ax=b  "<<endl;
  cout<<x<<endl;

  //Lectura de elementos de una matriz que se encuentran en un fichero
  matrix<double> B(3,3);
  ifstream in_f("testmatrix.dat");
  in_f >> B;
  cout<<" Lectura de elementos de matriz almacenados en un fichero  "<<endl;
  cout<<B<<endl;
  in_f.close();

  //Suma de matrices
  matrix<double> C;
  C = A + B;
  cout<<" Suma de dos matrices "<<endl;
  cout<<C<<endl;

  //Resta de matrices
  C = A - B;
  cout<<" Resta de dos matrices "<<endl;
  cout<<C<<endl;

  //Multiplicacion de un numero por una matriz
  double alpha = 3.0;
  C = alpha * B;
  cout<<" Multiplicacion de numero por matriz "<<endl;
  cout<<C<<endl;

  //Multiplicacion de matrices
  C = B * A;
  cout<<" Multiplicacion de matrices "<<endl;
  cout<<C<<endl;

  //Elevar matriz a una potencia
  C = B ^ 2;
  cout<<" Matriz elevado a una potencia "<<endl;
  cout<<C<<endl;

  //Determinante de una matriz
  cout<<" Determinante "<<endl;
  cout<<C.Det()<<endl;

  //Inicializa a cero todos los elementos de la matriz
  C.Null();
  cout<<" Inicializacion a cero "<<endl;
  cout<<C<<endl;

  //Inicializa a la matriz unidad los elementos de la matriz C
  C.Unit();
  cout<<" Inicializacion a matrix unidad "<<endl;
  cout<<C<<endl;

  //Norma cuadratica de una matriz
  cout<<" Norma cuadratica "<<endl;
  cout<<A.Norm()<<endl;
  cout<<" Norma cuadratica "<<endl;
  cout<<A.Norm(2)<<endl;
  cout<<" Norma supremo "<<endl;
  cout<<A.Norm(1)<<endl;


   cout << "Traza de la matriz "<<endl;
   cout << A.Traza()<<endl;

  //Transpuesta
   cout << "Matriz A y su Transpuesta "<<endl;
  cout<<A<<endl;
  cout<<~A<<endl;

}
