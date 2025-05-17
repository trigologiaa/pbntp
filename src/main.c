#include "../include/lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Nodo *cabeza = NULL;
  int opcion, dato;
  do {
    printf("\n--- MENÚ ---\n");
    printf("1. Insertar al inicio\n");
    printf("2. Insertar al final\n");
    printf("3. Eliminar nodo\n");
    printf("4. Buscar nodo\n");
    printf("5. Imprimir lista\n");
    printf("6. Salir\n");
    printf("Ingresá una opción: ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1:
      printf("Ingresá el dato para insertar al inicio: ");
      scanf("%d", &dato);
      insertarAlInicio(&cabeza, dato);
      break;
    case 2:
      printf("Ingresá el dato para insertar al final: ");
      scanf("%d", &dato);
      insertarAlFinal(&cabeza, dato);
      break;
    case 3:
      printf("Ingresá el dato a eliminar: ");
      scanf("%d", &dato);
      eliminarNodo(&cabeza, dato);
      break;
    case 4: {
      printf("Ingresá el dato a buscar: ");
      scanf("%d", &dato);
      Nodo *encontrado = buscarNodo(cabeza, dato);
      if (encontrado != NULL) {
        printf("Dato %d encontrado en la lista\n", encontrado->dato);
      } else {
        printf("Dato no encontrado en la lista\n");
      }
      break;
    }
    case 5:
      imprimirLista(cabeza);
      break;
    case 6:
      printf("Saliendo del menú...\n");
      break;
    default:
      printf("Opción inválida\n");
    }
  } while (opcion != 6);
  liberarLista(&cabeza);
  return 0;
}
