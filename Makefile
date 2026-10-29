# cartesian-c-ncurses makefile

# compiler
CC = clang

# compiler flags
CFLAGS = -Wall -Wextra -pedantic -Wno-gnu-statement-expression

# linker flags
LDFLAGS = -lncurses -lm -lcmocka

# header files
INCLUDES = -Iheaders

# list all .c files in src
SRC = $(shell find src -name "*.c")

# testing .c files
TEST_SRC = $(wildcard tests/*.c)

# for each .c file, create a .o object file
OBJ = $(SRC:.c=.o)

# name of executable
EXEC = cartesian-c-ncurses

# Default target to build the project when 'make' is run with no arguments
# This is the first target and will build the executable
all: $(EXEC)

# Rule to create the executable file from the object files
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Test target: compiles src files (except main) and test files
test: $(filter-out src/main.o, $(OBJ))
	$(CC) $(CFLAGS) $(INCLUDES) $(filter-out src/main.o, $(OBJ)) $(TEST_SRC) -o test_runner $(LDFLAGS)
	./test_runner

# Rule to compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean: remove object and executable files
clean:
	rm -f $(OBJ) $(EXEC) test_runner

# Run the compiled program (after it's built)
run: $(EXEC)
	./$(EXEC)
