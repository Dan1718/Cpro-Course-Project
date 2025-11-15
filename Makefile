# ============================================================
# Makefile for a simple calculator project
# ============================================================
# This Makefile automates the process of compiling and linking
# multiple C source files into a single executable.
# ============================================================

# The compiler to use
CC = gcc

# Compiler flags:
# -Wall : enables all common warnings
# -I./include : tells the compiler to look for header files in the 'include' folder
# -g : includes debugging information (useful for gdb)
CFLAGS = -Wall -I./include -g

# List of all source files (.c files)
# These are located in the 'src' directory
SRCS = src/main.c src/io.c src/logic.c src/wincheck.c

# Object files (.o) will be generated for each source file
# The substitution rule below replaces every ".c" with ".o"
OBJS = $(SRCS:.c=.o)

# The final name of the executable program
TARGET = calculator

# ============================================================
# Default target: 'all'
# ============================================================
# When you type 'make' with no arguments, this target runs.
# It depends on $(TARGET), so the rules for $(TARGET) will run.
all: $(TARGET)

# ============================================================
# Linking stage
# ============================================================
# To build the final executable $(TARGET), we need all object files.
# $@ refers to the target name (i.e., 'calculator')
# $^ refers to all the prerequisites (i.e., all .o files)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# ============================================================
# Compilation stage (pattern rule)
# ============================================================
# This rule describes how to make any .o file from its corresponding .c file.
# $< refers to the first prerequisite (the .c file)
# $@ refers to the target name (the .o file)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ============================================================
# Clean target
# ============================================================
# Typing 'make clean' removes all generated files.
# -f flag ignores errors if files don't exist.
clean:
	rm -f $(OBJS) $(TARGET)

# ============================================================
# End of Makefile
# ============================================================
# Usage:
#   make          → builds the project
#   make clean    → removes compiled files
# ============================================================
