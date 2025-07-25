#include <stdio.h>
#include <limits.h>
#include "./gcd.h"

int main (void) {
  int x = INT_MAX;
  int y = x - 1;

  int _gcd = gcd(x, y);

  printf("All things being equal, the gcd of %d and %d should be 1 but it is %d\n", x, y, _gcd);

  return 0;
}
