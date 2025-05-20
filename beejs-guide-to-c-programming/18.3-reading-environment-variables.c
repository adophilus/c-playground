#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *username = getenv("USERNAME");

  if (username == NULL) {
    printf("Cannot find the USERNAME environment variable\n");
    return EXIT_FAILURE;
  }

  printf("Value: %s\n", username);

  return 0;
}
