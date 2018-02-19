#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>

// Graph represented as a sparse matrix in CSR (Compressed Sparse Row) format. 
class Graph {
private:
    unsigned long n_nodes_;         // number of nodes
    unsigned long n_edges_;         // number of edges
    std::vector<double> a_;         // edge weights (elements in the sparse matrix)
    std::vector<unsigned long> ia_; // source nodes (row indices of the elements)
    std::vector<unsigned long> ja_; // destination nodes (column indices of the elements)

public:
    Graph();

    std::vector<double> A() const { return a_; }
    std::vector<unsigned long> IA() const { return ia_; }
    std::vector<unsigned long> JA() const { return ja_; }

    void ReadFromFile(const std::string& filename, const std::string& format);
};

#endif
