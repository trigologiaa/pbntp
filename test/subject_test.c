#include "../include/subject_test.h"
#include "../include/linked_list.h"
#include "../include/subject.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Runs all Subject module tests.
 */
void run_subject_tests() {
  printf("\n-> Running all Subject tests <-\n");
  test_create_subject();
  test_correlatives_list();
  test_subject_to_string();
  test_compare_subject_by_id();
  printf("\n-> Subject tests passed <-\n");
}

/**
 * @brief Tests creating a Subject and verifying its properties.
 *
 * Checks that the subject is created with the expected name, credits, and
 * initializes an empty correlatives list.
 */
void test_create_subject() {
  printf("\nRunning test_create_subject()\n");
  Subject *s = create_subject("Matemáticas", 6);
  assert(s != NULL);
  assert(strcmp(s->name, "Matemáticas") == 0);
  assert(s->credits == 6);
  assert(s->correlatives != NULL);
  assert(get_size(s->correlatives) == 0);
  destroy_subject(s);
  printf("test_create_subject() test passed\n");
}

/**
 * @brief Tests operations on the correlatives list of a Subject.
 *
 * Verifies that correlatives can be appended and iterated correctly, and that
 * all expected IDs are present.
 */
void test_correlatives_list() {
  printf("\nRunning test_correlatives_list()\n");
  Subject *s = create_subject("Física", 5);
  assert(s != NULL);
  int *cid1 = malloc(sizeof(int));
  int *cid2 = malloc(sizeof(int));
  *cid1 = 1;
  *cid2 = 2;
  append(s->correlatives, cid1);
  append(s->correlatives, cid2);
  assert(get_size(s->correlatives) == 2);
  DoubleLinkedNode *node = s->correlatives->head;
  int found1 = 0, found2 = 0;
  if (node) {
    do {
      int *val = (int *)node->data;
      if (*val == 1)
        found1 = 1;
      if (*val == 2)
        found2 = 1;
      node = node->next;
    } while (node != s->correlatives->head);
  }
  assert(found1 && found2);
  destroy_subject(s);
  printf("test_correlatives_list() test passed\n");
}

/**
 * @brief Tests the subject_to_string function.
 *
 * Checks that the string representation of a Subject is non-null and prints it
 * for visual verification.
 */
void test_subject_to_string() {
  printf("\nRunning test_subject_to_string()\n");
  Subject *s = create_subject("Química", 4);
  assert(s != NULL);
  char *str = subject_to_string(s);
  assert(str != NULL);
  printf("Subject to string: %s\n", str);
  free(str);
  destroy_subject(s);
  printf("test_subject_to_string() test passed\n");
}

/**
 * @brief Tests comparison of Subjects by their ID.
 *
 * Verifies that the comparison returns true only for subjects with the same ID
 * and handles NULL pointers safely.
 */
void test_compare_subject_by_id() {
  printf("\nRunning test_compare_subject_by_id()\n");
  Subject *s1 = create_subject("Historia", 3);
  Subject *s2 = create_subject("Geografía", 3);
  assert(compare_subject_by_id(s1, s1) == 1);
  assert(compare_subject_by_id(s1, s2) == 0);
  assert(compare_subject_by_id(NULL, s2) == 0);
  assert(compare_subject_by_id(s1, NULL) == 0);
  destroy_subject(s1);
  destroy_subject(s2);
  printf("test_compare_subject_by_id() test passed\n");
}
