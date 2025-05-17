// TODO: Tests de las funciones si es que se puede en C.
#include <assert.h>
#include <stdio.h>
#include "../include/linked_list.h"


// void test_createEmptyList() {
//     LinkedList *list = createList(); 
//     assert(list != NULL);
//     assert(list->head == NULL);
//     assert(list->tail == NULL);
//     assert(list->size == NULL);

//     printf("Test de list vacía completo.\n");
    
//     destroyList(list);
// }

// void test_createListWithOneElement() {
//     LinkedList *list = createList();
//     prepend(list, 10);
//     assert(list->head->data == 10);

//     printf("Test de list con un elemento completo.\n");
    
//     destroyList(list);
// }

// void test_appendElement() {
//     LinkedList *list = createList();
//     prepend(list, 3);
//     prepend(list, 2);
//     prepend(list, 1);
    
//     append(list, 5);
//     assert(list->tail->data == 5);

//     print("Test de añadir elemento al final completo.\n");
//     destroyList(list);
// }

// void test_removeFirstElement() {
//     LinkedList *list = createList();
//     prepend(list, 1);
//     prepend(list, 2);
//     prepend(list, 3);
//     prepend(list, 4);
//     assert(list->head->data == 1);

//     removeFirst(list);

//     printf("Test de eliminar el primer elemento completo.\n");
//     destroyList(list);
// }

// void test_removeData() {
//     LinkedList *list = createList();
//     append(list, 1);
//     append(list, 2);
//     append(list, 3);
//     append(list, 4);
//     append(list, 3);

//     removeData(list, 3);
//     char printedList = printList(list);
//     assert(printedList == "LinkedList: [1] -> [2] -> [4] -> [3]");
//     printf("Test de remover dato completo. \n")
//     destroyList(list);
// }

// void test_findElement() {
//     LinkedList *list = createList();
//     append(list, 1);
//     append(list, 2);
//     append(list, 3);

//     int valor = find(list, 2);
//     assert(valor == 2);
//     printf("Test de buscar elemento completo.");
//     destroyList(list);
// }

// void test_findUnexistingElement() {
//     LinkedList *list = createList();
//     append(list, 1);
//     append(list, 2);
//     append(list, 3);

//     int valor = find(list, 5);
//     assert(valor != 5);
//     printf("Test de encontrar elemento inexistente completo.");
//     destroyList(list);
// }

// void test_size() {
//     LinkedList *list = createList();
//     assert(list->size() == 0);
    
//     append(list, 1);
//     assert(list->size() == 1);

//     append(list, 2);
//     assert(list.size() == 2);

//     printf()

// }

// int main() {
//     test_createEmptyList();
//     test_createListWithOneElement();
//     test_appendElement();
//     test_removeFirstElement();
//     test_removeData();
//     test_findElement();
//     test_findUnexistingElement();
//     test_size();
//     return 0;
// }