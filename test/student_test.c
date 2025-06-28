#include "../include/student_test.h"
#include "../include/student.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Runs all Student module tests.
 */
void run_student_tests() {
  printf("\n-> Running all Studnt tests <-\n");
  test_create_student();
  test_student_to_string();
  test_compare_student_by_id_and_name();
  printf("\n-> Student tests passed <-\n");
}

/**
 * @brief Tests creating a Student and verifying its properties.
 *
 * Checks that the student is created with the expected name, age, default
 * average, and initialized enrollments list.
 */
void test_create_student() {
  printf("\nRunning test_create_student()\n");
  Student *s = create_student("Ana", 20);
  assert(s != NULL);
  assert(strcmp(s->name, "Ana") == 0);
  assert(s->age == 20);
  assert(s->average == 0.0f);
  assert(s->enrollments != NULL);
  assert(get_size(s->enrollments) == 0);
  destroy_student(s);
  printf("test_create_student() test passed\n");
}

/**
 * @brief Tests the student_to_string function.
 *
 * Verifies that the string representation contains the student's name and age.
 */
void test_student_to_string() {
  printf("\nRunning test_student_to_string()\n");
  Student *s = create_student("Luis", 22);
  char *desc = student_to_string(s);
  assert(desc != NULL);
  assert(strstr(desc, "Luis") != NULL);
  assert(strstr(desc, "22") != NULL);
  free(desc);
  destroy_student(s);
  printf("test_student_to_string() test passed\n");
}

/**
 * @brief Tests comparison functions by name and by ID.
 *
 * Verifies that two students with the same name compare equal by name, and that
 * ID comparisons behave as expected.
 */
void test_compare_student_by_id_and_name() {
  printf("\nRunning test_compare_student_by_id_and_name()\n");
  Student *s1 = create_student("Carlos", 25);
  Student *s2 = create_student("Carlos", 30);
  Student *s3 = create_student("Maria", 25);
  assert(compare_student_by_name(s1, s2) == true);
  assert(compare_student_by_name(s1, s3) == false);
  assert(compare_student_by_id(s1, s2) == false);
  assert(compare_student_by_id(s1, s1) == true);
  destroy_student(s1);
  destroy_student(s2);
  destroy_student(s3);
  printf("test_compare_student_by_id_and_name() test passed\n");
}
