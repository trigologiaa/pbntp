#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
  int dato;
  struct Nodo *siguiente;
} Nodo;

Nodo *crearNodo(int dato);
void insertarAlInicio(Nodo **cabeza, int dato);
void insertarAlFinal(Nodo **cabeza, int dato);
void eliminarNodo(Nodo **cabeza, int dato);
Nodo *buscarNodo(Nodo *cabeza, int dato);
void imprimirLista(Nodo *cabeza);
void liberarLista(Nodo **cabeza);

#endif
