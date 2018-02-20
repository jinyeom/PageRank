#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>

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