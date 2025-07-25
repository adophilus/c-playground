#include <stdio.h>

union foo {
  float b;
  short a;
};

int main (void) {
  union foo x;
  int *foo_int_p = (int*)&x;
  float *foo_float_p = (float *)&x;

  x.a = 12;
  printf("%d\n", x.a);
  printf("%d\n", *foo_int_p);

  return 0;
}
