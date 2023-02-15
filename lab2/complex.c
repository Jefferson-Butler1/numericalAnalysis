#include "imports.c"


int main(){
	complex a,b,c,d,e,f;
	a = 3+4*I;
	b = 2+3*I;
	c = a+b;
	d = a-b;
	e = a*b;
	f = a/b;
	printf("%lf + %lf I\n", creal(a), cimag(a));
	printf("%lf + %lf I\n", creal(b), cimag(b));
	printf("%lf + %lf I\n", creal(c), cimag(c));
	printf("%lf + %lf I\n", creal(d), cimag(d));
	printf("%lf + %lf I\n", creal(e), cimag(e));
	printf("%lf + %lf I\n", creal(f), cimag(f));
}	
