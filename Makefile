# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -I./include

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files and target executable name 
SRC = $(wildcard $(SRC_DIR)/*.c)
TARGET = $(BUILD_DIR)/logistics

# Default rule to build the target
all: $(TARGET)

# How to build the executable
$(TARGET): $(SRC)
				$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Clean rule to remove the build artifacts
clean:

				rm -f $(BUILD_DIR)/*

# Define 'all' and 'clean' as phony targets 
.PHONY: all clean
