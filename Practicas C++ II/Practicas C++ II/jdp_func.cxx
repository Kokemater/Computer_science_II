#include <iostream>
using namespace std;

#include "misfunciones.cpp"

int main(){
  const int ndim = 2;
  double V[ndim]={1,2}, W[ndim]={3,4}, r;
  r = prodescalar(V,W,ndim);
  cout<<r<<endl;
  prodescalar(V,W,ndim,r);
  cout<<r<<endl;  
}
