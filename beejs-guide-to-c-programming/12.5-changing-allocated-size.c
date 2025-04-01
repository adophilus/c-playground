#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void display_array(int *arr, size_t length) {
  printf("[ ");
  for (size_t i = 0; i < length; i++)
    printf("%d, ", arr[i]);
  printf("]\n");
}

void set_default_array(int *arr, int value, size_t length) {
  for (size_t i = 0; i < length; i++)
    arr[i] = value;
}

int* initialize_array(int value, size_t length) {
  int *p = malloc(sizeof(int) * length);
  set_default_array(p, value, length);
  return p;
}

int* reinitialize_array(int* prev, int value, size_t prev_length, size_t new_length) {
  size_t prev_array_size = sizeof(int) * prev_length;
  size_t new_array_size = sizeof(int) * new_length;

  int *p = malloc(new_array_size);
  memcpy(p, prev, prev_array_size);
  set_default_array(p, value, new_length);

  free(prev);

  return p;
}

int main (void) {
  size_t array_length = 10;
  int default_value = 0;

  int *p = initialize_array(default_value, array_length);
  /* int *p = malloc(sizeof(int) * array_length); */
  /* memset(p, default_value, sizeof(int) * array_length); */

  printf("int *p = %p\n", (void*)p);

  display_array(p, array_length);

  // size_t new_array_length = 20;
  size_t new_array_length = 26843545600; // an array with ints worth 100 GB

  /* p = reinitialize_array(p, 12, array_length, new_array_length); */
  if ((p = realloc(p, sizeof(int) * new_array_length)) == NULL) {
    fprintf(stderr, "Error reallocating!\n");
    return 1;
  }
  memset(p + array_length, default_value, sizeof(int) * (new_array_length - array_length));

  printf("int *p = %p\n", (void*)p);

  display_array(p, new_array_length);

  free(p);

  return 0;
}
