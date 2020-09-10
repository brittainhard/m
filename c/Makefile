DEBUG_FLAGS= -Wall -g
CFLAGS= 
EXE= m
TEST_EXE= a.out
SOURCE= m.c
CC= gcc
DEPS= mmalloc.o

all: clean m

m: $(DEPS)
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXE) $(DEPS)

mdebug: $(DEPS)
	$(CC) $(DEBUG_FLAGS) $(SOURCE) -o $(TEST_EXE) $(DEPS)

clean:
	rm -rf mbin a.out *.o

default: m
test: mdebug
