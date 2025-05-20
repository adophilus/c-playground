#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  double sum = 0;

  for (int i = 1; i < argc; i++) {
    char *err = NULL;
    double num = strtod(argv[i], &err);
    if (*err != '\0') {
      fprintf(stderr, "Invalid number: '%s'\n", err);
      return 1;
    }
    sum += num;
  }

  printf("%f\n", sum);

  return 0;
}
