#include <iostream>
using namespace std;

int main(){

  const int n=3;
  double b[n]={1.7,3.3,2.3}, x[n];

  double C[n*n]={
                   11,   3,  -2,
                    1.4, 9,   2.1,
                    1.5,-1.8,-1
                };

  double A[n][n];

  //Determinacion de A a partir de C
  int i,j,k;
  k = 0;
  for (i=0; i<=n-1; ++i){
    for (j=0; j<=n-1; j+=1){
      A[i][j] = C[k];
      k=k+1;
    }
  }

  cout<<"Array A"<<endl;
  for(i=0; i<n; i=i+1){
    for(j=0;j<n;j+=1){
      cout<<A[i][j]<<"   ";
    }
    cout<<"\n";
  }

  //Simular una multiplicacion matricial:   x = A * b , elemento a elemento
  //es decir  x_i =  Sumatorio_j_0^n-1  A_ij * b_j
  double sum=0;
  for(i=0;i<=n-1;i++){
    sum = 0;
    for(j=0;j<=n-1;j++){
      sum = sum + A[i][j] * b[j];
    }
    x[i] = sum;
  }

  cout<<"Array x "<<endl;
  for(i=0;i<=n-1;i++){
    cout<<x[i]<<endl;
  }
  
  cout<<"Array x "<<endl;
  for(double y: x){
    cout<<y<<endl;
  }
  
}
