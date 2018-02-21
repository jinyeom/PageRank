# Makefile for PageRank
CC=g++
CFLAGS=-std=c++11 -I ./include
SOURCES=./src/main.cpp ./src/graph.cpp ./src/util.cpp ./src/pagerank.cpp
EXECUTABLE=pagerank

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@

clean:
	rm $(EXECUTABLE)