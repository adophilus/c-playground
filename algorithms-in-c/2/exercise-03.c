#include <stdio.h>
#include <stdlib.h>
#include "./gcd.h"
#include "./Fraction.h"

int main(void) {
  Fraction fraction = Fraction_get();

  char* stringified_fraction = Fraction_stringify(&fraction);

  printf("Entered fraction: %s\n", stringified_fraction);

  free(stringified_fraction);

  int _gcd = gcd(fraction.numerator, fraction.denominator);

  Fraction_divide(&fraction, _gcd);

  stringified_fraction = Fraction_stringify(&fraction);

  printf("The lowest terms of the fraction is: %s\n", stringified_fraction);

  free(stringified_fraction);

  return 0;
}

