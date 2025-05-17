#ifndef LINKED_LIST_TEST_H
#define LINKED_LIST_TEST_H

#include "../include/linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_createEmptyList() {
  LinkedList *list = createList();
  assert(list != NULL);
  assert(list->head == NULL);
  assert(list->tail == NULL);
  assert(list->size == 0);
  printf("Test de list vacía completo.\n");
  destroyList(list);
}

void test_createListWithOneElement() {
  LinkedList *list = createList();
  prepend(list, 10);
  assert(list->head->data == 10);
  printf("Test de list con un elemento completo.\n");
  destroyList(list);
}

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

#endif
