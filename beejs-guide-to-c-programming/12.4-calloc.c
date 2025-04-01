#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
  size_t array_size = 1342177280;
  int *p = calloc(array_size, sizeof(int));

  for (size_t i = 0; i < array_size; i++)
    printf("%d, ", p[i]);

  return 0;
}
