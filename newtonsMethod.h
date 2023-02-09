#include <complex.h>
#include <math.h>

#ifndef NEWTONS_METHOD_H
#define NEWTONS_METHOD_H
#include <unistd.h>

complex double f(complex double x, complex double coeffs[], int n)
{
  complex double result = 0;
  int i;

  for (i = 0; i <= n; i++)
    {
      result = result + pow(x,i) * coeffs[i];
    }

  return result;
}

complex double df(complex double x, complex double coeffs[], int degree)
{
  complex double result = 0;
  int i;

  for (i = 1; i <= degree; i++)
    {
      result = result + pow(x,i-1) * i * coeffs[i];
    }
  if(result == 0){
    printf("Df = 0\n");
  }
  return result;
}

complex double newtonsMethod(complex double x, complex double coeffs[],
			     int degree, double tolerance)
{
  printf("Entering newtonsMethod() %lf + %lfI\n", creal(x), cimag(x));
  complex double x1;
  int i = 0;
  double fVal, dfVal;
  do
    {
      fVal  =  f(x, coeffs, degree);
      dfVal = df(x, coeffs, degree);
      x = x - (fVal/ dfVal);
      i++;	
      /* printf("%2d: %lf + %lfI\n", i, creal(x), cimag(x)); */
      /* printf(" f: %lf, df: %lf\n", cabs(fVal), dfVal); */
      //sleep(1);
    } while (cabs(fVal) > tolerance);

  return x;
}

#endif
