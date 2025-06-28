#ifndef ENROLLMENT_TEST_H

#define ENROLLMENT_TEST_H

#include "student.h"
#include "subject.h"
#include <stdbool.h>

/**
 * @brief Run all enrollment-related tests.
 */
void run_enrollment_tests();

/**
 * @brief Test creation of an enrollment.
 */
void test_create_enrollment();

/**
 * @brief Test if a student can enroll when there are no correlatives.
 */
void test_can_enroll_no_correlatives();

/**
 * @brief Test if a student can enroll when there are correlatives.
 */
void test_can_enroll_with_correlatives();

/**
 * @brief Test enrolling a student successfully and preventing duplicates.
 */
void test_enroll_student_success_and_duplicate();

/**
 * @brief Test recording an exam with various outcomes.
 */
void test_record_exam_success_and_failure();

/**
 * @brief Creates a test student for unit tests.
 *
 * @return Pointer to the created test student.
 */
Student *create_test_student();

/**
 * @brief Destroys a test student created for unit tests.
 *
 * Frees memory and destroys internal lists.
 *
 * @param s Pointer to the test student.
 */
void destroy_test_student(Student *s);

#endif
