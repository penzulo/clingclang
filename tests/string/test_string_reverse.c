#include "mylib/string.h"
#include <assert.h>
#include <stdio.h>

void test_standard_case(void) {
  char name[] = "Bhargav";
  strreverse(name);
  assert(!strcompare(name, "vagrahB"));
  puts("Test 1 Passed: Standard Case.");
}

void test_sentence_case(void) {
  char sentence[] = "This is a sentence.";
  strreverse(sentence);

  assert(!strcompare(sentence, ".ecnetnes a si sihT"));
  puts("Test 2 Passed: Sentence Case.");
}

void run_all_tests(void) {
  test_standard_case();
  test_sentence_case();
}

int main(void) {
  run_all_tests();
  return 0;
}
