#include "swapback-list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *create_str(int i) {
  char *result = malloc(50); // Allocate a buffer for the new string

  // Use sprintf to create the string
  sprintf(result, "i am at pos: %i", i);

  return result;
}

int main() {
  swapbacklist *sw = newSwapbackList();
  char *str = create_str(0);
  char *str1 = create_str(1);
  char *str2 = create_str(2);

  addListNode(sw, str);

  char *v = (char *)sw->tail->data;
  printf("%s\n", v);

  addListNode(sw, str1);
  char *v1 = (char *)sw->tail->data;
  printf("%s\n", v1);

  addListNode(sw, str2);

  char *v2 = (char *)sw->tail->data;
  printf("%s\n", v2);

  removeListNode(sw, 1);
  char *v3 = (char *)sw->tail->data;
  printf("%s\n", v3);

  return 0;
}