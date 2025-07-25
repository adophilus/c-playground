#include <stdio.h>
#include "./gcd.h"

int main(void) {
  int x = 12346, y = 56784, z = 809378;

  int _gcd = gcd(gcd(x, y), z);

  printf("The gcd of %d, %d, and %d is %d\n", x, y, z, _gcd);

  return 0;
}
