# ---
# Makefile for GNU/LINUX
# Matthew Behlke
# traffic
# ---

## Compilation parameters
CC = g++
CFLAGS = -std=c++0x

## Testing parameters


## Main
entry: node.o car.o entry.o node_graph.o node_search.o
	$(CC) $(CFLAGS) -o entry node.o car.o entry.o node_graph.o node_search.o

node.o: src/node.cc src/node.h
	$(CC) $(CFLAGS) -c src/node.cc
	
car.o: src/car.cc src/car.h
	$(CC) $(CFLAGS) -c src/car.cc
	
node_graph.o: src/node_graph.cc src/node_graph.h
	$(CC) $(CFLAGS) -c src/node_graph.cc

node_search.o: src/node_search.cc src/node_search.h
	$(CC) $(CFLAGS) -c src/node_search.cc
	
entry.o: src/entry.cc
	$(CC) $(CFLAGS) -c src/entry.cc
	
## Execution
run: entry
	./entry
	
## Testing
test: entry
	./entry
	
## Clean
clean:
	rm -f *.o