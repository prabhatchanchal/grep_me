# Makefile

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Source files
SRC_DIR = src
INCLUDE_DIR = include
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, obj/%.o, $(SRC_FILES))

# Executable name
EXECUTABLE = grep

# Target for the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ grep.c

# Target for object files
obj/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Create the 'obj' directory if it doesn't exist
$(shell mkdir -p obj)

# Clean target
clean:
	rm -rf obj $(EXECUTABLE)
