# Trabajo Práctico - Programación de Bajo Nivel - UNTREF (Universidad Nacional de Tres de Febrero)

En este trabajo, se nos asignó la implementación de una *Lista Enlazada Simple* en el lenguaje de programación **C**. El objetivo es crear una estructura de datos con funcionalidades básicas, incluyendo inserción, eliminación, búsqueda e impresión de elementos. El proyecto apunta a mejorar nuestro entendimiento del uso de punteros, la gestión dinámica de memoria y la estructuración de datos en formato de lista enlazada.

## Grupo: int _(_(_(\*\*x[])(char_, int*(*)(char*)))[])(char\*\*, char*(\*)());

El nombre del grupo puede leerse como "x es un arreglo de punteros a funciones que reciben como parámetros un puntero a un caracter y un puntero a una función que recibe un puntero a un caracter y retorna un puntero a un entero. Estas funciones retornan un puntero a un arreglo de punteros a funciones que reciben como parámetros un puntero a un puntero a un caracter y un puntero a una función que retorna un puntero a un caracter, y devuelven un puntero a un entero"... solo por diversión.


## Miembros:
  - [Basso Natale, Delfina Emma](https://github.com/delfina-basso)
  - [Bueno, Mateo Andrés](https://github.com/MateoBueno)
  - [Reinaga, Abril](https://github.com/makochipa)
  - [Ribero, Gastón Augusto](https://github.com/trigologiaa)

## Tabla de contenidos:
- [Compilation with Makefile](#compilation-with-makefile)
- [Commands Made by Makefile](#commands-made-by-makefile)
  - [bash (Linux or macOS)](#bash-linux-or-macos)
  - [powershell (Windows)](#powershell-windows)
- [Implementation Overview](#implementation-overview)
  - [Key Features Implemented](#key-features-implemented)
  - [Header Files](#header-files)

## Compilation with Makefile

```bash
  make clean
  make
```

## Commands made by Makefile

### bash (Linux or macOS)

```bash
  # Create directories
  mkdir -p build
  mkdir -p bin

  # Compile the source files
  gcc -Wall -Iinclude -c src/main.c -o build/main.o
  gcc -Wall -Iinclude -c src/linked_list.c -o build/linked_list.o
  gcc -Wall -Iinclude -c src/linked_list_test.c -o build/linked_list_test.o

  # Link the object files into the final binary
  gcc build/main.o build/linked_list.o build/linked_list_test.o -o bin/app

  # Run the program
  ./bin/app

  # Clean up generated files
  rm -rf build/*.o bin/app
```

### powershell (Windows)

```powershell
  # Create directories
  mkdir .\build
  mkdir .\bin

  # Compile the source files
  gcc -Wall -Iinclude -c .\src\main.c -o .\build\main.o
  gcc -Wall -Iinclude -c .\src\linked_list.c -o .\build\linked_list.o
  gcc -Wall -Iinclude -c .\src\linked_list_test.c -o .\build\linked_list_test.o

  # Link the object files into the final binary
  gcc .\build\main.o .\build\linked_list.o .\build\linked_list_test.o -o .\bin\app.exe

  # Run the program
  .\bin\app.exe

  # Clean up generated files
  Remove-Item -Recurse -Force .\build\*.o, .\bin\app.exe
```

## Resumen de Implementación
Este proyecto consiste en implementar una *Lista Enlazada Simple* en **C**. La implementación incluye la creación de nodos, inserción y eliminación de elementos tanto al principio como al final de la lista, búsqueda de un elemento específico y la impresión del contenido de la lista.

### Funcionalidades Claves

1. **Estructura del nodo**:
    - Un nodo (*LinkedNode*) contiene un entero (data) y un puntero al siguiente nodo.
2. **Estructura de la lista**:
    - Una lista enlazada (*LinkedList*) contiene un puntero a la cabeza y cola de la lista y un entero que representa su tamaño actual.
3. **Funciones implementadas**:
    - *createNode*(*int* *data*): Crea un nuevo nodo con un valor entero pasado por parámetro.
    - *prepend*(*LinkedList* **list*, *int* *data*): Inserta un nodo al principio de la lista.
    - *append*(*LinkedList* **list*, *int* *data*): Inserta un nodo al final de la lista.
    - *removeFirst*(*LinkedList* **list*): Elimina el primer nodo de la lista.
    - *removeLast*(*LinkedList* **list*): Elimina el último nodo de la lista.
    - *removeData*(*LinkedList* **list*, *int* *data*): Elimina la primera ocurrencia de un valor pasado por parámetro.
    - *find*(*LinkedList* **list*, *int* *data*, *int* **position*): Encuentra la primera ocurrencia del valor dado.
    - *printList*(*LinkedList* **list*): Imprime el contenido de la lista.
4. **Gestión de memoria**:
    - Funciones como *destroyList*(*LinkedList* **list*) y *clear*(*LinkedList* **list*) aseguran una correcta gestión de memoria, liberando toda la memoria asignada cuando sea necesario.
5. **Menú interactivo**:
    - Una interfaz simple de tipo menú le permite al usuario interactuar con la lista y testear diversas operaciones como insertar, eliminar y buscar elementos.

### Header Files

1. El poyecto contiene dos header files principales:
    - linked_list.h: Define las estructuras lista enlazada simple y nodo, así como los prototipos de funciones para gestionar la lista.
    - linked_list_test.h: Declara tests unitarios utilizados para corroborar el correcto funcionamiento de las funcionalidades de la lista enlazada. Estos tests cubren diversos escenarios como la creación de listas, la inserción de elementos y la eliminación de datos.
