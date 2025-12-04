#include "mylib/string.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_standard_case(void) {
  const char *s1 = "Hello ";
  const char *s2 = "World!";
  char *destination = malloc(strlength(s1) + strlength(s2) + 1);

  strcopy(s1, destination); // For initialization
  char *result = strconcat(s2, destination);

  // NOTE: Check for correct return value
  assert(result == destination);
  assert(strlength(destination) == ((strlength(s1) + strlength(s2))));
  free(destination);

  puts("Test 1 Passed: Standard Case.");
}

void run_all_tests(void) { test_standard_case(); }

int main(void) {
  run_all_tests();
  return 0;
}
