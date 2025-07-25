#include <stdio.h>
#include <threads.h>

int main(void) {
  for (int i = 10; i >= 0; i--) {
    printf("\r T minus %d second%s...\b", i, i != 1 ? "s" : "");
    fflush(stdout);
    thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);
  }
  printf("\rLiftoff!                                   \n");
  return 0;
}
