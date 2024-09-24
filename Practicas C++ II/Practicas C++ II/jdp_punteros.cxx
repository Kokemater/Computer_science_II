#include <iostream>
#include <fstream>
using namespace std;
int main(){

  double y(3.7);
  double x=2.5;
  cout<<y<<"  "<<&y<<"  "<<*(&y)<<endl;
  cout<<x<<"  "<<&x<<"  "<<*(&x)<<endl;
  int n; n=3;
  cout<<n<<"  "<<&n<<"  "<<*(&n)<<endl;

  //Punteros
  double *p; int *s; p = &x; s = &n;
  cout<<"Estudio de Puntero a int \n";
  cout<<s<<"  "<<&s<<"  "<<*s<<endl; *s = 5; cout<<"n="<<n<<endl;
  cout<<sizeof(n)<<"  "<<sizeof(s)<<" "<<sizeof(p)<<endl;

  const int ndim = 3;
  double V[ndim]={1.1,2.2,3.3};
  p = V;
  cout<<"p = V \n";
  for(int i=0;i<ndim;i+=1){
    cout<<p[i]<<endl;
  }

  //Reserva dinamica de memoria. Array: estatico; Puntero: dinamico. Ejemplo:
  //leer numeros de un fichero, pero no sabemos cuantos hay.
  fstream misdatos;
  misdatos.open("testdata.txt",fstream::in);
  misdatos>>x;n = 0;
  while( !misdatos.eof() ){
    n = n + 1;
    misdatos>>x;
  }
  p = new double[n];
  misdatos.close();
  misdatos.open("testdata.txt",fstream::in);
  misdatos>>x; int M = 0;
  while( !misdatos.eof() ){
    p[M] = x;M++;
    misdatos>>x;
  }
  misdatos.close();
  
  cout<<"p : \n";
  for(int i=0;i<n;i+=1){
    cout<<p[i]<<endl;
  }

  
  double *pp = nullptr;
  cout<<"pp : \n";
  pp = p;
  for(pp = p; pp<p+n;pp+=1){
    cout<<*pp<<endl;
  }

  //Cuando terminamos con p y no lo necesitaremos mas:
  delete[] p;



  //Doble puntero. Ejemplo.
  double B[ndim][ndim]={{1,2,3},{4,5,6},{7,8,9}};
  double **A; A = new double * [ndim];
  for(int i=0;i<ndim;++i){ A[i] = new double [ndim]; }
  for(int i=0;i<ndim;i+=1){
    for(int j=0;j<ndim;j++){
      A[i][j]=B[i][j];
    }
  }
  cout<<"A:\n";
  for(int i=0;i<ndim;i+=1){
    for(int j=0;j<ndim;j++){
      cout<<A[i][j]<<"  ";
    }
    cout<<endl;
  }

}
