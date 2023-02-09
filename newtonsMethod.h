#include <complex.h>
#include <math.h>
#include "syntheticDivide.h"
#ifndef NEWTONS_METHOD_H
#define NEWTONS_METHOD_H
#include <unistd.h>

complex double f(complex double x, complex double coeffs[], int n)
{
  complex double result = 0;
  int i;

  for (i = 0; i <= n; i++){
      result = result + pow(x,i) * coeffs[i];
    }

  return result;
}

complex double df(complex double x, complex double coeffs[], int degree)
{
  complex double result = 0;
  int i;
  for (i = 1; i <= degree; i++){
      result = result + pow(x,i-1) * i * coeffs[i];
    }
  return result;
}

complex double newtonsMethod(complex double x, complex double coeffs[],
			     int degree)
{
  complex double tolerance = 0.0001 + .0001*I,
	  result[degree+1];
  int i = 0;
  complex double fVal, dfVal;
  do{
      syntheticDivide(coeffs, degree,x, result, &fVal);
      syntheticDivide(result, degree,x, result, &dfVal);
      //fVal  =  f(x, coeffs, degree);
      //dfVal = df(x, coeffs, degree);
      x = x - (fVal/ dfVal);
      i++;	
    } while (i < 50);//((fVal) > cabs(tolerance));
  return x;
}

#endif
