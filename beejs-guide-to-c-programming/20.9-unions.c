#include <stdio.h>

union foo {
  int a, b, c;
  float g, h;
  char i, j, k;
};

int main() {
  union foo x;
  x.a = 1;
  x.b = 2;
  x.c = 3;
  x.g = 3.142;

  printf("%d %d %d %f", x.a, x.b, x.c, x.g);

  return 0;
}
