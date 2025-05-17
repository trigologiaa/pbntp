# int _(_(_(\*\*x[])(char_, int*(*)(char*)))[])(char\*\*, char*(\*)());

## The name of the group can be read as "x is an array of pointers to functions that take as parameters a pointer to a character and a pointer to a function that takes a pointer to a character and returns a pointer to an integer. These functions return a pointer to an array of pointers to functions that take as parameters a pointer to a pointer to a character and a pointer to a function that returns a pointer to a character, and return a pointer to an integer"... it is just for fun.

### Compilación

```bash
  make clean
  make
```

### Compilación manual y ejecución

```bash
  # Creación carpeta build/
  mkdir -p build
  # Compilación intermedia de lista.c a lista.o
  gcc -c -Iinclude src/lista.c -o build/lista.o
  # Compilación intermedia de main.c a main.o
  gcc -c -Iinclude src/main.c -o build/main.o
  # Creación de carpeta bin/
  mkdir -p bin
  # Compilación de aplicación
  gcc build/lista.o build/main.o -o bin/app
  # Ejecución de la aplicación
  ./bin/app
  # Eliminación de carpeta build/ y sus archivos
  rm -rf build/*
  # Eliminación de carpeta bin/
  rm -f bin/app
```
