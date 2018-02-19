#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>

// Print the argument vector.
template<typename T> void PrintVector(const std::vector<T> &v) {
    std::cout << "[ ";
    for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

// Split the argument string, tokenize it with the argument deliminator, and
// store its tokens in the argument vector.
void Split(const std::string &s, const char *delim, std::vector<std::string> &v) {
    char *dup = strdup(s.c_str());
    char *token = strtok(dup, delim);
    while (token != NULL) {
        v.push_back(std::string(token));
        token = strtok(NULL, delim);
    }
    free(dup);
}