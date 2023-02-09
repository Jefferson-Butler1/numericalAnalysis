#ifndef SYNTHETIC_DIVIDE_H
#define SYNTHETIC_DIVIDE_H

#include <complex.h>

#define MAX_DEGREE 20

void syntheticDivide(complex double poly[], int degree,
		     complex double constant,
		     complex double result[],
		     complex double remainder[])
{
    int i;
    complex double temp[MAX_DEGREE + 1];

    for (i = 0; i <= degree; i++){
        temp[i] = poly[i];
    }
    
    for(i = degree-1; i >= 0; i --){
	poly[i] += constant * poly[i+1];
    }
    remainder[0] = poly[0];
    for(i = 0; i < degree; i++){
	result[i] = poly[i+1];
    }
/*
    for (i = 0; i < degree; i++){
        result[i] = temp[0] / constant;
        temp[0] = 0;

        for (int j = 1; j <= degree - i; j++){
            temp[j - 1] = result[i] * constant + temp[j];
        }
    }

    result[degree] = temp[0];
    remainder[0] = 0;
*/
}

#endif
