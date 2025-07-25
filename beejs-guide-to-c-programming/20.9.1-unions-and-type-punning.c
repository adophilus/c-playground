#include <stdio.h>

union foo {
  float b;
  short a;
};

int main() {
  union foo x;
  x.b = 3.14159;
  /* x.a = 1; */

  printf("%f %d", x.b, x.a);

  return 0;
}
