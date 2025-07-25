#ifndef C_ALGORITHMS_CH2_FRACTION

#define C_ALGORITHMS_CH2_FRACTION

typedef struct {
  int numerator;
  int denominator;
} Fraction;

Fraction Fraction_get();

void Fraction_divide(Fraction *fraction, int divisor);

char* Fraction_stringify(Fraction *fraction);

#endif
