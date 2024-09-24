double prodescalar(double H[], double * p, int n){
  double result;
  result = 0;
  for(int i=0;i<n;i+=1){
    result = result + H[i]*p[i];
  }
  return result;
}

void prodescalar(double H[], double * p, int n, double &result){
  result = 0;
  for(int i=0;i<n;i+=1){
    result = result + H[i]*p[i];
  }
}
