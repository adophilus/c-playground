#include <stdio.h>

typedef struct {
  char *name;
  int leg_count;
  int speed;
} Animal;

void display_animal(Animal *animal) {
  printf("Name = %s\nLegs = %d\nSpeed = %d\n", animal->name, animal->leg_count, animal->speed);
}

int main (void) {
  Animal lion = { .name = "Lion", .leg_count = 4, .speed = 40 };

  display_animal(&lion);

  return 0;
}
