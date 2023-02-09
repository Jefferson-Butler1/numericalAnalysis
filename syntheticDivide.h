#ifndef SYNTHETIC_DIVIDE_H
#define SYNTHETIC_DIVIDE_H
#include <complex.h>
#define MAX_DEGREE 20
void syntheticDivide(complex double poly[], int degree,
		     complex double constant,
		     complex double result[],
		     complex double *remainder)
{
    int i;
    complex double temp[MAX_DEGREE + 1];
    for (i = 0; i <= degree; i++){
        temp[i] = poly[i];
    }
    for(i = degree-1; i >= 0; i --){
	temp[i] = temp[i] + constant * temp[i+1];
    }
    *remainder = temp[0];
    printf("remainder: %lf\n", creal(*remainder));
    for(int i = 0; i < degree; i++){
	result[i] = temp[i+1];
    }
}
#endif
