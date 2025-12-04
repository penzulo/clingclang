#include "mylib/collections/dll.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

void test_standard_case(void) {
  uint8_t numbers[5] = {10, 20, 30, 40, 50};
  uint8_t *pnums = numbers;
  LinkedList *list = dll_new(numbers);

  for (uint8_t i = 1; i < 5; dll_push_back(list, &numbers[i]), i++) {}

  for (ListNode *cursor = dll_front(list); cursor;
       pnums++, cursor = cursor->next) {
    assert(*(uint8_t *)cursor->data == *pnums);
  }

  dll_free(list);
  puts("Test 1 Passed: Array initialization");
}

void test_clear_list(void) {
  uint8_t numbers[5] = {10, 20, 30, 40, 50};
  LinkedList *list = dll_new(numbers);
  for (uint8_t i = 1; i < 5; dll_push_back(list, &numbers[i]), i++) {}

  dll_clear(list);

  assert(!dll_front(list));
  assert(!dll_back(list));
  assert(dll_size(list) == 0);

  dll_free(list);
  puts("Test 2 Passed: Clearing a Linked List");
}

void test_push_operation(void) {
  uint8_t back[5] = {10, 20, 30, 40, 50};
  uint8_t front[5] = {60, 70, 80, 90, 100};
  uint8_t expected[10] = {100, 90, 80, 70, 60, 10, 20, 30, 40, 50};
  uint8_t i = 0;

  LinkedList *list = dll_new(back);

  for (uint8_t i = 1; i < 5; dll_push_back(list, &back[i]), i++) {}
  for (uint8_t i = 0; i < 5; dll_push_front(list, &front[i]), i++) {}
  for (ListNode *node = dll_front(list); node; node = node->next, i++) {
    assert(*(uint8_t *)node->data == expected[i]);
  }

  assert(dll_size(list) == 10);

  dll_free(list);
  puts("Test 3 Passed: Expected behaviour of push operations.");
}

void test_pop_operation(void) {
  uint8_t numbers[5] = {11, 22, 33, 44, 55};
  LinkedList *list = dll_new(numbers);

  for (uint8_t i = 1; i < 5; dll_push_back(list, &numbers[i]), i++) {}
  for (uint8_t i = 0; i < 5; i++) {
    assert(*(uint8_t *)dll_pop_back(list) == numbers[4 - i]);
  }

  assert(!dll_size(list));
  dll_free(list);
  puts("Test 4 Passed: Expected behaviour of pop operations.");
}

void run_all_tests(void) {
  test_standard_case();
  test_clear_list();
  test_push_operation();
  test_pop_operation();
}

int main(void) {
  run_all_tests();
  return 0;
}
