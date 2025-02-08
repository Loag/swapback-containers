#include "swapback-list.h"
#include <stdlib.h>

#pragma clang diagnostic ignored "-Wincompatible-pointer-types"

swapbacklist *newSwapbackList(void *ptr) {
  node *n = malloc(sizeof(node));
  n->next = NULL;
  n->prev = NULL;
  n->data = ptr;

  swapbacklist *s = malloc(sizeof(swapbacklist));
  s->head = n;
  s->tail = n;
  return s;
}

void addListNode(swapbacklist *list, void *ptr) {
  if (list != NULL) {
    node *newTail = malloc(sizeof(node));

    // if head and tail exist
    if (list->head != NULL && list->tail != NULL) {

      newTail->prev = list->tail;
      newTail->next = NULL;
      newTail->data = ptr;

      // set the current tails next to the new tail
      list->tail->next = newTail;

      list->tail = newTail;
    } else {
      list->head = newTail;
      list->tail = newTail;
    }
  }
}

// if we had the length we could probably be
// marginally faster since we could chose to
// iterate from the front or back
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
