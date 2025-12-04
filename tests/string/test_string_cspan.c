#include "mylib/string.h"
#include <assert.h>
#include <stdio.h>

void test_standard_case(void) {
  const char *strspace = "Bhargav;;";
  const char *rejectable = ";";

  assert(strcspan(rejectable, strspace) == 7);
  puts("Test 1 Passed: Standard Substring Case.");
}

void test_empty_reject_case(void) {
  const char *strspace = "aaaabbbb";
  const char *rejectable = "";

  assert(strcspan(rejectable, strspace) == 8);
  puts("Test 2 Passed: Empty Reject Case.");
}

void run_all_tests(void) {
  test_standard_case();
  test_empty_reject_case();
}

int main(void) {
  run_all_tests();
  return 0;
}
