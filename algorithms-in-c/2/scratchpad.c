#include <stdio.h>
#include "./gcd.h"

int main(void) {
  int x = 461952, y = 116298;
  int x = 2, y = 3;

  while (scanf("%d %d", &x, &y) != EOF) {
    if (x > 0 && y > 0) {
      int _gcd1 = gcd(x, y);
      int _gcd2 = gcd2(x, y);
      printf("[gcd] %d %d %d\n", x, y, _gcd1);
      printf("[gcd2] %d %d %d\n", x, y, _gcd2);
    }
  }
}
