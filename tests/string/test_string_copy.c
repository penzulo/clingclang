#include "mylib/string.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_standard_case(void) {
  const char *s1 = "String to be copied.";
  char *s2 = malloc(strlength(s1) + 1);

  assert(strcopy(s1, s2) == s2); // Check if both point to the same location.
  assert(strlength(s1) == strlength(s2)); // Check if lengths are same.
  free(s2);
  puts("Test 1 Passed: Basic string copy.");
}

void run_all_tests(void) { test_standard_case(); }

int main(void) {
  run_all_tests();
  return 0;
}
