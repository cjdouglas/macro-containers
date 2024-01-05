#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>
#include <stdlib.h>

#define INCLUDE_LIST(TYPE) _GENERATE_LIST_TYPES(TYPE) _GENERATE_LIST_IMPL(TYPE)

#define _GENERATE_LIST_TYPES(TYPE)            \
  struct _list_node_##TYPE {                  \
    TYPE value;                               \
    struct _list_node_##TYPE* next;           \
  };                                          \
                                              \
  struct list_##TYPE {                        \
    struct _list_node_##TYPE* root;           \
    struct _list_node_##TYPE* tail;           \
    int (*compare)(const TYPE*, const TYPE*); \
    int size;                                 \
  };

#define _GENERATE_LIST_IMPL(TYPE)                                         \
  void list_##TYPE##_init(struct list_##TYPE* list,                       \
                          int (*compare)(const TYPE*, const TYPE*)) {     \
    list->root = calloc(1, sizeof(struct _list_node_##TYPE));             \
    list->tail = list->root;                                              \
    list->compare = compare;                                              \
    list->size = 0;                                                       \
  }                                                                       \
                                                                          \
  void list_##TYPE##_free(struct list_##TYPE* list) {                     \
    struct _list_node_##TYPE* current = list->root;                       \
    while (current) {                                                     \
      struct _list_node_##TYPE* prev = current;                           \
      current = current->next;                                            \
      free(prev);                                                         \
    }                                                                     \
  }                                                                       \
                                                                          \
  void list_##TYPE##_add(struct list_##TYPE* list, TYPE value) {          \
    struct _list_node_##TYPE* next =                                      \
        calloc(1, sizeof(struct _list_node_##TYPE));                      \
    next->value = value;                                                  \
    next->next = NULL;                                                    \
    list->tail->next = next;                                              \
    list->size++;                                                         \
  }                                                                       \
                                                                          \
  void list_##TYPE##_remove(struct list_##TYPE* list, const TYPE* item) { \
    struct _list_node_##TYPE* prev = list->root;                          \
    struct _list_node_##TYPE* current = list->root->next;                 \
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
  bool list_##TYPE##_contains(const struct list_##TYPE* list,             \
                              const TYPE* item) {                         \
    struct _list_node_##TYPE* current = list->root;                       \
    while (current) {                                                     \
      if (list->compare(&current->value, item) == 0) {                    \
        return true;                                                      \
      }                                                                   \
      current = current->next;                                            \
    }                                                                     \
    return false;                                                         \
  }                                                                       \
  int list_##TYPE##_size(struct list_##TYPE* list) { return list->size; }

#endif  // _LIST_H
