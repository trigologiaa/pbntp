#include "../include/lista.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *crearNodo(int dato) {
  Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
  if (nuevo == NULL) {
    printf("Error al asignar memoria\n");
    return NULL;
  }
  nuevo->dato = dato;
  nuevo->siguiente = NULL;
  return nuevo;
}

void insertarAlInicio(Nodo **cabeza, int dato) {
  Nodo *nuevo = crearNodo(dato);
  if (nuevo == NULL) {
    return;
  }
  nuevo->siguiente = *cabeza;
  *cabeza = nuevo;
}

void insertarAlFinal(Nodo **cabeza, int dato) {
  Nodo *nuevo = crearNodo(dato);
  if (nuevo == NULL) {
    return;
  }
  if (*cabeza == NULL) {
    *cabeza = nuevo;
    return;
  }
  Nodo *actual = *cabeza;
  while (actual->siguiente != NULL) {
    actual = actual->siguiente;
  }
  actual->siguiente = nuevo;
}

void eliminarNodo(Nodo **cabeza, int dato) {
  if (*cabeza == NULL) {
    return;
  }
  Nodo *actual = *cabeza;
  Nodo *anterior = NULL;
  while (actual != NULL && actual->dato != dato) {
    anterior = actual;
    actual = actual->siguiente;
  }
  if (actual == NULL) {
    return;
  }
  if (anterior == NULL) {
    *cabeza = actual->siguiente;
  } else {
    anterior->siguiente = actual->siguiente;
  }
  free(actual);
}

Nodo *buscarNodo(Nodo *cabeza, int dato) {
  Nodo *actual = cabeza;
  while (actual != NULL) {
    if (actual->dato == dato) {
      return actual;
    }
    actual = actual->siguiente;
  }
  return NULL;
}

void imprimirLista(Nodo *cabeza) {
  Nodo *actual = cabeza;
  while (actual != NULL) {
    printf("%d -> ", actual->dato);
    actual = actual->siguiente;
  }
  printf("NULL\n");
}

void liberarLista(Nodo **cabeza) {
  Nodo *actual = *cabeza;
  while (actual != NULL) {
    Nodo *temp = actual;
    actual = actual->siguiente;
    free(temp);
  }
  *cabeza = NULL;
}
