#include "mylib/collections/dll.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct ListNode {
  void *data;
  struct ListNode *prev;
  struct ListNode *next;
} ListNode;

typedef struct LinkedList {
  ListNode *head;
  ListNode *tail;
  size_t size;
} LinkedList;

typedef struct DllIterator {
  ListNode *current;
} DllIterator;

LinkedList *dll_create(void) {
  LinkedList *list = malloc(sizeof(LinkedList));
  if (!list) return NULL;
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

ListNode *dll_back_node(const LinkedList *list) {
  return (list && list->tail) ? list->tail : NULL;
}

ListNode *dll_front_node(const LinkedList *list) {
  return (list && list->head) ? list->head : NULL;
}

size_t dll_size(const LinkedList *list) { return list ? list->size : 0; }

int dll_is_empty(const LinkedList *list) { return !list || list->size == 0; }

int dll_push_back(LinkedList *list, void *data) {
  if (!list) return -1;
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) return -1;
  node->data = data;
  node->next = NULL;
  node->prev = list->tail;
  if (list->tail) list->tail->next = node;
  else list->head = node;
  list->tail = node;
  list->size++;
  return 0;
}

int dll_push_front(LinkedList *list, void *data) {
  if (!list) return -1;
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) return -1;
  node->data = data;
  node->next = list->head;
  node->prev = NULL;
  if (list->head) list->head->prev = node;
  else list->tail = node;
  list->head = node;
  list->size++;
  return 0;
}

void *dll_pop_back(LinkedList *list) {
  if (!list || !list->tail) return NULL;
  ListNode *old = list->tail;
  void *data = old->data;
  list->tail = old->prev;
  if (list->tail) list->tail->next = NULL;
  else list->head = NULL;
  list->size--;
  free(old);
  return data;
}

void *dll_pop_front(LinkedList *list) {
  if (!list || !list->head) return NULL;
  ListNode *old = list->head;
  void *data = old->data;
  list->head = old->next;
  if (list->head) list->head->prev = NULL;
  else list->tail = NULL;
  list->size--;
  free(old);
  return data;
}

void dll_clear(LinkedList *list) {
  if (!list) return;
  ListNode *current = list->head;

  while (current) {
    ListNode *next = current->next;
    free(current);
    current = next;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void dll_destroy(LinkedList *list) {
  if (!list) return;
  dll_clear(list);
  free(list);
}

DllIterator *dll_iter_create(LinkedList *list) {
  if (!list) return NULL;
  DllIterator *iter = malloc(sizeof(DllIterator));
  if (!iter) return NULL;

  iter->current = list->head;
  return iter;
}

void *dll_iter_next(DllIterator *iter) {
  if (!iter || !iter->current) return NULL;
  void *data = iter->current->data;
  iter->current = iter->current->next;
  return data;
}

void dll_iter_destroy(DllIterator *iter) { free(iter); }
