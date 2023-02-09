#include "imports.c"


double x = 0;
/**
takes user input to attempt to recursively
solve a polynomial for its roots 
**/

int main(){
  printf("Starting x?\n");
  scanf("%lf", &x);

  for(int i = 0; i < 30; i++){
    x = (x+2)/(x+1);
    printf("%20.16lf\n", x);
  }
}
