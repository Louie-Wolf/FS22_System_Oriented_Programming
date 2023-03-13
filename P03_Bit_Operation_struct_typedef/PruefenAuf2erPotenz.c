#include <stdio.h>
#include <stdlib.h>

int main(){
  int a = 32; // any positive number
  printf("Please enter a number");
  scanf("%d",&a);
  
  if(a > 0 && ((a & (a - 1)) == 0)){
    printf("%d is a power of 2\n", a);
  } else {
    printf("%d is not a power of 2\n", a);
  }

  return EXIT_SUCCESS;
}
