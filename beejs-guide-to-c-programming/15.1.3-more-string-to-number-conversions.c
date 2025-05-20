#include <stdio.h>
#include <stdlib.h>

int main (void) {
  char *s = "34x90";
  char *badstr;

  unsigned long int x = strtoul(s, &badstr, 10);

  printf("connnversion to unsigned long gave: %lu\n", x);
  printf("invalid character: %s\n", badstr);

  return 0;
}
