#ifndef SWAPBACK_LIST_H
#define SWAPBACK_LIST_H

typedef struct {
  void *data;
  struct Node *next;
  struct Node *prev;
} node;

typedef struct {
  node *head;
  node *tail;
} swapbacklist;

swapbacklist *newSwapbackList();

void addListNode(swapbacklist *list, void *ptr);
void removeListNode(swapbacklist *list, int pos);

#endif
