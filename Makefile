# Variables
CC = gcc
CFLAGS = -Wall -Iinclude

# Archivos fuente (agregado linked_list_test.c)
SRC = src/main.c src/linked_list.c src/linked_list_test.c

# Archivos objeto
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

# Binario final
BIN = bin/app

# Objetivo por defecto
.DEFAULT_GOAL := run

# Compilación
all: $(BIN)

# Regla de ejecución
run: all
	@./$(BIN)
	@rm -rf build bin

# Regla para enlazar binario
$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(BIN)

# Regla para compilar archivos fuente a objetos
build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -rf build/*.o $(BIN)
