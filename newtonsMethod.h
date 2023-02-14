#include <complex.h>
#include <math.h>
#include "syntheticDivide.h"
#ifndef NEWTONS_METHOD_H
#define NEWTONS_METHOD_H
#include <unistd.h>

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
      x = x - (fVal/ dfVal);
      i++;	
    } while (i < 5000);//((fVal) > cabs(tolerance));
  return x;
}

#endif
