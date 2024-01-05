#include <stdio.h>

#include "macro_containers/fwd_list.h"

INCLUDE_FWD_LIST(int)

int compare_int(const int* a, const int* b) { return *a - *b; }

int main() {}
