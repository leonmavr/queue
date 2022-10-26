###################################################
# definitions                                     #
###################################################
CC = gcc

INCL_DIR = .
CFLAGS = -std=c99 -I$(INCL_DIR) -Wall
TEST_DIR = tests
EXEC = $(TEST_DIR)/tests
#SOURCES = $(wildcard $(TESTS_DIR)*.c)
SOURCES = $(TEST_DIR)/tests.c
OBJECTS = $(SOURCES:%.c=%.o)
RM = rm -rf

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LDFLAGS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean

clean: 
	$(RM) $(TEST_DIR)/*.o
	$(RM) $(EXEC)
