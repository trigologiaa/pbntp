# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Source and test files
SRC = $(wildcard src/*.c)
TESTS = $(wildcard test/*.c)

# Object files for source and tests
OBJ_SRC = $(patsubst src/%.c, build/%.o, $(SRC))
OBJ_TESTS = $(patsubst test/%.c, build/tests_%.o, $(TESTS))

# All object files to link
OBJ = $(OBJ_SRC) $(OBJ_TESTS)

# Output binary
BIN = bin/app

.PHONY: all run clean build

# Default target: build binary
all: | build bin data $(BIN)

# Build target (only compile and link, no run)
build: all

# Run target: build then execute
run: all
	@./$(BIN)
	rm -rf build bin

# Link all object files into executable
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

# Compile source files
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files
build/tests_%.o: test/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if not exists
build:
	mkdir -p build

# Create bin directory if not exists
bin:
	mkdir -p bin

# Create data directory if not exists
data:
	mkdir -p data

# Clean build artifacts
clean:
	rm -rf build bin data