#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *linked_list_initialize(int value) {
  struct node *head;

  head = (struct node *) malloc(sizeof(*head));
  head->value = value;
  head->next = NULL;

  return head;
}

void linked_list_deinitialize(struct node *node) {
  if (node->next != NULL) {
    linked_list_deinitialize(node->next);
    return;
  }

  free(node);
}

struct node *linked_list_delete_next(struct node *n) {
  struct node *return_node = n->next;
  n->next = n->next->next;
  return return_node;
}

struct node* linked_list_insert_after(struct node *n, int value) {
  struct node *next_node = n->next;
  struct node *new_node = malloc(sizeof(*new_node));
  new_node->value = value;
  new_node->next = next_node;

  n->next = new_node;

  return new_node;
}

void linked_list_display(struct node *n) {

  for (struct node *current_node = n; current_node != NULL; current_node = current_node->next) {
    printf("[ %d ]->", current_node->value);
  }

  printf("\n");
}

int main(void) {
  struct node *list = linked_list_initialize(10);

  linked_list_display(list);
  linked_list_insert_after(list, 20);

  linked_list_display(list);
  struct node *thirty_node = linked_list_insert_after(list, 30);

  linked_list_display(list);
  linked_list_insert_after(thirty_node, 40);

  linked_list_display(list);
  linked_list_delete_next(list);

  linked_list_display(list);
  linked_list_deinitialize(list);
  
  return 0;
}

