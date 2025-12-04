#include "mylib/string.h"
#include <assert.h>
#include <stdio.h>

void test_equal_strings(void) {
  const char s1[] = "Word";
  const char s2[] = "Word";

  assert(strcompare(s1, s2) == 0);
  puts("Test 1 Passed: Equal Strings Case.");
}

void test_greater_string(void) {
  const char s1[] = "word";
  const char s2[] = "words";

  assert(strcompare(s1, s2) == -1);
  puts("Test 2 Passed: `s2` > `s1`");
}

void test_empty_case(void) {
  const char s1[] = "";
  const char s2[] = "";

  assert(!strcompare(s1, s2));
  puts("Test 3 Passed: Empty Strings Case.");
}

void test_aliased_pointer(void) {
  const char sentence[] = "same sentence";

  assert(!strcompare(sentence, sentence));
  puts("Test 4 Passed: Pointer Aliasing Case.");
}

void run_all_tests(void) {
  test_equal_strings();
  test_greater_string();
  test_empty_case();
  test_aliased_pointer();
}

int main(void) {
  run_all_tests();
  return 0;
}
