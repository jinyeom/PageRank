#include <iostream>
#include <fstream>
#include <exception>

#include <string>

#include "../include/graph.h"
#include "../include/util.h"

// Construct an empty graph.
Graph::Graph(): n_nodes_(0), n_edges_(0), a_(), ia_({0}), ja_() {}

// Read and store a graph from a file specified by the argument file name 
// and its format.
void Graph::ReadFromFile(const std::string &filename, const std::string &format) {
    std::ifstream f;
    std::string line;
    std::vector<std::string> tokens;
    char err_buf[64];

    if (format.compare("DIMACS") == 0) {
        // A boolean indicator that checks for the problem line in the DIMACS
        // file. Set to true if the file's problem line is read.
        bool problem_read = false;

        f.open(filename, std::ifstream::in);
        for (int i = 1; std::getline(f, line); ++i) {
            Split(line, " ", tokens);
            if (tokens[0].compare("c") == 0) {
                // comment; do nothing
            } else if (tokens[0].compare("p") == 0) {
                // problem line
                if (problem_read) {
                    sprintf(err_buf, "%s:%d: found miltiple problem lines", filename.c_str(), i);
                    throw std::logic_error(err_buf);
                }
                if (tokens.size() != 4) {
                    sprintf(err_buf, "%s:%d: invalid number of tokens", filename.c_str(), i);
                    throw std::length_error(err_buf);
                }
                n_nodes_ = std::stoul(tokens[2]);
                n_edges_ = std::stoul(tokens[3]);
                problem_read = true;
            } else if (tokens[0].compare("a") == 0) {
                // edge descriptor
                if (!problem_read) {
                    sprintf(err_buf, "%s:%d: edge read before the problem line", filename.c_str(), i);
                    throw std::logic_error(err_buf);
                }
                if (tokens.size() != 4) {
                    sprintf(err_buf, "%s:%d: invalid number of tokens", filename.c_str(), i);
                    throw std::length_error(err_buf);
                }
                ia_.push_back(std::stoul(tokens[1])); // src node ID
                ja_.push_back(std::stoul(tokens[2])); // dst node ID
                a_.push_back(std::stod(tokens[3])); // edge weight
            } else {
                sprintf(err_buf, "%s:%d: line starts with unknown token", filename.c_str(), i);
                throw std::invalid_argument(err_buf);
            }
            tokens.clear();
        }
        f.close();
    } else {
        // Handle invalid file formats.
        sprintf(err_buf, "%s: invalid file format `%s`", filename.c_str(), format.c_str());
        throw std::invalid_argument(err_buf);
    }
}