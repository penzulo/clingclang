#include "mylib/string.h"
#include <assert.h>
#include <stdio.h>

void test_empty_case(void) {
  const char text[] = "";
  assert(!strlength(text));
  puts("Test 1 Passed: Empty String Case.");
}

void test_standard_case(void) {
  const char text[] = "Nepal is beautiful.";
  assert(strlength(text) == 19);
  puts("Test 2 Passed: Standard Case.");
}

void test_special_characters(void) {
  const char string[] = "\nbut bhutan is better.\n";
  assert(strlength(string) == 23);
  puts("Test 3 Passed: Special Characters Case.");
}

void run_all_tests(void) {
  test_empty_case();
  test_standard_case();
  test_special_characters();
}

int main(void) {
  run_all_tests();
  return 0;
}
