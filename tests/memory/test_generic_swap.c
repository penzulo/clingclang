#include "mylib/memory.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void test_integer_case(void) {
  uint8_t num1 = 65;
  uint8_t num2 = 97;
  swap(&num1, &num2, sizeof(uint8_t));

  assert(num2 == 65 && num1 == 97);
  puts("Test 1 Passed: Integer Swap");
}

void test_integer_array_case(void) {
  uint8_t arr1[5] = {1, 2, 3, 4, 5};
  uint8_t arr2[5] = {6, 7, 8, 9, 10};
  swap(arr1, arr2, sizeof(arr1));

  for (uint8_t i = 0; i < 5; assert(arr2[i] + 5 == arr1[i]), i++) {}
  puts("Test 2 Passed: Integer Array Swap");
}

void test_struct_case(void) {
  typedef struct {
    char name[256];
    uint8_t age;
    float gpa;
  } Student;

  Student s1 = {"Bhargav", 20, 8.2f};
  Student s2 = {"John", 22, 6.0f};
  swap(&s1, &s2, sizeof(Student));

  assert(strcmp(s1.name, "John") == 0);
  assert(s1.age == 22);
  assert(s1.gpa == 6.0f);
  assert(strcmp(s2.name, "Bhargav") == 0);
  assert(s2.age == 20);
  assert(s2.gpa == 8.2f);

  puts("Test 3 Passed: Student Struct Swap");
}

void run_all_tests(void) {
  test_integer_case();
  test_integer_array_case();
  test_struct_case();
}

int main(void) {
  run_all_tests();
  return 0;
}
