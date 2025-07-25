#include <stdlib.h>
#include <stdio.h>
#include "./Fraction.h"

Fraction Fraction_get() {
  int numerator;
  int denominator;

  printf("Enter the numerator: ");
  scanf("%d", &numerator);
  printf("Enter the denominator: ");
  scanf("%d", &denominator);

  Fraction fraction = { .numerator = numerator, .denominator = denominator };

  return fraction;
}

void Fraction_divide(Fraction *fraction, int divisor) {
  fraction->numerator /= divisor;
  fraction->denominator /= divisor;
}

char* Fraction_stringify(Fraction *fraction) {
  /* int len = 7 + ; */
  char* buffer = malloc(1024);
  sprintf(buffer, "[ %d / %d ]", fraction->numerator, fraction->denominator);
  return buffer;
}
