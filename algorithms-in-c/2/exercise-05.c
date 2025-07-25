#include <stdio.h>
#include <stdlib.h>

char* binary(int num) {
  char* buffer = malloc(1024);
  int i = 0;

  while (num >= 1) {
    buffer[i] = num % 2 == 0 ? '0' : '1';
    num /= 2;
    i++;
  }

  for (int j = 0; j < i / 2; j++) {
    char t = buffer[(i - 1) - j];
    buffer[(i - 1) - j] = buffer[j];
    buffer[j] = t;
  }

  return buffer;
}

int main(void) {
  int user_input;
  
  printf("Enter a number: ");
  scanf("%d", &user_input);

  printf("The number the user entered: %d\n", user_input);

  char* binary_equivalent = binary(user_input);

  printf("Binary equivalent: %s\n", binary_equivalent);

  free(binary_equivalent);

  return 0;
}
