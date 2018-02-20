#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>

#include "sparse_matrix.h"

// Graph represented as a sparse matrix in CSR (Compressed Sparse Row) format. 
class Graph {
private:
    int n_nodes_;               // number of nodes
    int n_edges_;               // number of edges
    std::vector<double> nodes_; // node values
    SparseMatrix *edges_;       // edge values
    
public:
    Graph();

    // Read and store a graph from a file specified by the argument file name and its format.
    void ReadFromFile(const std::string& filename, const std::string& format);
};

#endif
