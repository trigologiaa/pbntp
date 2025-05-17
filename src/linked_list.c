#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedNode *createNode(int data) {
  LinkedNode *node = malloc(sizeof(LinkedNode));
  if (node == NULL) {
    return NULL;
  }
  node->data = data;
  node->next = NULL;
  return node;
}

// Find permite encontrar la primera ocurrencia del dato pasado por parámetro.
LinkedNode *find(LinkedList *list, int data) {
  for (LinkedNode *current = list->head; current != NULL;
       current = current->next) {
    if (current->data == data) {
      return current;
    }
  }
  return NULL;
}

// CreateList crea una nueva lista enlazada vacía.
LinkedList *createList() {
  LinkedList *list = malloc(sizeof(LinkedList));
  if (list == NULL) {
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Clear limpia la lista sin quitarle su espacio de memoria.
void clear(LinkedList *list) {
  while (!isEmpty(list)) {
    removeFirst(list);
  }
}

/* destroyList elimina todos los nodos de la lista
 * y libera espacio de memoria.
 */
void destroyList(LinkedList *list) {
  clear(list);
  free(list);
}

/* prepend añade un dato al inicio de la lista.
 *  Ejemplo:
 *  prepend(&list, 10) añade 10 al inicio de la lista.
 *  list es un puntero a la lista donde se añadirá el dato.
 */
void prepend(LinkedList *list, int data) {
  LinkedNode *node = malloc(sizeof(LinkedNode));
  node->data = data;
  node->next = list->head;
  list->head = node;
  if (list->tail == NULL) {
    list->tail = node;
  }
  list->size++;
}

/* append inserta un dato al final de la lista,
 *  reserva espacio en memoria.
 */
void append(LinkedList *list, int data) {
  LinkedNode *node = malloc(sizeof(LinkedNode));
  node->data = data;
  node->next = NULL;
  if (isEmpty(list)) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
  list->size++;
}

/* removeFirst remueve el primer elemento
 *  de la lista y libera memoria.
 */
void removeFirst(LinkedList *list) {
  if (isEmpty(list)) {
    return;
  }
  LinkedNode *temp = list->head;
  list->head = list->head->next;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  free(temp);
  list->size--;
}

/* removeLast elimina el último elemento de la lista
 * y libera memoria. Si la lista está vacía no hace nada.
 */
void removeLast(LinkedList *list) {
  if (isEmpty(list)) {
    return;
  }
  if (list->size == 1) {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
  } else {
    LinkedNode *current = list->head;
    while (current->next != list->tail) {
      current = current->next;
    }
    free(list->tail);
    current->next = NULL;
    list->tail = current;
  }
  list->size--;
}

// removeData elimina la primera ocurrencia del dato pasado por parámetro.
void removeData(LinkedList *list, int data) {
  if (isEmpty(list)) {
    return;
  }
  if (list->head->data == data) {
    removeFirst(list);
    return;
  }
  LinkedNode *current = list->head;
  while (current->next != NULL && current->next->data != data) {
    current = current->next;
  }
  if (current->next == NULL) {
    return;
  }
  LinkedNode *temp = current->next;
  current->next = temp->next;
  if (temp == list->tail) {
    list->tail = current;
  }
  free(temp);
  list->size--;
}

/* printList imprime la lista enlazada.
 *  Ejemplo:
 *  lista: {1, 2, 3, 4}
 *  printList(lista) = "LinkedList: [1] -> [2] -> [3] -> [4]"
 */
void printList(LinkedList *list) {
  printf("LinkedList: ");
  LinkedNode *current = list->head;
  while (current != NULL) {
    printf("[%d]", current->data);
    if (current->next != NULL) {
      printf(" -> ");
    }
    current = current->next;
  }
  printf("\n");
}

// size retorna el tamaño de la lista.
int size(LinkedList *list) { return list->size; }

/* isEmpty devuelve true si la lista está vacía,
 *  en caso contrario devuelve false.
 */
bool isEmpty(LinkedList *list) { return list->size == 0; }
