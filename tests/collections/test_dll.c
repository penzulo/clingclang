#include "mylib/collections/dll.h"
#include "mylib/memory.h"
#include "mylib/string.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_standard_case(void) {
  int numbers[] = {10, 20, 30, 40, 50};
  int n = sizeof(numbers) / sizeof(int);

  LinkedList *list = dll_create();
  for (int i = 0; i < n; dll_push_back(list, &numbers[i]), i++) {}
  DllIterator *it = dll_iter_create(list);

  for (int i = 0; i < n; i++) {
    assert(numbers[i] == *(int *)dll_iter_next(it));
  }

  dll_iter_destroy(it);
  dll_destroy(list);
  puts("Test 1 Passed: Array initialization");
}

void test_clear_list(void) {
  int numbers[] = {10, 20, 30, 40, 50};
  int n = sizeof(numbers) / sizeof(int);
  LinkedList *list = dll_create();
  for (uint8_t i = 1; i < n; dll_push_back(list, &numbers[i]), i++) {}

  dll_clear(list);

  assert(!dll_front_node(list));
  assert(!dll_back_node(list));
  assert(dll_size(list) == 0);

  dll_destroy(list);
  puts("Test 2 Passed: Clearing a Linked List");
}

void test_push_operation(void) {
  int back[] = {10, 20, 30, 40, 50};
  int front[] = {60, 70, 80, 90, 100};
  int expected[] = {100, 90, 80, 70, 60, 10, 20, 30, 40, 50};

  int nelems = sizeof(back) / sizeof(int);
  int nexpected = sizeof(expected) / sizeof(int);

  LinkedList *list = dll_create();

  for (int i = 0; i < nelems; i++) {
    dll_push_front(list, &front[i]);
    dll_push_back(list, &back[i]);
  }

  DllIterator *it = dll_iter_create(list);
  for (int i = 0; i < nexpected; i++) {
    assert(expected[i] == *(int *)dll_iter_next(it));
  }
  dll_iter_destroy(it);

  assert(dll_size(list) == 10);

  dll_destroy(list);
  puts("Test 3 Passed: Expected behaviour of push operations.");
}

void test_pop_operation(void) {
  int numbers[] = {11, 22, 33, 44, 55};
  int n = sizeof(numbers) / sizeof(int);
  LinkedList *list = dll_create();

  for (int i = 0; i < n; dll_push_back(list, &numbers[i]), i++) {}
  for (int i = 0; i < n; i++) {
    assert(*(int *)dll_pop_back(list) == numbers[n - 1 - i]);
  }

  assert(!dll_size(list));
  dll_destroy(list);
  puts("Test 4 Passed: Expected behaviour of pop operations.");
}

/**
 * @brief Simulates Music Playlist
 *
 * This test was designed to check how a Doubly Linked List
 * would be used in real scenarios. A music playlist can be
 * implemented using DLLs as we need functionality to skip and
 * replay songs.
 * Surprisingly, the usage makes sense where a playlist needs to
 * be looped or when a particular song needs to be looped.
 */
void test_music_playlist(void) {
  char *songs[] = {
      "99 Problems",
      "Old Black Magic",
      "Summertime Voodoo",
  };

  int nsongs = sizeof(songs) / sizeof(uintptr_t);
  LinkedList *list = dll_create();

  for (int i = 0; i < nsongs; i++) {
    char *new_song = malloc(strlength_a(songs[i]));
    if (!new_song) return;
    memcopy(songs[i], new_song, strlength_a(songs[i]));
    dll_push_back(list, new_song);
  }

  DllIterator *it = dll_iter_create(list);
  for (int i = 0; i < nsongs; i++) {
    assert(strcompare(songs[i], (const char *)dll_iter_next(it)) == 0);
  }
  dll_iter_destroy(it);

  for (; !dll_is_empty(list); free(dll_pop_front(list))) {}
  dll_destroy(list);
  puts("Test 5 Passed: Playlist Created");
}

void run_all_tests(void) {
  test_standard_case();
  test_clear_list();
  test_push_operation();
  test_pop_operation();
  test_music_playlist();
}

int main(void) {
  run_all_tests();
  return 0;
}
