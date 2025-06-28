#ifndef STUDENT_TEST_H

#define STUDENT_TEST_H

/**
 * @brief Runs all Student module tests.
 */
void run_student_tests(void);

/**
 * @brief Tests creating a Student and verifying its properties.
 *
 * Checks that the student is created with the expected name, age, default
 * average, and initialized enrollments list.
 */
void test_create_student(void);

/**
 * @brief Tests the student_to_string function.
 *
 * Verifies that the string representation contains the student's name and age.
 */
void test_student_to_string(void);

/**
 * @brief Tests comparison functions by name and by ID.
 *
 * Verifies that two students with the same name compare equal by name, and that
 * ID comparisons behave as expected.
 */
void test_compare_student_by_id_and_name(void);

#endif
