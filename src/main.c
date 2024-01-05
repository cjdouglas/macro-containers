#include <stdio.h>

#include "macro_containers/fwd_list.h"

INCLUDE_FWD_LIST(int)

int compare_int(const int* a, const int* b) { return *a - *b; }

int main() {
  struct fwd_list_int list;
  fwd_list_int_init(&list, compare_int);
  printf("%d\n", fwd_list_int_size(&list));
  fwd_list_int_add(&list, 10);
  printf("%d\n", fwd_list_int_size(&list));

  int item = 9;
  // int* result = list_int_find(&list, &item, list_int_compare);
  // printf("Found item? %d\n", result != NULL);

  // Free
  fwd_list_int_free(&list);
}
