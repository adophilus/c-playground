#include <stdio.h>

int main(void) {
  volatile int *x;

  printf("x = %p", (void* )x);

  return 0;
}
