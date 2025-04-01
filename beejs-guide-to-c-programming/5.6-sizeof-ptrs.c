#include <stdio.h>

int main (void) {
  int *i;
  printf("%zu\n", sizeof(int*));
  printf("%zu\n", sizeof(i));
  printf("%zu\n", sizeof(*i));
  return 0;
}
