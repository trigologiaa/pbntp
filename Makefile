# Variables
CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/linked_list.c
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
BIN = bin/app

# Objetivo por defecto: compilar y ejecutar
.DEFAULT_GOAL := run

# Regla para compilar
all: $(BIN)

# Ejecutar después de compilar
run: all
	@./$(BIN)
	@rm -rf build bin

# Cómo construir el ejecutable a partir de objetos
$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(BIN)

# Cómo compilar .c en build/
build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar todo lo generado
clean:
	rm -rf build/*.o $(BIN)
