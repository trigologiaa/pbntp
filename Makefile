# Variables
CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/lista.c
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
BIN = bin/app

# Regla principal
all: $(BIN)

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
	rm -rf build bin
