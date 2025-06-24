# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Source files
SRC = $(wildcard src/*.c)

# Object files
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

# Output binary
BIN = bin/app

# Default goal
.DEFAULT_GOAL := run

# Main target
all: $(BIN)

# Run target
run: all
	@./$(BIN)
	@rm -rf build bin

# Link object files
$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(BIN)

# Compile source files
build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object and binary files
clean:
	rm -rf build bin