#include <vector>
#include <stdexcept>

#include "../include/sparse_matrix.h"

// Construct an empty sparse matrix entry.
template <typename T>
Entry::Entry(): empty_(true), v_() {}

// Construct a sparse matrix entry with a value.
template <typename T>
Entry::Entry(T v): empty_(false), v_(v) {}

// Construct a square sparse matrix given its dimensions.
template <typename T>
SparseMatrix::SparseMatrix(int n): m_(n), n_(n), a_(), ia_(n + 1), ja_() {}

// Construct a sparse matrix given its dimensions.
template <typename T>
SparseMatrix::SparseMatrix(int m, int n): m_(m), n_(n), a_(), ia_(m + 1), ja_() {}

// Get an element at (i, j).
template <typename T> 
Entry* SparseMatrix::Get(int i, int j) const {
    if (i < 0 || i >= m_ || j < 0 || j >= n_) {
        throw std::out_of_range("invalid coordinates (i, j)");
    }
    for (int pos = ia_[i]; pos < ia_[i + 1]; ++pos) {
        if (ja_[pos] == j) {
            return a_[pos];
        }
    }
    // If there's no match, return the empty value.
    // Note that returned value 0 is not the same as numerical zero, 
    // but rather an indicator of absence.
    return T();
}

// Set an element at (i, j) with v.
template <typename T> 
void SparseMatrix::Set(int i, int j, T v) {
    // If the argument position is empty, insert a new entry.
    if (Get(i, j) == T()) {
        a_.insert(a_.begin() + index, v);
        ja_.insert(ja_.begin() + index, j);
        for (int r = i; r <= m_; ++r) {
            ia_[r] += 1;
        }
    }
    
}