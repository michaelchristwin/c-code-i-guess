# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude

# Source and build directories
SRC_DIR = src
BUILD_DIR = build

# Source files in src directory and root
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
ROOT_FILES = main.c

# All source files
SRCS = $(SRC_FILES) $(ROOT_FILES)

# Object files - handle both src/ and root files
SRC_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
ROOT_OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(ROOT_FILES))
OBJS = $(SRC_OBJS) $(ROOT_OBJS)

# Executable name
TARGET = my_program

# Default target
all: $(BUILD_DIR)/$(TARGET)

# Link object files to create the executable
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files from src directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile source files from root directory
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)/*

# Create build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

.PHONY: all clean