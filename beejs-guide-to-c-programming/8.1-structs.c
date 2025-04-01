#include <stdio.h>
#include <string.h>

struct Person {
  char first_name[100];
  char last_name[100];
  int *age;
};

void display_person(struct Person *person);

void override_person(struct Person *person) {
  strcpy(person->first_name, "Johnnn");
  /* person->first_name = "John"; */
  person->last_name = "Doe";
  *person->age = 10;

  display_person(person);
}

void display_person(struct Person *person) {
  printf("\tFirst name: %s (%p)\n", person->first_name, (void*)person->first_name);
  printf("\tLast name: %s (%p)\n", person->last_name, (void*)person->last_name);
  printf("\tAge: %d (%p)\n", *person->age, (void*)person->age);
}

int main (void) {
  char* name = "Uchenna Ofoma";
  printf("name: %s\n", name);
  name[0] = 'X';
  /* strcpy(name, "Charles"); */
  /* *name = "Charles Dickson"; */
  printf("name: %s\n", name);

  int austins_age = 20;

  struct Person austin = {
      .first_name = "Austin",
      .last_name = "Chris",
      .age = &austins_age,
  };

  struct Person fake_austin = {
    .first_name = austin.first_name,
    .last_name = austin.last_name,
    .age = austin.age,
  };

  printf("----> BEFORE\n");
  printf("Printing Austin's details...\n");
  display_person(&austin);

  printf("Printing Fake Austin's details...\n");
  display_person(&fake_austin);

  printf("Overriding Austin...\n");
  override_person(&austin);

  printf("----> AFTER\n");
  printf("Printing Austin's details...\n");
  display_person(&austin);

  printf("Printing Fake Austin's details...\n");
  display_person(&fake_austin);

  return 0;
}
