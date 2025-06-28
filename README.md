# Informe del Trabajo Práctico Grupal - Grupo `int _(_(_(\*\*x[])(char_, int*(*)(char*)))[])(char\*\*, char*(\*)());`

El nombre del grupo puede leerse como **x es un arreglo de punteros a funciones que reciben como parámetros un puntero a un caracter y un puntero a una función que recibe un puntero a un caracter y retorna un puntero a un entero. Estas funciones retornan un puntero a un arreglo de punteros a funciones que reciben como parámetros un puntero a un puntero a un caracter y un puntero a una función que retorna un puntero a un caracter, y devuelven un puntero a un entero**... es solo por diversión.

## Programación de Bajo Nivel - Primer Cuatrimestre 2025

**Integrantes del Grupo:**

- [Basso Natale, Delfina Emma - 80087](https://github.com/delfina-basso)
- [Bueno, Mateo Andrés - 72943](https://github.com/MateoBueno)
- [Reinaga, Abril - 72613](https://github.com/makochipa)
- [Ribero, Gastón Augusto - 72592](https://github.com/trigologiaa)

**Fecha de Entrega:** [29/06/2025]

## Tabla de Contenidos:

- [1. Introducción](#1-introducción)
  - [1.1. Objetivos del TP](#11-objetivos-del-tp)
  - [1.2. Resumen de la solución](#12-resumen-de-la-solución)
- [2. Diseño del Sistema](#2-diseño-del-sistema)
  - [2.1. Arquitectura General](#21-arquitectura-general)
  - [2.2. Estructuras de Datos](#22-estructuras-de-datos)
  - [2.3. Algoritmos Implementados](#23-algoritmos-implementados)
  - [2.4. Gestión de Datos de Entrada y Salida](#24-gestión-de-datos-de-entrada-y-salida)
- [3. Implementación](#3-implementación)
  - [3.1. Estructura del Proyecto](#31-estructura-del-proyecto)
  - [3.2. Módulos Principales](#32-módulos-principales)
  - [3.3. Tests Unitarios](#33-tests-unitarios)
  - [3.4. Decisiones de Diseño](#34-decisiones-de-diseño)
- [4. Cumplimiento de la consigna y Puntos Extra](#4-cumplimiento-de-la-consigna-y-puntos-extra)
  - [4.1. Funcionalidades básicas obligatorias](#41-funcionalidades-básicas-obligatorias)
  - [4.2. Puntos extra implementados](#42-puntos-extra-implementados)
  - [4.3. Limitaciones detectadas y reconocidas](#43-limitaciones-detectadas-y-reconocidas)
- [5. Análisis de Complejidad](#5-análisis-de-complejidad)
- [6. Pruebas y Resultados](#6-pruebas-y-resultados)
  - [6.1. Estrategia de Pruebas](#61-estrategia-de-pruebas)
  - [6.2. Ejecución de pruebas](#62-ejecución-de-pruebas)
  - [6.3. Resultados](#63-resultados)
- [7. Conclusiones y Trabajo Futuro](#7-conclusiones-y-trabajo-futuro)
  - [7.1. Conclusiones](#71-conclusiones)
  - [7.2. Trabajo Futuro](#72-trabajo-futuro)
- [8. Bibliografía](#8-bibliografía)
- [9. Apéndice](#9-apéndice)

## 1. Introducción

El objetivo del trabajo fue desarrollar un **Sistema de Gestión de Estudiantes** en lenguaje C, que permita administrar un gran número de estudiantes y materias de forma eficiente.

### 1.1. Objetivos del TP

- Permitir el **alta, baja, modificación y listado de estudiantes y materias**.
- **Buscar estudiantes por nombre o rango de edad**.
- Permitir que los estudiantes se **anoten y rindan materias**.
- Manejar el sistema de manera escalable y práctica para el usuario.

### 1.2. Resumen de la solución

El sistema fue desarrollado con una estructura modular en C, utilizando **listas circulares doblemente enlazadas** para la gestión de estudiantes y materias. Además, se implementaron funcionalidades adicionales para sumar valor al sistema (ver sección de Puntos Extra).

## 2. Diseño del Sistema

### 2.1. Arquitectura General

El sistema fue diseñado utilizando una arquitectura modular, con cada módulo representando una responsabilidad bien definida. Esto facilita la escalabilidad, el mantenimiento y la lectura del código.

#### Diagrama de bloques

```
╭──────────────────╮
│   Interfaz CLI   │
╰──────────────────╯
         │
         v
╭──────────────────╮
│  Módulo Student  │
╰──────────────────╯
         │
         v
╭──────────────────╮
│Módulo Enrollment │
╰──────────────────╯
         │
         v
╭──────────────────╮
│  Módulo Subject  │
╰──────────────────╯
         │
         v
╭──────────────────╮
│Módulo LinkedList │
╰──────────────────╯
         │
         v
╭──────────────────╮
│Módulo Persistence│
╰──────────────────╯
         │
         v
╭──────────────────╮
│   Archivos CSV   │
╰──────────────────╯
```

#### Principales decisiones de diseño

- Separación clara de responsabilidades: Cada módulo (estudiantes, materias, inscripciones, persistencia, listas, búsquedas) se implementa en archivos _.c_ y _.h_ separados.

- Uso de estructuras dinámicas (listas circulares doblemente enlazadas) para permitir manejo eficiente de grandes volúmenes de datos sin limitar el tamaño de las colecciones.

- Interfaces genéricas en las listas para permitir reutilización con cualquier tipo de dato (estudiantes, materias, inscripciones).

### 2.2. Estructuras de Datos

#### Lista circular doblemente enlazada

- Estructura base usada para almacenar tanto **estudiantes, materias** como **inscripciones**.
- Permite inserción, borrado y recorrido en ambas direcciones.
- Implementación de forma **genérica**, operando con punteros _void_ \* para soportar cualquier tipo de dato.

```c
typedef struct DoubleLinkedNode {
  void    *data;
  struct  DoubleLinkedNode *next;
  struct  DoubleLinkedNode *prev;
} DoubleLinkedNode;

typedef struct CircularList {
  DoubleLinkedNode  *head;
  int               size;
} CircularList;
```

#### Estudiantes

```c
typedef struct Student {
  int           id;
  char          name[50];
  CircularList  *enrollments;
} Student;
```

Cada estudiante tiene un **ID único**, **nombre**, **edad**, y una lista de **inscripciones**.

#### Materias

```c
typedef struct Subject {
  int id;
  char  name[50];
  int   credits;
} Subject;
```

Cada materia tiene un **ID único**, **nombre** y cantidad de **créditos**.

#### Inscripciones a materias

```c
typedef struct SubjectEnrollment {
  int   subjectId;
  float grade;
} SubjectEnrollment;
```

Cada inscripción representa la relación de un estudiante con una materia, incluyendo la **nota si la cursó o rindió**.

- Para cada módulo principal (Check-in, Gestión de Carga, Embarque, Despacho):
- Descripción de las estructuras de datos utilizadas (pilas, colas, listas, colas de prioridad, árboles binarios, etc.).
- Justificación de la elección de cada estructura de datos en función de los requerimientos del problema.
- Diagramas de las estructuras de datos (si es pertinente).

### 2.3. Algoritmos Implementados

#### Para cada módulo principal

- Descripción detallada de los algoritmos implementados para las tareas clave (simulación de llegada de pasajeros, gestión de colas de check-in, asignación de carga, cálculo de la línea del horizonte, compresión Huffman, asignación de zonas de embarque, gestión de la cola de prioridad para despacho, etc.).
- Explicación del funcionamiento de cada algoritmo, incluyendo pseudocódigo o diagramas de flujo si es necesario.
- Referencias a conceptos teóricos de algoritmos y estructuras de datos aplicados.

### 2.4. Gestión de Datos de Entrada y Salida

- Descripción de cómo se leen y procesan los datos de los archivos de entrada (`vuelos.txt`, `clientes.txt`, etc.).
- Explicación del formato y contenido de los archivos de salida generados (`.huff`, `linea_horizonte.txt`).

## 3. Implementación

La implementación del sistema fue realizada íntegramente en lenguaje **C (C99)**, siguiendo una estructura modular y utilizando listas doblemente enlazadas circulares como base para almacenar y manipular los listados de estudiantes y materias.

### 3.1. Estructura del Proyecto

La organización de carpetas es la siguiente:

```
bin/      -> Ejecutable final
build/    -> Objetos compilados
data/     -> Archivos CSV de entrada/salida
include/  -> Headers (.h)
src/      -> Código fuente (.c)
test/     -> Tests unitarios
```

### 3.2. Módulos Principales

#### Módulo _linked_list_

##### Propósito

Implementación de una lista circular doblemente enlazada para gestionar tanto estudiantes como materias.

##### Funciones clave

- Creación y destrucción:

  - _createList()_
  - _destroyList()_
  - _clear()_

- Manipulación de nodos:

  - _prepend()_
  - _append()_
  - _removeFirst()_
  - _removeLast()_
  - _removeData()_

- Recorridos y búsqueda:

  - _find()_
  - _forEach()_

- Consultas:
  - _isEmpty()_
  - _getSize()_
  - _listToString()_

#### Módulo _student_

##### Propósito

Gestión de estudiantes: alta, baja, modificación, representación textual y comparación.

##### Estructura principal

```c
typedef struct Student {
  int           id;
  char          name[50];
  int           age;
  CircularList  *enrollments;
} Student;
```

##### Funciones clave

- _createStudent()_
- _destroyStudent()_
- _studentToString()_
- _compareStudentById()_
- _compareStudentByName()_

#### Módulo _subject_

##### Propósito

Gestión de materias: creación, eliminación, representación y comparación.

##### Estructura principal

```c
typedef struct Subject {
  int   id;
  char  name[50];
  int   credits;
} Subject;
```

##### Funciones clave

- _createSubject()_
- _destroySubject()_
- _subjectToString()_
- _CompareSubjectById()_

#### Módulo _enrollment_

##### Propósito

Gestión de inscripciones y rendición de materias.

##### Estructura principal

```c
typedef struct SubjectEnrollment {
  int   subjectId;
  float grade;
} SubjectEnrollment;
```

##### Funciones clave

- Inscripción:

  - _canEnroll()_
  - _enrollStudent()_

- Rendición de examen:

  - _recordExam()_

- Gestión de memoria:

  - _createEnrollment()_
  - _destroyEnrollment()_

#### Módulo _search_

##### Propósito

Búsquedas específicas de estudiantes y materias.

##### Funciones clave

- _findStudentsByName()_
- _findStudentsByAgeRange()_
- _getStudentById()_
- _getSubjectById()_

#### Módulo _persistence_

##### Propósito

Persistencia de datos en archivos CSV.

##### Funciones clave

- Guardado y carga de estudiantes:

  - _saveStudentsToCsv()_
  - _loadStudentsFromCsv()_

- Guardado y carga de materias:

  - _saveSubjectsToCsv()_
  - _loadSubjectsFromCsv()_

##### Formato de archivos

- Archivos CSV separados para estudiantes y materias.
- Cada línea representa un estudiante o materia.
- Las inscripciones de cada estudiante se almacenan serializadas en una columna adicional.

### 3.3. Tests Unitarios

Cada módulo tiene su archivo de pruebas dedicado dentro de la carpeta _test/_, por ejemplo:

- _linked_list_test.c_
- _student_test.c_
- _subject_test.c_
- _enrollment_test.c_
- _persistence_test.c_
- _search_test.c_

Los tests se realizaron utilizando **CUnit** y ejecuciones manuales desde consola.

### 3.4. Decisiones de Diseño

#### Modularización clara

Separación estricta entre lógica de estudiantes, materias, persistencia y listas genéricas.

#### Estructuras dinámicas

Uso de listas circulares doblemente enlazadas.

#### Comparadores y toString genéricos

Las listas reciben punteros a funciones de comparación y conversión a string, lo que permite reutilizar la misma implementación con distintos tipos de datos.

#### Persistencia en CSV

Formato humano-legible, fácil de depurar y portabe entre ejecuciones.

- Descripción general de la implementación.

- Organización del código.

- Explicación de las decisiones de modularización y las interfaces utilizadas (si corresponde).

- Breve descripción de las principales funciones y clases implementadas.

- Consideraciones sobre las buenas prácticas de programación aplicadas.

## 4. Cumplimiento de la consigna y Puntos Extra

### 4.1. Funcionalidades básicas obligatorias

| **Requerimiento**                                 | **Implementación**                            |
| ------------------------------------------------- | --------------------------------------------- |
| Alta, baja, modificación y listado de estudiantes | Implementado en el módulo _student_           |
| Búsqueda de estudiantes por nombre                | Implementado en el módulo _search_            |
| Búsqueda por rango de edad                        | Implementado en el módulo _search_            |
| Alta, baja, modificación y listado de materias    | Implementado en el módulo _subject_           |
| Anotación del estudiante en materias              | Implementado en el módulo _enrollment_        |
| Registro de rendición de materias                 | Implementado en el módulo _enrollment_        |
| Estructuras adecuadas para grandes volúmenes      | Uso de listas circulares doblemente enlazadas |

### 4.2. Puntos extra implementados

| **Punto extra sugerido**                        | **Descripción**                                                                                     |
| ----------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| Persistencia en CSV                             | Guardado y carga de estudiantes, materias, inscripciones y calificaciones en archivos CSV separados |
| Tests unitarios                                 | Pruebas unitarias para todos los módulos principales                                                |
| Generación masiva de estudiantes y materias     | Función para generar datos masivos aleatorios para pruebas de carga en _test_massive_load.c_        |
| Mejora en la interfaz de usuario                | Menús en consola con mensajes claros y navegación por opciones numéricas                            |
| Estadísticas de estudiantes y materias          | Cálculo de promedios y cantidad de materias cursadas/rendidas                                       |
| Árbol de correlatividades                       | Control de correlativas para inscripción mediante lista circular en _can_enroll_                    |
| Restricción por correlativas aprobadas          | Verificación que impide anotarse sin aprobar todas las correlativas                                 |
| Paginado                                        | Función paginate_list para mostrar listados largos en páginas con pausa                             |
| Ordenamiento por promedio                       | Ordenamiento in-place de estudiantes por promedio de notas descendente                              |
| Auto-incremento de ID único                     | Contadores estáticos y función global generate_unique_id para IDs únicos                            |
| Gestión de correlatividades en materias         | Cada materia mantiene lista de correlativas verificadas antes de inscripción                        |
| Conversión a string y comparadores reutilizabes | Funciones para representación textual y comparación flexible de estudiantes y materias              |

### 4.3. Limitaciones detectadas y reconocidas

#### Escalabilidad de las búsquedas

Actualmente las búsquedas son de complejidad **O(n)**. En volúmenes muy grandes de datos (por ejemplo, más de 50000 estudiantes o materias), podría haber demoras.

#### Persistencia básica

El sistema utiliza **archivos CSV**. No está preparado para concurrencia o acceso multiusuario.

## 5. Análisis de Complejidad

A continuación se detalla la complejidad temporal y espacial de las principales operaciones implementadas en las estructuras y módulos de la lista circular doblemente enlazada:

| **Operación**    | **Complejidad temporal** | **Complejidad espacial** | **Comentario**                                            |
| ---------------- | ------------------------ | ------------------------ | --------------------------------------------------------- |
| _create_node_    | O(1)                     | O(1)                     | Asignación de memoria constante por nodo                  |
| _prepend_        | O(1)                     | O(1)                     | Operación constante en lista circular doblemente enlazada |
| _append_         | O(1)                     | O(1)                     | No depende del tamaño de la lista                         |
| _remove_first_   | O(1)                     | O(1)                     | También constante                                         |
| _remove_last_    | O(1)                     | O(1)                     | También constante                                         |
| _find_           | O(n)                     | O(1)                     | Recorrido secuencial                                      |
| _remove_data_    | O(n)                     | O(1)                     | Búsqueda lineal antes de eliminar                         |
| _for_each_       | O(n)                     | O(1)                     | Valida cada nodo una vez                                  |
| _list_to_string_ | O(n)                     | O(n)                     | Recorre todos los nodos y acumula en un buffer            |

## 6. Pruebas y Resultados

Se realizaron pruebas unitarias para cada uno de los módulos principales, incluyendo operaciones de creación, modificación, búsqueda y persistencia de datos.

### 6.1. Estrategia de Pruebas

#### Pruebas unitarias

Cada módulo tiene un archivo de pruebas en la carpeta _test/_ junto con su header en _include/_.

#### Cobertura de pruebas

- Creación y destrucción de estructuras.

- Inserción y eliminación de elementos.

- Búsqueda y consultas.

- Guardado y carga desde archivos CSV.

### 6.2. Ejecución de pruebas

Las pruebas pueden ejecutarse de la siguiente manera:

```bash
# Ejecutar automáticamente
make run

# Creación de archivos para ejecución manual (se puede ahorrar este paso ejecutando solo el anterior)
make build
./bin/app

# Limpieza de carpetas y archivos creados por el programa
make clean
```

### 6.3. Resultados

- Todas las funcionalidades pasaron las pruebas unitarias.

- Se validó que el sistema puede cargar y guardar correctamente estudiantes y materias.

- Se comprobó el correcto funcionamiento de la paginación, ordenamiento y búsqueda por nombre y edad.

## 7. Conclusiones y Trabajo Futuro

### 7.1. Conclusiones

El proyecto cumplió con todos los requerimientos planeados en la consigna y se implementaron varios puntos extra que enriquecen el sistema.

#### Logros destacados

- Modularización clara y mantenible.

- Uso de estructuras dinámicas eficientes.

- Persistencia en formato CSV.

- Pruebas unitarias completas por módulo.

- Implementación de ordenamiento, búsquedas y paginación.

### 7.2. Trabajo Futuro

Algunas mejoras que podrían realizarse en el futuro incluyen:

- Implementar persistencia en formato binario para mayor eficiencia.

- Agregar índices para búsquedas más rápidas (por ejemplo, binary tree o hash table para estudiantes).

- Mejorar la interfaz de usuario, por ejemplo utilizando ncurses o una interfaz gráfica.

- Añadir control de concurrencia para acceso multiusuario.

- Validaciones adicionales en la carga de archivos (detección de formatos inválidos).

## 8. Bibliografía

- [Free Programming Books](https://github.com/EbookFoundation/free-programming-books)

- [cplusplus.com](https://www.cplusplus.com/)

- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)

- [Stack Overflow](https://stackoverflow.com/)

- [TutorialsPoint - C Programming](https://www.tutorialspoint.com/cprogramming/index.htm)

- [ChatGPT](https://www.chatgpt.com/)

- [Pointers Explanation](https://www.youtube.com/watch?v=qclZUQYZTzg)

## 9. Apéndice

- [Repositorio](https://github.com/trigologiaa/pbntp)

- **Estructura de carpetas**

  ```
  bin/      -> Ejecutable final
  build/    -> Objetos compilados
  data/     -> Archivos CSV de entrada/salida
  include/  -> Headers (.h)
  src/      -> Código fuente (.c)
  test/     -> Tests unitarios
  ```

- **Datos de pruebas**

  Se incluyeron archivos CSV de ejemplo en la carpeta _data/_ para facilitar las pruebas por parte de los docentes.
