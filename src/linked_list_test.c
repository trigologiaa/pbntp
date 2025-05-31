#include "../include/linked_list_test.h"
#include <assert.h>

/**
 * @brief tests the creation of an empty linked list
 *
 * verifies that a new list is initialized correctly with size 0, and both head
 * and tail set to NULL
 */
void test_createEmptyList() {
  printf("\n ->> test_createEmptyList started\n");
  CircularList *list = createList();
  assert(list != NULL);
  printf(" ->> Created an empty list\n");
  assert(list->head == NULL);
  printf(" ->> Head is NULL\n");
  assert(list->tail == NULL);
  printf(" ->> Tail is NULL\n");
  assert(list->size == 0);
  printf(" ->> Size is 0\n");
  destroyList(list);
  printf(" ->> test_createEmptyList completed successfully\n");
}

/**
 * @brief tests the creation of a linked list with a single element
 *
 * ensures that the list correctly stores the single node and updates head,
 * tail, and size accordingly
 */
void test_createListWithOneElement() {
  printf("\n ->> test_createListWithOneElement started\n");
  CircularList *list = createList();
  prepend(list, 10);
  printf(" ->> Prepending 10 to the list\n");
  assert(list->head->data == 10);
  printf(" ->> Head data is 10\n");
  destroyList(list);
  printf(" ->> test_createListWithOneElement completed successfully\n");
}

/**
 * @brief tests appending elements to the linked list
 *
 * validates that elements are added to the end of the list and that tail and
 * size are updated correctly
 */
void test_appendElement() {
  printf("\n ->> test_appendElement started\n");
  CircularList *list = createList();
  prepend(list, 3);
  printf(" ->> Prepending 3 to the list\n");
  prepend(list, 2);
  printf(" ->> Prepending 2 to the list\n");
  prepend(list, 1);
  printf(" ->> Prepending 1 to the list\n");
  append(list, 5);
  printf(" ->> Appending 5 to the list\n");
  assert(list->tail->data == 5);
  printf(" ->> Tail data is 5\n");
  destroyList(list);
  printf(" ->> test_appendElement completed successfully\n");
}

/**
 * @brief tests removing the first element of the list
 *
 * checks that the head is updated and memory is freed appropriately
 */
void test_removeFirstElement() {
  printf("\n ->> test_removeFirstElement started\n");
  CircularList *list = createList();
  prepend(list, 1);
  printf(" ->> Prepending 1 to the list\n");
  append(list, 2);
  printf(" ->> Appending 2 to the list\n");
  append(list, 3);
  printf(" ->> Appending 3 to the list\n");
  append(list, 4);
  printf(" ->> Appending 4 to the list\n");
  assert(list->head->data == 1);
  printf(" ->> Head data is 1\n");
  removeFirst(list);
  printf(" ->> Removing the first element (1)\n");
  destroyList(list);
  printf(" ->> test_removeFirstElement completed successfully\n");
}

/**
 * @brief tests removing the last element of the list
 */
void test_removeLast() {
  printf("\n ->> test_removeLast started\n");
  CircularList *list = createList();
  append(list, 1);
  printf(" ->> Appending 1 to the list\n");
  append(list, 2);
  printf(" ->> Appending 2 to the list\n");
  removeLast(list);
  printf(" ->> Removing the last element (2)\n");
  assert(list->tail->data == 1);
  printf(" ->> Tail data is 1\n");
  assert(list->size == 1);
  printf(" ->> Size is 1\n");
  removeLast(list);
  printf(" ->> Removing the last element (1)\n");
  assert(isEmpty(list));
  printf(" ->> The list is empty\n");
  assert(list->head == NULL && list->tail == NULL);
  destroyList(list);
  printf(" ->> test_removeLast completed successfully\n");
}

/**
 * @brief tests removing a specific data value from the list
 *
 * ensures that only the first occurrence of the data is removed and that list
 * links and size remain consistent
 */
void test_removeData() {
  printf("\n ->> test_removeData started\n");
  CircularList *list = createList();
  append(list, 1);
  printf(" ->> Appending 1 to the list\n");
  append(list, 2);
  printf(" ->> Appending 2 to the list\n");
  append(list, 3);
  printf(" ->> Appending 3 to the list\n");
  append(list, 4);
  printf(" ->> Appending 4 to the list\n");
  append(list, 3);
  printf(" ->> Appending another 3 to the list\n");
  removeData(list, 3);
  printf(" ->> Removing the first occurrence of 3\n");
  char *output = listToString(list);
  printf(" ->> List after removal: %s", output);
  assert(strcmp(output, "List: -> [1] <-> [2] <-> [4] <-> [3] <-\n") == 0);
  free(output);
  destroyList(list);
  printf(" ->> test_removeData completed successfully\n");
}

/**
 * @brief tests finding an element in the list
 *
 * confirms that a pointer to the correct node is returned when the data exists
 * in the list
 */
void test_findElement() {
  printf("\n ->> test_findElement started\n");
  CircularList *list = createList();
  append(list, 1);
  printf(" ->> Appending 1 to the list\n");
  append(list, 2);
  printf(" ->> Appending 2 to the list\n");
  append(list, 3);
  printf(" ->> Appending 3 to the list\n");
  int position = -1;
  DoubleLinkedNode *value = find(list, 2, &position);
  printf(" ->> Finding element with value 2 at index %d\n", position);
  assert(value->data == 2);
  printf(" ->> Found element: %d\n", value->data);
  destroyList(list);
  printf(" ->> test_findElement completed successfully\n");
}

/**
 * @brief tests searching for a value not present in the list
 *
 * ensures that the function returns NULL when the element is not found
 */
void test_findUnexistingElement() {
  printf("\n ->> test_findUnexistingElement started\n");
  CircularList *list = createList();
  append(list, 1);
  printf(" ->> Appending 1 to the list\n");
  append(list, 2);
  printf(" ->> Appending 2 to the list\n");
  append(list, 3);
  printf(" ->> Appending 3 to the list\n");
  int position = -1;
  DoubleLinkedNode *value = find(list, 5, &position);
  printf(" ->> Finding element with value 5 at index%d\n", position);
  assert(value == NULL);
  printf(" ->> Element not found\n");
  destroyList(list);
  printf(" ->> test_findUnexistingElement completed successfully\n");
}

/**
 * @brief tests the size reporting function
 *
 * validates that the size of the list matches the number of nodes after
 * operations
 */
void test_size() {
  printf("\n ->> test_size started\n");
  CircularList *list = createList();
  assert(getSize(list) == 0);
  printf(" ->> Size is 0\n");
  append(list, 1);
  printf(" ->> Appending 1 to the list\n");
  assert(getSize(list) == 1);
  printf(" ->> Size is 1\n");
  append(list, 2);
  printf(" ->> Appending 2 to the list\n");
  assert(getSize(list) == 2);
  printf(" ->> Size is 2\n");
  destroyList(list);
  printf(" ->> test_size completed successfully\n");
}
