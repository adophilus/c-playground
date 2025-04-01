I recently started learnig about c and I'm currently at the section where they talk about structs. I've already passed the point where they discussed pointers but I wanted to give myself a litle exercise. I wanted to see if changing the values of a struct I created which houses pointers and then setting the values of (another) similar struct to the pointers from the first struct would affect the second struct. Here's my code:

```c
#include <stdio.h>
#include <string.h>

struct Person {
  char *first_name;
  char *last_name;
  int *age;
};

void display_person(struct Person *person);

void override_person(struct Person *person) {
  /* person->first_name[0] = 'M'; */
  /* strcpy(person->first_name, "Johnnn"); */
  person->first_name = "John";
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
  /* char* name = "Uchenna Ofoma"; */
  /* printf("name: %s\n", name); */
  /* name[0] = 'X'; */
  /* strcpy(name, "Charles"); */
  /* *name = "Charles Dickson"; */
  /* printf("name: %s\n", name); */

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
```

Here's the output of the code above:
```
----> BEFORE
Printing Austin's details...
        First name: Austin (0x10005bc)
        Last name: Chris (0x1000528)
        Age: 20 (0x7fffcbfa8b44)
Printing Fake Austin's details...
        First name: Austin (0x10005bc)
        Last name: Chris (0x1000528)
        Age: 20 (0x7fffcbfa8b44)
Overriding Austin...
        First name: John (0x10005b7)
        Last name: Doe (0x1000500)
        Age: 10 (0x7fffcbfa8b44)
----> AFTER
Printing Austin's details...
        First name: John (0x10005b7)
        Last name: Doe (0x1000500)
        Age: 10 (0x7fffcbfa8b44)
Printing Fake Austin's details...
        First name: Austin (0x10005bc)
        Last name: Chris (0x1000528)
        Age: 10 (0x7fffcbfa8b44)
```

I understand why the values printed in the second struct don't match up (because the override function is actually assigning the value of those fields, `first_name` and `last_name`, to new pointers). So I was trying to experiment with it (as you can see in the commented out codes). I tried
```c
int main (void) {
  char name[] = "Uchenna Ofoma";
  printf("name: %s\n", name);
  name[0] = 'X';
  printf("name: %s\n", name);
  return 0;
}
```

Which works without any errors, but then I tried:
```c
int main (void) {
  char* name = "Uchenna Ofoma";
  printf("name: %s\n", name);
  name[0] = 'X';
  printf("name: %s\n", name);
  return 0;
}
```

Which just segfaults. This one also segfaults:
```c
int main (void) {
  char* name = "Uchenna Ofoma";
  printf("name: %s\n", name);
  strcpy(name, "Charles");
  printf("name: %s\n", name);
  return 0;
}
```

I'll paste the strace logs in the next chat.
