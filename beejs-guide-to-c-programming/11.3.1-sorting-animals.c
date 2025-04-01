#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int leg_count;
} Animal;

int compare_fn (const void *elem1, const void *elem2) {
  const Animal *animal1 = elem1;
  const Animal *animal2 = elem2;

  if (animal1->leg_count > animal2->leg_count)
    return 1;
  else if (animal1->leg_count < animal2->leg_count)
    return -1;
  else
    return 0;
}

int main (void) {
  Animal animals[] = {
    {.name = "Dog", .leg_count = 4},
    {.name = "Lion", .leg_count = 4},
    {.name = "Ostrich", .leg_count = 2},
    {.name = "Snake", .leg_count = 0},
  };

  qsort(animals, 4, sizeof(Animal), compare_fn);

  for (int i = 0; i < 4; i++)
    printf("%d: %s\n", animals[i].leg_count, animals[i].name);
}
