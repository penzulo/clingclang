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
  return (list && list->tail) ? list->tail : NULL;
}

void *dll_front(LinkedList *list) {
  return (list && list->head) ? list->head : NULL;
}

size_t dll_size(LinkedList *list) { return list->size; }

uint8_t dll_is_empty(LinkedList *list) {
  return !list->head && !list->tail && !list->size;
}

uint8_t dll_push_back(LinkedList *list, void *data) {
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) return 1;
  node->data = data;
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

void dll_clear(LinkedList *list) {
  for (; list->head; dll_pop_back(list)) {}
}

void dll_free(LinkedList *list) {
  dll_clear(list);
  free(list);
}
