#include <stdio.h>
#include "./gcd.h"

int main (void) {
  int x = 12345, y = 56789;

  gcd_mod_debug(x, y);

  return 0;
}
