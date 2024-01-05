#ifndef _MC_TEST_UTILS_H
#define _MC_TEST_UTILS_H

#include <stdint.h>

typedef struct {
  int value;
  char text[32];
} simple;

typedef struct {
  uint64_t value;
  char long_text[128];
  simple** children;
} complex;

int compare_int(const int* a, const int* b) { return *a - *b; }

int compare_simple(const simple* a, const simple* b) {
  return a->value - b->value;
}

int compare_complex(const complex* a, const complex* b) {
  return a->value - b->value;
}

#endif  // _MC_TEST_UTILS_H
