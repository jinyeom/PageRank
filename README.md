# PageRank
C++ Implementation of the PageRank Algorithm

## Installation
The program can be compiled through `make` command in the PageRank directory.

## Usage
After pagerank is compiled, it can be run via the following command:
```
./pagerank --filename [GRAPH_FILE] --fmt DIMACS --style pull --df 0.85
```
where [GRAPH\_FILE] is replaced with the graph file name (.dimacs). In addition,
when adding `--csr` flag to the command, the graph matrix (CSR formatted) is also printed.
Make sure to stream the output to a file (>).

The program is also parameterized by the file format (currently, only DIMACS is supported),
style (pull or push), and the damping factor.
