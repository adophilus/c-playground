#include <stdio.h>

int main (void) {
  int a[5] = { 10, 20, 30, 40, 50 };
  void *b = a;

  printf("&a = %p\n", (void*)a);
  printf("*a = %d\n", *a);
  printf("&a + 1 = %p\n", (void*)(a + 1), *(a + 1));
  printf("*(a + 1) = %d\n", *(a + 1));

  printf("&b = %p\n", b);
  printf("*b = %d\n", *(int*)b);
  printf("&b + 1 = %p\n", (b + 1));
  printf("*(b + 1) = %d\n", *(int*)(b + 1));

  return 0;
} 
