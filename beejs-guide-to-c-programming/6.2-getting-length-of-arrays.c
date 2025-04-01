#include <stdio.h>

// this won't work as expected becasue `sizeof(x)` returns the sizeof the pointer `x` rather than the sizeof the whole array
size_t get_length_of_array(int *x) {
  return (sizeof(x) / sizeof(x[0]));
}

int main (void) {
  int i[10];

  printf("%zu\n", sizeof(i));
  printf("%zu\n", get_length_of_array(i));
  return 0;
}
