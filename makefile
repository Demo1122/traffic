# ---
# Makefile for GNU/LINUX
# Matthew Behlke
# traffic
# ---

## Compilation parameters
CC = g++
CFLAGS = -std=c++0x

## Testing parameters


# Main
entry: node.o car.o entry.o
	$(CC) $(CFLAGS) -o entry node.o  car.o entry.o

node.o: src/node.cc src/node.h
	$(CC) $(CFLAGS) -c src/node.cc
	
car.o: src/car.cc src/car.h
	$(CC) $(CFLAGS) -c src/car.cc
	
entry.o: src/entry.cc
	$(CC) $(CFLAGS) -c src/entry.cc
	
# Testing
test: entry
	./entry
	
## Clean
clean:
	rm -f *.o