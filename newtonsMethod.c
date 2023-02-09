#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main(){
  double x, f;
  double n;
  int repLimit = 50;
  scanf("%lf", &n);
  for(int i = 0; i < repLimit; i++){
    n = n-(3*n*n*n*n -29*n*n*n +60*n*n + 144*n -448)/
      (12*n*n*n - 87*n*n + 120*n + 144);
    printf("%2d: %lf\n", i, n);
  }
}
