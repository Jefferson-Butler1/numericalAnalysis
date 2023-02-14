#include "imports.c"
#include "syntheticDivide.h"
#include <complex.h>

int main(){
   printf("entered main\n");
   complex double poly[10] = {144, -60, -2, 2}, 
	constant = 3 + 0*I, result[10],
	*remainder;
   int degree = 3;
   printf("entering synthetic\n");
   syntheticDivide(poly, degree, constant, 
		   result, remainder);
   for(int i = degree; i >= 0 ; i-- ){
	printf("(%2.0lf + %2.0lfi x^%d) + ", 
		creal(result[i]),
		cimag(result[i]), 
		i);
   }
   printf("\n");

}
