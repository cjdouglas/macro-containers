#ifndef _MC_FWD_LIST_H
#define _MC_FWD_LIST_H

#include <stdbool.h>
#include <stdlib.h>

#define INCLUDE_FWD_LIST(TYPE) \
  _GENERATE_FWD_LIST_TYPES(TYPE) _GENERATE_FWD_LIST_IMPL(TYPE)

#define _GENERATE_FWD_LIST_TYPES(TYPE)        \
  struct _fwd_list_node_##TYPE {              \
    TYPE value;                               \
    struct _fwd_list_node_##TYPE* next;       \
  };                                          \
                                              \
  struct fwd_list_##TYPE {                    \
    struct _fwd_list_node_##TYPE* root;       \
    struct _fwd_list_node_##TYPE* tail;       \
    int (*compare)(const TYPE*, const TYPE*); \
    int size;                                 \
  };

#define _GENERATE_FWD_LIST_IMPL(TYPE)                                     \
  void fwd_list_##TYPE##_init(struct fwd_list_##TYPE* list,               \
                              int (*compare)(const TYPE*, const TYPE*)) { \
    list->root = calloc(1, sizeof(struct _fwd_list_node_##TYPE));         \
    list->tail = list->root;                                              \
    list->compare = compare;                                              \
    list->size = 0;                                                       \
  }                                                                       \
                                                                          \
  void fwd_list_##TYPE##_free(struct fwd_list_##TYPE* list) {             \
    struct _fwd_list_node_##TYPE* current = list->root;                   \
    while (current) {                                                     \
      struct _fwd_list_node_##TYPE* prev = current;                       \
      current = current->next;                                            \
      free(prev);                                                         \
    }                                                                     \
  }                                                                       \
                                                                          \
  void fwd_list_##TYPE##_add(struct fwd_list_##TYPE* list, TYPE value) {  \
    struct _fwd_list_node_##TYPE* next =                                  \
        calloc(1, sizeof(struct _fwd_list_node_##TYPE));                  \
    next->value = value;                                                  \
    next->next = NULL;                                                    \
    list->tail->next = next;                                              \
    list->size++;                                                         \
  }                                                                       \
                                                                          \
  void fwd_list_##TYPE##_remove(struct fwd_list_##TYPE* list,             \
                                const TYPE* item) {                       \
    struct _fwd_list_node_##TYPE* prev = list->root;                      \
    struct _fwd_list_node_##TYPE* current = list->root->next;             \
    while (current) {                                                     \
      if (list->compare(&current->value, item) == 0) {                    \
        prev->next = current->next;                                       \
        free(current);                                                    \
        return;                                                           \
      }                                                                   \
      current = current->next;                                            \
    }                                                                     \
  }                                                                       \
                                                                          \
  bool fwd_list_##TYPE##_contains(const struct fwd_list_##TYPE* list,     \
                                  const TYPE* item) {                     \
    struct _fwd_list_node_##TYPE* current = list->root;                   \
    while (current) {                                                     \
      if (list->compare(&current->value, item) == 0) {                    \
        return true;                                                      \
      }                                                                   \
      current = current->next;                                            \
    }                                                                     \
    return false;                                                         \
  }                                                                       \
  int fwd_list_##TYPE##_size(struct fwd_list_##TYPE* list) {              \
    return list->size;                                                    \
  }

#endif  // _MC_FWD_LIST_H