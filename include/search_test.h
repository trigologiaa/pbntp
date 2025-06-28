#ifndef SEARCH_TEST_H

#define SEARCH_TEST_H

/**
 * @brief Run all search-related tests.
 */
void run_search_tests();

/**
 * @brief Test finding students by name (found case).
 */
void test_find_students_by_name_found();

/**
 * @brief Test finding students by name (not found case).
 */
void test_find_students_by_name_not_found();

/**
 * @brief Test finding students by age range (found case).
 */
void test_find_students_by_age_range_found();

/**
 * @brief Test finding students by age range (not found case).
 */
void test_find_students_by_age_range_not_found();

/**
 * @brief Test getting a student by ID.
 */
void test_get_student_by_id();

/**
 * @brief Test getting a subject by ID.
 */
void test_get_subject_by_id();

#endif
