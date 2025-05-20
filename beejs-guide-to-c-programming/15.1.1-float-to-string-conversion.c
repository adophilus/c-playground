#include <stdio.h>
#include <stdlib.h>

void update_name(char **name) {
  *name = "Updated";
}

int main (void) {
  char s[10];
  float f = 3.14159;

  snprintf(s, 10, "%f\n", f);

  printf("The value of pi is: %s\n", s);

  return 0;
}
