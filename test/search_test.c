#include "../include/search_test.h"
#include "../include/linked_list.h"
#include "../include/search.h"
#include "../include/student.h"
#include "../include/subject.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static Student *make_student(const char *name, int age);
static Subject *make_subject(const char *name, int credits);
static void destroy_student_wrapper(void *data);
static void destroy_subject_wrapper(void *data);

/**
 * @brief Run all search-related tests.
 */
void run_search_tests() {
  printf("\n-> Running all Search tests <-\n");
  test_find_students_by_name_found();
  test_find_students_by_name_not_found();
  test_find_students_by_age_range_found();
  test_find_students_by_age_range_not_found();
  test_get_student_by_id();
  test_get_subject_by_id();
  printf("\n-> Search tests passed <-\n");
}

/**
 * @brief Test finding students by name (found case).
 */
void test_find_students_by_name_found() {
  printf("\nRunning test_find_students_by_name_found()\n");
  CircularList *students = create_list();
  Student *s1 = make_student("Alice", 20);
  Student *s2 = make_student("Bob", 22);
  Student *s3 = make_student("Alice", 25);
  append(students, s1);
  append(students, s2);
  append(students, s3);
  printf("Test find_students_by_name (should find 2 Alices):\n");
  find_students_by_name(students, "Alice");
  destroy_list(students, destroy_student_wrapper);
  printf("test_find_students_by_name_found() test passed\n");
}

/**
 * @brief Test finding students by name (not found case).
 */
void test_find_students_by_name_not_found() {
  printf("\nRunning test_find_students_by_name_not_found()\n");
  CircularList *students = create_list();
  Student *s = make_student("Charlie", 30);
  append(students, s);
  printf("Test find_students_by_name (no match):\n");
  find_students_by_name(students, "Diana");
  destroy_list(students, destroy_student_wrapper);
  printf("test_find_students_by_name_not_found() test passed\n");
}

/**
 * @brief Test finding students by age range (found case).
 */
void test_find_students_by_age_range_found() {
  printf("\nRunning test_find_students_by_age_range_found()\n");
  CircularList *students = create_list();
  append(students, make_student("Eve", 18));
  append(students, make_student("Frank", 21));
  append(students, make_student("Grace", 25));
  printf("Test find_students_by_age_range (18 to 22):\n");
  find_students_by_age_range(students, 18, 22);
  destroy_list(students, destroy_student_wrapper);
  printf("test_find_students_by_age_range_found() test passed\n");
}

/**
 * @brief Test finding students by age range (not found case).
 */
void test_find_students_by_age_range_not_found() {
  printf("\nRunning test_find_students_by_age_range_not_found()\n");
  CircularList *students = create_list();
  append(students, make_student("Hank", 30));
  append(students, make_student("Ivy", 35));
  printf("Test find_students_by_age_range (20 to 25):\n");
  find_students_by_age_range(students, 20, 25);
  destroy_list(students, destroy_student_wrapper);
  printf("test_find_students_by_age_range_not_found() test passed\n");
}

/**
 * @brief Test getting a student by ID.
 */
void test_get_student_by_id() {
  printf("\nRunning test_get_student_by_id()\n");
  CircularList *students = create_list();
  Student *s1 = make_student("Jack", 19);
  Student *s2 = make_student("Kara", 23);
  append(students, s1);
  append(students, s2);
  Student *found = get_student_by_id(students, s1->id);
  assert(found != NULL);
  assert(strcmp(found->name, "Jack") == 0);
  Student *not_found = get_student_by_id(students, 9999);
  assert(not_found == NULL);
  destroy_list(students, destroy_student_wrapper);
  printf("test_get_student_by_id() test passed\n");
}

/**
 * @brief Test getting a subject by ID.
 */
void test_get_subject_by_id() {
  printf("\nRunning test_get_subject_by_id()\n");
  CircularList *subjects = create_list();
  Subject *sub1 = make_subject("Math", 6);
  Subject *sub2 = make_subject("History", 4);
  append(subjects, sub1);
  append(subjects, sub2);
  Subject *found = get_subject_by_id(subjects, sub1->id);
  assert(found != NULL);
  assert(strcmp(found->name, "Math") == 0);
  Subject *not_found = get_subject_by_id(subjects, 9999);
  assert(not_found == NULL);
  destroy_list(subjects, destroy_subject_wrapper);
  printf("test_get_subject_by_id() test passed\n");
}

/**
 * @brief Creates a new student with the given name and age.
 *
 * This function is a wrapper around create_student, simplifying the creation of
 * students in the tests.
 *
 * @param name The student's name.
 * @param age The student's age.
 * @return Student* Pointer to the newly created student.
 */
static Student *make_student(const char *name, int age) {
  Student *s = create_student(name, age);
  return s;
}

/**
 * @brief Creates a new subject with the given name and credits.
 *
 * This function is a wrapper around create_subject, simplifying the creation of
 * subjects in the tests.
 *
 * @param name The subject's name.
 * @param credits The number of credits for the subject.
 * @return Subject* Pointer to the newly created subject.
 */
static Subject *make_subject(const char *name, int credits) {
  Subject *subj = create_subject(name, credits);
  return subj;
}

/**
 * @brief Wrapper function to destroy a student, passed as void*, used by
 * functions expecting a generic pointer.
 *
 * @param data Pointer to the student to destroy (void*).
 */
static void destroy_student_wrapper(void *data) {
  destroy_student(data);
}

/**
 * @brief Wrapper function to destroy a subject, passed as void*, used by
 * functions expecting a generic pointer.
 *
 * @param data Pointer to the subject to destroy (void*).
 */
static void destroy_subject_wrapper(void *data) {
  destroy_subject(data);
}