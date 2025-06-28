#ifndef LINKED_LIST_TEST_H

#define LINKED_LIST_TEST_H

#include "linked_list.h"
#include <stdbool.h>

/**
 * @brief Run all linked list related tests.
 */
void run_linked_list_tests();

/**
 * @brief Test creating and destroying a list.
 */
void test_create_and_destroy_list();

/**
 * @brief Test prepend and append operations.
 */
void test_prepend_and_append();

/**
 * @brief Test removing first and last elements.
 */
void test_remove_first_and_last();

/**
 * @brief Test removing specific data from the list.
 */
void test_remove_data();

/**
 * @brief Test finding an element in the list.
 */
void test_find();

/**
 * @brief Test clearing the list.
 */
void test_clear();

/**
 * @brief Test applying a function to each element in the list.
 */
void test_for_each();

/**
 * @brief Test converting a list to string and printing it.
 */
void test_list_to_string_and_print();

/**
 * @brief Convert an integer pointer to string (used for printing lists).
 *
 * @param data Pointer to integer data.
 * @return Dynamically allocated string representation of the integer.
 */
char *int_to_string(void *data);

/**
 * @brief Compare two integer pointers for equality.
 *
 * @param a Pointer to first integer.
 * @param b Pointer to second integer.
 * @return true if integers are equal, false otherwise.
 */
bool compare_ints(void *a, void *b);

/**
 * @brief Free memory allocated for an integer.
 *
 * @param data Pointer to the integer to free.
 */
void free_int(void *data);

/**
 * @brief Increment an integer by 1 (used in for_each test).
 *
 * @param data Pointer to the integer.
 */
void increment(void *data);

#endif
