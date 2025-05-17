#ifndef LINKED_LIST_TEST_H
#define LINKED_LIST_TEST_H

/**
 * @file linked_list_test.h
 *
 * @brief header file for unit tests of the linked list implementation
 *
 * this file declares test functions that validates the behavior of the linked
 * list operations such as creation, insertion, deletion, and search
 */

#include "../include/linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief tests the creation of an empty linked list
 *
 * verifies that a new list is initialized correctly with size 0, and both head
 * and tail set to NULL
 */
void test_createEmptyList();

/**
 * @brief tests the creation of a linked list with a single element
 *
 * ensures that the list correctly stores the single node and updates head,
 * tail, and size accordingly
 */
void test_createListWithOneElement();

/**
 * @brief tests appending elements to the linked list
 *
 * validates that elements are added to the end of the list and that tail and
 * size are updated correctly
 */
void test_appendElement();

/**
 * @brief tests removing the first element of the list
 *
 * checks that the head is updated and memory is freed appropriately
 */
void test_removeFirstElement();

/**
 * @brief tests removing a specific data value from the list
 *
 * ensures that only the first occurrence of the data is removed and that list
 * links and size remain consistent
 */
void test_removeData();

/**
 * @brief tests finding an element in the list
 *
 * confirms that a pointer to the correct node is returned when the data exists
 * in the list
 */
void test_findElement();

/**
 * @brief tests searching for a value not present in the list
 *
 * ensures that the function returns NULL when the element is not found
 */
void test_findUnexistingElement();

/**
 * @brief tests the size reporting function
 *
 * validates that the size of the list matches the number of nodes after
 * operations
 */
void test_size();

#endif
