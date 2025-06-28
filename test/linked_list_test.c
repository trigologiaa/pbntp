#include "../include/linked_list_test.h"
#include "../include/linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Run all linked list related tests.
 */
void run_linked_list_tests() {
  printf("\n-> Running all Linked List tests <-\n");
  test_create_and_destroy_list();
  test_prepend_and_append();
  test_remove_first_and_last();
  test_remove_data();
  test_find();
  test_clear();
  test_for_each();
  test_list_to_string_and_print();
  printf("\n-> Linked List tests passed <-\n");
}

/**
 * @brief Test creating and destroying a list.
 */
void test_create_and_destroy_list() {
  printf("\nRunning test_create_and_destroy_list()\n");
  CircularList *list = create_list();
  assert(list != NULL);
  assert(is_empty(list));
  assert(get_size(list) == 0);
  destroy_list(list, free_int);
  printf("test_create_and_destroy_list() test passed\n");
}

/**
 * @brief Test prepend and append operations.
 */
void test_prepend_and_append() {
  printf("\nRunning test_prepend_and_append()\n");
  CircularList *list = create_list();
  int *a = malloc(sizeof(int));
  *a = 1;
  int *b = malloc(sizeof(int));
  *b = 2;
  int *c = malloc(sizeof(int));
  *c = 3;
  prepend(list, a);
  append(list, b);
  prepend(list, c);
  assert(get_size(list) == 3);
  assert(*(int *)list->head->data == 3);
  assert(*(int *)list->head->next->data == 1);
  assert(*(int *)list->tail->data == 2);
  destroy_list(list, free_int);
  printf("test_prepend_and_append() test passed\n");
}

/**
 * @brief Test removing first and last elements.
 */
void test_remove_first_and_last() {
  printf("\nRunning test_remove_first_and_last()\n");
  CircularList *list = create_list();
  int *a = malloc(sizeof(int));
  *a = 1;
  int *b = malloc(sizeof(int));
  *b = 2;
  int *c = malloc(sizeof(int));
  *c = 3;
  append(list, a);
  append(list, b);
  append(list, c);
  remove_first(list);
  assert(get_size(list) == 2);
  assert(*(int *)list->head->data == 2);
  remove_last(list);
  assert(get_size(list) == 1);
  assert(*(int *)list->head->data == 2);
  remove_first(list);
  assert(is_empty(list));
  destroy_list(list, free_int);
  printf("test_remove_first_and_last() test passed\n");
}

/**
 * @brief Test removing specific data from the list.
 */
void test_remove_data() {
  printf("\nRunning test_remove_data()\n");
  CircularList *list = create_list();
  int *a = malloc(sizeof(int));
  *a = 10;
  int *b = malloc(sizeof(int));
  *b = 20;
  int *c = malloc(sizeof(int));
  *c = 30;
  append(list, a);
  append(list, b);
  append(list, c);
  assert(remove_data(list, b, compare_ints));
  assert(get_size(list) == 2);
  assert(!remove_data(list, b, compare_ints));
  destroy_list(list, free_int);
  printf("test_remove_data() test passed\n");
}

/**
 * @brief Test finding an element in the list.
 */
void test_find() {
  printf("\nRunning test_find()\n");
  CircularList *list = create_list();
  int *x = malloc(sizeof(int));
  *x = 5;
  int *y = malloc(sizeof(int));
  *y = 10;
  int *z = malloc(sizeof(int));
  *z = 15;
  append(list, x);
  append(list, y);
  append(list, z);
  int pos;
  DoubleLinkedNode *node = find(list, y, &pos, compare_ints);
  assert(node != NULL);
  assert(*(int *)node->data == 10);
  assert(pos == 1);
  destroy_list(list, free_int);
  printf("test_find() test passed\n");
}

/**
 * @brief Test clearing the list.
 */
void test_clear() {
  printf("\nRunning test_clear()\n");
  CircularList *list = create_list();
  for (int i = 0; i < 5; i++) {
    int *n = malloc(sizeof(int));
    *n = i;
    append(list, n);
  }
  assert(get_size(list) == 5);
  clear(list, free_int);
  assert(is_empty(list));
  destroy_list(list, free_int);
  printf("test_clear() test passed\n");
}

/**
 * @brief Test applying a function to each element in the list.
 */
void test_for_each() {
  printf("\nRunning test_for_each()\n");
  CircularList *list = create_list();
  for (int i = 0; i < 3; i++) {
    int *n = malloc(sizeof(int));
    *n = i;
    append(list, n);
  }
  for_each(list, increment);
  DoubleLinkedNode *current = list->head;
  int expected = 1;
  do {
    assert(*(int *)current->data == expected);
    expected++;
    current = current->next;
  } while (current != list->head);
  destroy_list(list, free_int);
  printf("test_for_each() test passed\n");
}

/**
 * @brief Test converting a list to string and printing it.
 */
void test_list_to_string_and_print() {
  printf("\nRunning test_list_to_string_and_print()\n");
  CircularList *list = create_list();
  int *a = malloc(sizeof(int));
  *a = 7;
  int *b = malloc(sizeof(int));
  *b = 8;
  append(list, a);
  append(list, b);
  char *str = list_to_string(list, int_to_string);
  assert(str != NULL);
  printf("Result of list_to_string:\n%s", str);
  free(str);
  printf("Result of print_list:\n");
  print_list(list, int_to_string);
  destroy_list(list, free_int);
  printf("test_list_to_string_and_print() test passed\n");
}

/**
 * @brief Convert an integer pointer to string (used for printing lists).
 *
 * @param data Pointer to integer data.
 * @return Dynamically allocated string representation of the integer.
 */
char *int_to_string(void *data) {
  char *buffer = malloc(32);
  if (buffer) {
    snprintf(buffer, 32, "%d", *(int *)data);
  }
  return buffer;
}

/**
 * @brief Compare two integer pointers for equality.
 *
 * @param a Pointer to first integer.
 * @param b Pointer to second integer.
 * @return true if integers are equal, false otherwise.
 */
bool compare_ints(void *a, void *b) {
  return (*(int *)a == *(int *)b);
}

/**
 * @brief Free memory allocated for an integer.
 *
 * @param data Pointer to the integer to free.
 */
void free_int(void *data) {
  free(data);
}

/**
 * @brief Increment an integer by 1 (used in for_each test).
 *
 * @param data Pointer to the integer.
 */
void increment(void *data) {
  (*(int *)data)++;
}