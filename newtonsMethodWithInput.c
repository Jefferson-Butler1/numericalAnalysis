#include "imports.c"
/*
uses Newton's method at repLimit depth to find a root of the given polynomial 
 */
int newtonsMethod(int repLimit, int degree,
		  double n, double * result,
		  double coefficients []);
int syntheticDivide(int deg, double *rem, double divisor,
		    double coef[],
		    double newCoef[]);

int main(){
  double  remainder, f, n;
  int repLimit = 50, degree;
  complex sumFunc = 0, sumDer = 0;
  double coefficients [degree];
  	
  printf("Enter degree:\n");
  scanf("%d", &degree);
  printf("Enter coefficients:\n");
  for(int i = degree; i >= 0; i--){
    scanf("%lf", &coefficients[i]);
  }
  newtonsMethod(repLimit, degree, 1, &f, coefficients);
  syntheticDivide(degree, &remainder, f, coefficients, coefficients);
  newtonsMethod(repLimit, degree, 1, &f, coefficients);
  printf("reached the end of main, result is %lf!\n", f);
}

int newtonsMethod(int repLimit, int degree,
		  double n, double * result,
		  double coefficients []){
  double sumFunc = 0, sumDer = 0;
  for(int i = 0; i < repLimit; i++){
    for(int j = 0; j <= degree; j++){
      sumFunc += coefficients[j] * pow(n, j);
      if(j > 0){
	sumDer += coefficients[j] * (j) * pow(n,j-1);
      }
    }
    printf("sumFunc: %lf + %lf, sumDer: %lf + %lf\n",
	   creal(sumFunc), cimag(sumFunc), creal(sumDer), cimag(sumDer));
    n = n-sumFunc/sumDer;
    printf("%2d: %lf + %lfI\n", i, creal(n), cimag(n));
    sumFunc = sumDer = 0;
  }
  *result = n;
  return 0;
}

int syntheticDivide(int deg, double *rem, double divisor,
		    double poly[],
		    double newCoef[]){
  double temp [deg+1];
  
  newCoef[0] = poly[0];
  printf("%lf\n", newCoef[0]);

  for(int i = 1; i <= deg; i++){
    newCoef[i] = divisor*newCoef[i-1] + poly[i];
    printf("%lf\n", newCoef[i]);
  }
  *rem = newCoef[deg];
  return 0;
}


