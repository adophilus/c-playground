#include <stdio.h>

int main(void) {
  int p_original[] = {10, 20};
  printf("*p_original = %p\n", (void *)p_original);
  printf("*(p_original + 1) = %p\n", (void *)(p_original + 1));

  const int *p = p_original;
  printf("*p = %p\n", (void *)p);

  int x[] = {30, 40};

  printf("*x = %p\n", (void *)x);
  printf("*(x + 1) = %p\n", (void *)(x + 1));
  printf("*(x + 2) = %p\n", (void *)(x + 2));
  /* printf("*p = %p\n", (void *)p); */
  /* p++; */
  /* p = x; */
  /* printf("*p = %p\n", (void *)p); */

  return 0;
}
