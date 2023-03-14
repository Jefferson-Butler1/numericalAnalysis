#include "imports.c"





int main(){
	double x1,x2,x3,x4;		
	x1 = x2 = x3 = x4 = 0;
	for(int i = 1; i < 15; i++){
		x1 = (498 - 0*x1 - 5*x2 -8*x3 + 2*x4)/100;
		x2 = (834 - 4*x1 - 0*x2 -2*x3 - 6*x4)/200;
		x3 = (6 - 2*x1 - 1*x2 -0*x3 - 4*x4)/10;
		x4 = (255 - 5*x1 - 15*x2 +10*x3 - 0*x4)/50;
	}
	printf("%20.16lf\t%20.16lf\t%20.16lf\t%20.16lf\t\n",
		x1,x2,x3,x4);	
}	
