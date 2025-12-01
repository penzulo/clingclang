#include "mylib/memory.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct ListNode {
  void *data;
  struct ListNode *prev;
  struct ListNode *next;
} ListNode;

typedef struct {
  ListNode *head;
  ListNode *tail;
  size_t size;
} LinkedList;

LinkedList *dll_new(void *data) {
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) return NULL;
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  LinkedList *list = malloc(sizeof(LinkedList));
  if (!list) {
    free(node);
    return NULL;
  }
  list->head = node;
  list->tail = node;
  list->size = 1;
  return list;
}

void *dll_back(LinkedList *list) {
  return (list && list->tail) ? list->tail->data : NULL;
}

void *dll_front(LinkedList *list) {
  return (list && list->head) ? list->head->data : NULL;
}

size_t dll_size(LinkedList *list) { return list->size; }

uint8_t dll_is_empty(LinkedList *list) {
  return !list->head && !list->tail && !list->size;
}

uint8_t dll_push_back(LinkedList *list, void *data, size_t size) {
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) return 1;
  node->data = malloc(size);
  if (!node->data) {
    free(node);
    return 1;
  }
  memcopy(data, node->data, size);
  node->prev = list->tail;
  node->next = NULL;
  if (list->tail) list->tail->next = node;
  else list->head = node;
  list->tail = node;
  list->size++;
  return 0;
}

uint8_t dll_push_front(LinkedList *list, void *data) {
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) return 1;
  node->data = data;
  node->prev = NULL;
  node->next = list->head;
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

LinkedList *dll_from_array(void *array, size_t length, size_t esize) {
  LinkedList *list = dll_new(NULL);
  if (!list) return NULL;
  for (size_t i = 0; i < length; i++) {
    dll_push_back(list, (uint8_t *)array + (i * esize), esize);
  }
  return list;
}

// NOTE: Performs deep copy
LinkedList *dll_from_array1(void *array, size_t length, size_t esize) {
  LinkedList *list = malloc(sizeof(LinkedList));
  if (!list) return NULL;
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  uint8_t *byte_ptr = array;
  for (size_t i = 0; i < length; i++) {
    ListNode *node = malloc(sizeof(ListNode));
    if (!node) return NULL;
    node->data = malloc(esize);
    if (!node->data) {
      free(node->data);
      return NULL;
    }
    memcopy(byte_ptr + (i * esize), node->data, esize);
    node->next = NULL;
    if (list->tail) list->tail->next = node;
    else list->head = node;
    list->tail = node;
    list->size++;
  }
  return list;
}

void dll_free(LinkedList *list) {
  for (; list->head; dll_pop_back(list)) {}
  free(list);
}
