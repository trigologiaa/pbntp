#include "../include/enrollment_test.h"
#include "../include/enrollment.h"
#include "../include/linked_list.h"
#include "../include/student.h"
#include "../include/subject.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Run all enrollment-related tests.
 */
void run_enrollment_tests() {
  printf("\n-> Running all Enrollment tests <-\n");
  test_create_enrollment();
  test_can_enroll_no_correlatives();
  test_can_enroll_with_correlatives();
  test_enroll_student_success_and_duplicate();
  test_record_exam_success_and_failure();
  printf("\n-> Enrollment tests passed <-\n");
}

/**
 * @brief Test creation of an enrollment.
 */
void test_create_enrollment() {
  printf("\nRunning test_create_enrollment()\n");
  SubjectEnrollment *en = create_enrollment(5);
  assert(en != NULL);
  assert(en->subjectId == 5);
  assert(en->passed == false);
  assert(en->grade == -1.0f);
  destroy_enrollment(en);
  printf("test_create_enrollment() test passed\n");
}

/**
 * @brief Test if a student can enroll when there are no correlatives.
 */
void test_can_enroll_no_correlatives() {
  printf("\nRunning test_can_enroll_no_correlatives()\n");
  Student *s = create_test_student();
  Subject *subj = create_subject("Matemáticas", 6);
  bool res = can_enroll(s, subj, NULL);
  assert(res == true);
  destroy_subject(subj);
  destroy_test_student(s);
  printf("\ntest_can_enroll_no_correlatives() test passed\n");
}

/**
 * @brief Test if a student can enroll when there are correlatives.
 */
void test_can_enroll_with_correlatives() {
  printf("\nRunning test_can_enroll_with_correlatives()\n");
  Student *s = create_test_student();
  Subject *subj = create_subject("Física", 6);
  int *cor_id = malloc(sizeof(int));
  *cor_id = 1;
  append(subj->correlatives, cor_id);
  SubjectEnrollment *en = create_enrollment(1);
  en->passed = true;
  append(s->enrollments, en);
  bool res = can_enroll(s, subj, NULL);
  assert(res == true);
  en->passed = false;
  res = can_enroll(s, subj, NULL);
  assert(res == false);
  destroy_subject(subj);
  destroy_test_student(s);
  printf("test_can_enroll_with_correlatives() test passed\n");
}

/**
 * @brief Test enrolling a student successfully and preventing duplicates.
 */
void test_enroll_student_success_and_duplicate() {
  printf("\nRunning test_enroll_student_success_and_duplicate()\n");
  Student *s = create_test_student();
  Subject *subj = create_subject("Historia", 4);
  bool res = enroll_student(s, subj, NULL);
  assert(res == true);
  assert(get_size(s->enrollments) == 1);
  res = enroll_student(s, subj, NULL);
  assert(res == false);
  assert(get_size(s->enrollments) == 1);
  destroy_subject(subj);
  destroy_test_student(s);
  printf("test_enroll_student_success_and_duplicate() test passed\n");
}

/**
 * @brief Test recording an exam with various outcomes.
 */
void test_record_exam_success_and_failure() {
  printf("\nRunning test_record_exam_success_and_failure()\n");
  Student *s = create_test_student();
  SubjectEnrollment *en = create_enrollment(10);
  append(s->enrollments, en);
  bool res = record_exam(s, 10, 7.5f);
  assert(res == true);
  assert(en->grade == 7.5f);
  assert(en->passed == true);
  res = record_exam(s, 10, 3.0f);
  assert(res == false);
  assert(en->grade != 3.0f);
  assert(en->passed != false);
  res = record_exam(s, 10, 15.0f);
  assert(res == false);
  res = record_exam(s, 99, 8.0f);
  assert(res == false);
  destroy_test_student(s);
  printf("test_record_exam_success_and_failure() test passed\n");
}

/**
 * @brief Creates a test student for unit tests.
 *
 * @return Pointer to the created test student.
 */
Student *create_test_student() {
  Student *s = malloc(sizeof(Student));
  if (!s) {
    return NULL;
  }
  s->id = 1;
  snprintf(s->name, sizeof(s->name), "Test Student");
  s->enrollments = create_list();
  return s;
}

/**
 * @brief Destroys a test student created for unit tests.
 *
 * Frees memory and destroys internal lists.
 *
 * @param s Pointer to the test student.
 */
void destroy_test_student(Student *s) {
  if (!s) {
    return;
  }
  if (s->enrollments) {
    destroy_list(s->enrollments, destroy_enrollment);
  }
  free(s);
}
