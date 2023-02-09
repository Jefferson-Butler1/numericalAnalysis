#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "syntheticDivide.h"
#include "newtonsMethod.h"

#define MAX_DEGREE 20
#define TOLERANCE 0.0001

int main()
{
    int degree, i;
    complex double poly[MAX_DEGREE + 1];
    complex double root, result[MAX_DEGREE + 1],
      remainder[MAX_DEGREE + 1];
    double tempImag, tempReal;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    printf("Enter the coefficients of the polynomial:\n");
    for (i = degree; i >= 0; i--){
	scanf("%lf",&tempReal);
	poly[i] = tempReal + 0 * I;
    }

    for (i = 1; i <= degree; i++)
    {
	for(int j = 0; j <= degree; j++){
	  printf("%lfx^%d ", creal(poly[j]), j);
	}
	printf("\n");
	root = newtonsMethod(1, poly, degree, TOLERANCE);

        syntheticDivide(poly, degree, root, result, remainder);

        degree--;
        for (int j = 0; j <= degree; j++)
        {
            poly[j] = result[j];
        }
        printf("Root %d: %lf + %lfi\n",
	       i, creal(root), cimag(root));
    }

    printf("Root %d: %lf + %lfi\n",
	   degree + 1, creal(result[0]), cimag(result[0]));

    return 0;
}
