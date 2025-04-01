#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *items;
  size_t length;
} Vec;

Vec* init_vec(int initial_value, size_t length) {
  size_t vector_size = (sizeof(int) * length);
  int *items = malloc(sizeof(int) * length);

  for (size_t i = 0; i < length; i++)
    items[i] = initial_value;

  Vec *vec = malloc(vector_size + sizeof(size_t));
  vec->items = items;
  vec->length = length;

  return vec;
}

void display_vector(Vec *vec) {
  printf("[ ");
  for (size_t i = 0; i < vec->length; i++)
    printf("%d, ", vec->items[i]);
  printf("]\n");
}

void free_vector(Vec *vec) {
  free(vec->items);
  free(vec);
}

int main (void) {
  // initialize a vector with 10GB worth of `int`s
  Vec* vec = init_vec(1, 2684354560);

  display_vector(vec);

  free_vector(vec);
}
