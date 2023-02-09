#include "imports.c"
#include "syntheticDivide.h"
#include "newtonsMethod.h"
#define MAX_DEGREE 20
#define TOLERANCE 0.0001
int main()
{
    //initioalize vars
    int degree, i;
    complex double poly[MAX_DEGREE + 1];
    complex double root, result[MAX_DEGREE + 1],
      remainder[MAX_DEGREE + 1];
    double tempImag, tempReal;
    //set vars
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    printf("Enter the coefficients of the polynomial:\n");
    for (i = degree; i >= 0; i--){
	scanf("%lf",&tempReal);
	poly[i] = tempReal + 0 * I;
    }
    //solve problem
    for (i = degree; i > 0; i--){
	root = newtonsMethod(1, poly, degree);
        syntheticDivide(poly, degree, root, result, remainder);
        for (int j = 0; j <= degree; j++){
            poly[j] = result[j];
        }
        printf("Root %d: %8.6lf + %8.6lfi\n",
	       i, creal(root), cimag(root));
    }
}
