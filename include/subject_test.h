#ifndef SUBJECT_TEST_H

#define SUBJECT_TEST_H

/**
 * @brief Runs all Subject module tests.
 */
void run_subject_tests(void);

/**
 * @brief Tests creating a Subject and verifying its properties.
 *
 * Checks that the subject is created with the expected name, credits, and
 * initializes an empty correlatives list.
 */
void test_create_subject(void);

/**
 * @brief Tests operations on the correlatives list of a Subject.
 *
 * Verifies that correlatives can be appended and iterated correctly, and that
 * all expected IDs are present.
 */
void test_correlatives_list(void);

/**
 * @brief Tests the subject_to_string function.
 *
 * Checks that the string representation of a Subject is non-null and prints it
 * for visual verification.
 */
void test_subject_to_string(void);

/**
 * @brief Tests comparison of Subjects by their ID.
 *
 * Verifies that the comparison returns true only for subjects with the same ID
 * and handles NULL pointers safely.
 */
void test_compare_subject_by_id(void);

#endif
