# Practical Work - Programación de Bajo Nivel - UNTREF (Universidad Nacional de Tres de Febrero)

In this assignment, we were tasked with implementing a *Double Linked List* in the programming language **C**. The goal was to create a data structure with basic functionalities, including inserting, deleting, searching, and printing elements. The project aimed to improve our understanding of pointers, dynamic memory management, and structuring data in a linked list format.

## Group: int _(_(_(\*\*x[])(char_, int*(*)(char*)))[])(char\*\*, char*(\*)());

The name of the group can be read as "x is an array of pointers to functions that take as parameters a pointer to a character and a pointer to a function that takes a pointer to a character and returns a pointer to an integer. These functions return a pointer to an array of pointers to functions that take as parameters a pointer to a pointer to a character and a pointer to a function that returns a pointer to a character, and return a pointer to an integer"... it is just for fun.

## Members:
  - [Basso Natale, Delfina Emma](https://github.com/delfina-basso)
  - [Bueno, Mateo Andrés](https://github.com/MateoBueno)
  - [Reinaga, Abril](https://github.com/makochipa)
  - [Ribero, Gastón Augusto](https://github.com/trigologiaa)

## Table of Contents:
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

## Implementation Overview

This project consists of implementing a *Double Linked List* in **C**. The implementation includes the creation of nodes, insertion and removal of elements at the beginning and end of the list, searching for a specific element, and printing the list contents.

### Key Features Implemented

1. **Node Structure**:
    - A node (*DoubleLinkedNode*) contains an integer (data) and a pointer to the next node.
2. **Double Linked List Structure**:
    - A linked list (*DoubleLinkedList*) contains a pointer to the head and tail of the list and an integer tracking the size.
3. **Functions Implemented**:
    - *createNode*(*int* *data*): Creates a new node with a given integer value.
    - *prepend*(*DoubleLinkedList* **list*, *int* *data*): Adds a node at the beginning of the list.
    - *append*(*DoubleLinkedList* **list*, *int* *data*): Adds a node at the end of the list.
    - *removeFirst*(*DoubleLinkedList* **list*): Removes the first node of the list.
    - *removeLast*(*DoubleLinkedList* **list*): Removes the last node of the list.
    - *removeData*(*DoubleLinkedList* **list*, *int* *data*): Removes the first occurrence of a specific value.
    - *find*(*DoubleLinkedList* **list*, *int* *data*, *int* **position*): Finds the first occurrence of a value.
    - *printList*(*DoubleLinkedList* **list*): Prints the contents of the list.
4. **Memory Management**:
    - Functions such as *destroyList*(*DoubleLinkedList* **list*) and *clear*(*DoubleLinkedList* **list*) ensure proper memory management, freeing all allocated memory when needed.
5. **Interactive Menu**:
    - A simple menu-based interface allows users to interact with the linked list, testing various operations like inserting, removing, and searching for elements.

### Header Files

1. The project contains two primary header files:
    - linked_list.h: Defines the linked list and node structures, as well as all the function prototype used to manage the linked list.
    - linked_list_test.h: Declares unit test functions used to validate the behavior of the linked list functions. These tests cover scenarios such as list creation, element insertion, and data removal.