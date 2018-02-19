# Makefile for PageRank
CC=g++
CFLAGS=-std=c++11
SOURCES=./src/main.cpp ./src/graph.cpp ./src/util.cpp
EXECUTABLE=pagerank

all: $(EXECUTABLE)

$(EXECUTABLE): 
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@

clean:
	rm $(EXECUTABLE)