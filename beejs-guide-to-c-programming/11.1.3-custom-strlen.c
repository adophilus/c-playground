#include <stdio.h>
#include <string.h>

size_t custom_strlen(char* s) {
  char *e = s;

  while (*e++ != '\0');

  return e - s;
}

int main (void) {
  char *s = "hello there little 😾😾😾";
  printf("Here's the string: %s\n", s);
  printf("The length of the string should be 22 bytes but it is %zu bytes\n", strlen(s));

  return 0;
}
