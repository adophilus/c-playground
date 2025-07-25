#include <stdio.h>

typedef enum { VEHICLE, ORGANIC_MATTER } ObjectType;

typedef struct {
  ObjectType type;

  char *name;
  char *model;
} Vehicle;

typedef enum { MALE, FEMALE } Gender;

typedef struct {
  ObjectType type;

  char *name;
  Gender gender;
} Human;

typedef union {
  ObjectType type;
  Vehicle vehicle;
  Human person;
} Object;

Human make_human(char *name, Gender gender) {
  Human human = {.type = ORGANIC_MATTER, .name = name, .gender = gender};

  return human;
}

Vehicle make_vehicle(char *name, char *model) {
  Vehicle vehicle = {.type = VEHICLE, .name = name, .model = model};
  return vehicle;
}

char *gender_to_string(Gender gender) {
  switch (gender) {
  case MALE:
    return "MALE";
  case FEMALE:
    return "FEMALE";
  };
}

int main(void) {
  Object obj;

  Human human = make_human("Marcus", MALE);
  Vehicle vehicle = make_vehicle("Lexus", "G40");

  obj.person = human;
  obj.vehicle = vehicle;

  switch (obj.type) {
  case VEHICLE: {
    Vehicle vehicle = obj.vehicle;
    printf("We got ourselves a vehicle! %s\n", vehicle.name);
    break;
  }
  case ORGANIC_MATTER: {

    Human person = obj.person;
    printf("We got ourselves a person! Name: %s, Gender: %s\n", person.name,
           gender_to_string(person.gender));
    break;
  }
  };

  return 0;
}
