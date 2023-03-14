#include "imports.c"

double f(double x);

int main(){
	int sections;	
	double xLow, xHigh;
	//find interval
	printf("Enter xLow\n"); 
	scanf("%lf", &xLow);
	printf("Enter xHigh\n"); 
	scanf("%lf", &xHigh);
	//find number of reimann summs
	printf("enter number of reimann sections\n");
	scanf("%d", &sections);

	//iterate through sections
	double sumLeft = 0, 
	       sumTrap = 0,
		width = (xHigh - xLow) / sections;
	double x = xLow, fval = f(x), fNext = f(x+width);

	x = xLow;
	sumTrap = (f(xLow) + f(xHigh)) / 2;
	for(int i = 1; i < sections; i++){
		x += width;
		sumTrap += f(x);
	}
	sumLeft *= width;
	sumTrap *= width;
	printf("Your integral using Trapezoid is \t%lf\n", sumTrap);
}

double f(double x){
	return  x*x*x*x + 4 * (x*x*x) + 6 * (x*x) - 8 * x + 1; 
}
