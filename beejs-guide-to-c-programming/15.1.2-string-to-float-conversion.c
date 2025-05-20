#include <stdio.h>
#include <stdlib.h>

int main (void) {
  char *pi = "3.14159";

  float f = atof(pi);

  printf("the (float) value of pi is: %f\n", f);

  return 0;
}
