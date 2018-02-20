// Simple implementation of the PageRank algorithm.
// Author: Jin Yeom (jinyeom@utexas.edu)
//
// This program reads a graph from a file with DIMACS format, and performs
// the PageRank algorithm to rank each node in the graph.

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <exception>

#include "../include/graph.h"
#include "../include/util.h"

void Usage(char *prog) {
    std::cout << "Usage: " << prog
              << " --filename FILENAME"
              << " --fmt FORMAT"
              << " --style STYLE"
              << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 7) {
        Usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    std::string filename;
    std::string filefmt;
    std::string style;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--filename") == 0) {
            filename = argv[++i];
        } else if (strcmp(argv[i], "--fmt") == 0) {
            filefmt = argv[++i];
        } else if (strcmp(argv[i], "--style") == 0) {
            style = argv[++i];
            if (style.compare("pull") != 0 && style.compare("push") != 0) {
                Usage(argv[0]);
                return EXIT_FAILURE;
            }
        } else {
            Usage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    Graph *graph = new Graph();
    try {
        graph->ReadFromFile(filename, filefmt);
    } catch (std::exception &e) {
        std::cout << "\x1b[31merror\x1b[0m: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<double> weights = graph->A();
    std::vector<int> rows = graph->IA();
    std::vector<int> cols = graph->JA();

    PrintVector(weights);
    PrintVector(rows);
    PrintVector(cols);

    return EXIT_SUCCESS;
}
