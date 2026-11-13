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

# for each .c file, create a .o object file
OBJ = $(SRC:.c=.o)

# testing .c files
TEST_SRC = $(wildcard tests/*.c)
TEST_OBJ = $(TEST_SRC:.c=)


# name of executable
EXEC = cartesian-c-ncurses

# default target to build project when 'make' is run with no args
all: $(EXEC)

# Rule to create executable file from object files
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

test: $(TEST_OBJ)
	@for t in $(TEST_OBJ); do ./$$t || exit 1; done

# Test target: compiles src files (except main) and test files
# pattern rule
tests/test_%: tests/test_%.c $(filter-out src/main.o, $(OBJ))
	$(CC) $(CFLAGS) $(INCLUDES) $^ -lcmocka $(LDFLAGS) -o $@

# Rule to compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean: remove object and executable files
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) 

# Run the compiled program (after it's built)
run: $(EXEC)
	./$(EXEC)
