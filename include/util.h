#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

// Print the argument vector.
template<typename T> void PrintVector(const std::vector<T> &v);

// Split the argument string, tokenize it with the argument deliminator, and
// store its tokens in the argument vector.
void Split(const std::string &s, const char* delim, std::vector<std::string>& v);

#endif