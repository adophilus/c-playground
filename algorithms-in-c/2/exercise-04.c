#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int convert(char* stringified_number) {
  int len = strlen(stringified_number);
  int value = 0;

  for (int i = len; i > 0; i--) {
    char current_string_digit = stringified_number[len - i];
    int current_digit = atoi(&current_string_digit);
    int current_digit_to_right_power = current_digit * pow(10, i - 1);

    value += current_digit_to_right_power;
  }

  return value;
}

int main (void) {
  char* user_input = malloc(1024);
  
  printf("Enter a number: ");
  scanf("%s", user_input);

  int converted_user_input = convert(user_input);
  printf("The value of the converted user input is: %d\n", converted_user_input);

  free(user_input);

  return 0;
}
