#include "../include/lista.h"
#include <stdio.h>
#include <stdlib.h>


/*  createNode crea un nuevo nodo para listas enlazadas.
*   Ejemplo:
*   createNode(10) crea un nuevo nodo con 10 como data
*/  
LinkedNode *createNode(int data) {
  LinkedNode *nuevo = (LinkedNode *)malloc(sizeof(LinkedNode));
  if (nuevo == NULL) {
    printf("Error al asignar memoria\n");
    return NULL;
  }
  nuevo->data = data;
  nuevo->next = NULL;
  return nuevo;
}

/*  insertarAlInicio inserta un data al inicio de la lista.
*   Ejemplo:
*   insertarAlInicio(&cabeza, 10) inserta 10 al inicio de la lista.actual
*   &cabeza es un puntero a la cabeza actual de la lista.
*/
void insertarAlInicio(LinkedNode **cabeza, int data) {
  LinkedNode *nuevo = createNode(data);
  if (nuevo == NULL) {
    return;
  }
  nuevo->next = *cabeza;
  *cabeza = nuevo;
}

/*  insertarAlInicio inserta un data al final de la lista.
*   Ejemplo:
*   insertarAlInicio(&cabeza, 10) inserta 10 al final de la lista.actual
*   &cabeza es un puntero a la cabeza actual de la lista.
*/
void insertarAlFinal(LinkedNode **cabeza, int data) {
  LinkedNode *nuevo = createNode(data);
  if (nuevo == NULL) {
    return;
  }
  if (*cabeza == NULL) {
    *cabeza = nuevo;
    return;
  }
  LinkedNode *actual = *cabeza;
  while (actual->next != NULL) {
    actual = actual->next;
  }
  actual->next = nuevo;
}



void eliminarNodo(LinkedNode **cabeza, int data) {
  if (*cabeza == NULL) {
    return;
  }
  LinkedNode *actual = *cabeza;
  LinkedNode *anterior = NULL;
  while (actual != NULL && actual->data != data) {
    anterior = actual;
    actual = actual->next;
  }
  if (actual == NULL) {
    return;
  }
  if (anterior == NULL) {
    *cabeza = actual->next;
  } else {
    anterior->next = actual->next;
  }
  free(actual);
}
/* find busca un dato en la lista, si lo encuentra
* devuelve el dato correspondiente, sino, 
* devuelve NULL.
*/
LinkedNode *find(LinkedList *list, int data) {
  // LinkedNode *actual = ;
  // while (actual != NULL) {
  //   if (actual->data == data) {
  //     return actual;
  //   }
  //   actual = actual->next;
  // }
  // return NULL;
}
/* 
* 
*/
void imprimirLista(LinkedNode *cabeza) {
  LinkedNode *actual = cabeza;
  while (actual != NULL) {
    printf("%d -> ", actual->data);
    actual = actual->next;
  }
  printf("NULL\n");
}

// liberarLista libera el espacio de memoria guardado para la lista.
void liberarLista(LinkedNode **cabeza) {
  LinkedNode *actual = *cabeza;
  while (actual != NULL) {
    LinkedNode *temp = actual;
    actual = actual->next;
    free(temp);
  }
  *cabeza = NULL;
}
