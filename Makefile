# Define the compiler to use
CC = clang

# Define compiler flags for warnings and other checks
CFLAGS = -Wall -Wextra -pedantic -Wno-gnu-statement-expression

# Define linker flags 
LDFLAGS = -lncurses -lm

# List all source files in the project
SRC = src/main.c src/point.c src/rect.c src/cross.c src/colour_pairs.c src/func.c src/circle.c src/numberline.c

# Define object files based on the source files (for each .c file, create a .o file)
OBJ = $(SRC:.c=.o)

# Define the name of the final executable
EXEC = cartesian-c-ncurses

# Default target to build the project when 'make' is run with no arguments
# This is the first target and will build the executable
all: $(EXEC)

# Rule to create the executable file from the object files
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Rule to compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -Iheaders -c $< -o $@

# Clean up generated files like object files, executables, binaries
clean:
	rm -f $(OBJ) $(EXEC) 

# Run the compiled program (after it's built)
run: $(EXEC)
	./$(EXEC)
