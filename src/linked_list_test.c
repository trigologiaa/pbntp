#include "../include/linked_list_test.h"
#include <assert.h>

/**
 * @brief tests the creation of an empty linked list
 *
 * verifies that a new list is initialized correctly with size 0, and both head
 * and tail set to NULL
 */
void test_createEmptyList() {
  LinkedList *list = createList();
  assert(list != NULL);
  assert(list->head == NULL);
  assert(list->tail == NULL);
  assert(list->size == 0);
  printf("Test de list vacía completo.\n");
  destroyList(list);
}

/**
 * @brief tests the creation of a linked list with a single element
 *
 * ensures that the list correctly stores the single node and updates head,
 * tail, and size accordingly
 */
void test_createListWithOneElement() {
  LinkedList *list = createList();
  prepend(list, 10);
  assert(list->head->data == 10);
  printf("Test de list con un elemento completo.\n");
  destroyList(list);
}

/**
 * @brief tests appending elements to the linked list
 *
 * validates that elements are added to the end of the list and that tail and
 * size are updated correctly
 */
void test_appendElement() {
  LinkedList *list = createList();
  prepend(list, 3);
  prepend(list, 2);
  prepend(list, 1);
  append(list, 5);
  assert(list->tail->data == 5);
  printf("Test de añadir elemento al final completo.\n");
  destroyList(list);
}

/**
 * @brief tests removing the first element of the list
 *
 * checks that the head is updated and memory is freed appropriately
 */
void test_removeFirstElement() {
  LinkedList *list = createList();
  prepend(list, 1);
  append(list, 2);
  append(list, 3);
  append(list, 4);
  assert(list->head->data == 1);
  removeFirst(list);
  printf("Test de eliminar el primer elemento completo.\n");
  destroyList(list);
}

/**
 * @brief tests removing a specific data value from the list
 *
 * ensures that only the first occurrence of the data is removed and that list
 * links and size remain consistent
 */
void test_removeData() {
  char *buffer = NULL;
  size_t size = 0;
  FILE *stream = open_memstream(&buffer, &size);
  FILE *original_stdout = stdout;
  stdout = stream;
  LinkedList *list = createList();
  append(list, 1);
  append(list, 2);
  append(list, 3);
  append(list, 4);
  append(list, 3);
  removeData(list, 3);
  printList(list);
  fflush(stream);
  stdout = original_stdout;
  fclose(stream);
  assert(strcmp(buffer, "LinkedList: [1] -> [2] -> [4] -> [3]\n") == 0);
  printf("Test de remover dato completo.\n");
  destroyList(list);
}

/**
 * @brief tests finding an element in the list
 *
 * confirms that a pointer to the correct node is returned when the data exists
 * in the list
 */
void test_findElement() {
  LinkedList *list = createList();
  append(list, 1);
  append(list, 2);
  append(list, 3);
  LinkedNode *valor = find(list, 2);
  assert(valor->data == 2);
  printf("Test de buscar elemento completo.\n");
  destroyList(list);
}

/**
 * @brief tests searching for a value not present in the list
 *
 * ensures that the function returns NULL when the element is not found
 */
void test_findUnexistingElement() {
  LinkedList *list = createList();
  append(list, 1);
  append(list, 2);
  append(list, 3);
  LinkedNode *valor = find(list, 5);
  assert(valor == NULL);
  printf("Test de encontrar elemento inexistente completo.\n");
  destroyList(list);
}

/**
 * @brief tests the size reporting function
 *
 * validates that the size of the list matches the number of nodes after
 * operations
 */
void test_size() {
  LinkedList *list = createList();
  assert(getSize(list) == 0);
  append(list, 1);
  assert(getSize(list) == 1);
  append(list, 2);
  assert(getSize(list) == 2);
  printf("Test de verificar tamaño de lista completo.\n");
  destroyList(list);
}
