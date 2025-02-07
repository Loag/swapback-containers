#include "swapback-list.h"
#include <stdlib.h>

swapbacklist *newSwapbackList() {
  node *n = malloc(sizeof(node));
  n->next = NULL;
  n->prev = NULL;
  n->data = NULL;

  swapbacklist *s = malloc(sizeof(swapbacklist));
  s->head = n;
  s->tail = n;
  return s;
}

void addListNode(swapbacklist *list, void *ptr) {
  node *newTail = malloc(sizeof(node));

  newTail->prev = list->tail;
  newTail->next = NULL;
  newTail->data = ptr;

  list->tail->next = newTail;
  list->tail = newTail;
}

void removeListNode(swapbacklist *list, int pos) {
  int cur = 0;
  node *current = list->head;

  while (cur <= pos) {
    current = current->next;
    cur++;
  }

  // set curs value to the current tails value
  current->data = list->tail->data;

  // get the new tail which is the prev node from tail
  node *newTail = (node *)list->tail->prev;

  // set its next to null
  newTail->next = NULL;

  // free the previous tail and set the tail to the new tail
  free(list->tail);
  list->tail = newTail;
}