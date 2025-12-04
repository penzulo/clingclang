#include "mylib/string.h"
#include <assert.h>
#include <stdio.h>

void test_standard_case(void) {
  const char *strspace = "aaabbbcccxyz";
  const char *acceptable = "abc";

  assert(strspan(acceptable, strspace) == 9);
  puts("Test 1 Passed: Standard Substring Case.");
}

void test_string_span_empty(void) {
  const char *strspace = "aaaabbbb";
  const char *acceptable = "";

  assert(!strspan(acceptable, strspace));
  puts("Test 2 Passed: Empty Substring Case.");
}

void run_all_tests(void) {
  test_standard_case();
  test_string_span_empty();
}

int main(void) {
  run_all_tests();
  return 0;
}
