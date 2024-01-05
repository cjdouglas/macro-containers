#include <stdio.h>

#include "list.h"

INCLUDE_LIST(int)

int list_int_compare(const int* a, const int* b) { return *a - *b; }

int main() {
  struct list_int list;
  list_int_init(&list, list_int_compare);
  printf("%d\n", list_int_size(&list));
  list_int_add(&list, 10);
  printf("%d\n", list_int_size(&list));

  int item = 9;
  // int* result = list_int_find(&list, &item, list_int_compare);
  // printf("Found item? %d\n", result != NULL);

  // Free
  list_int_free(&list);
}
