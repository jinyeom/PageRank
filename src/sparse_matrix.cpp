#include <vector>
#include <stdexcept>

#include "../include/sparse_matrix.h"

// Construct an empty sparse matrix entry.
template <typename T>
Entry<T>::Entry(int i, int j): i_(i), j_(j), v_(), is_empty_(true) {}

// Construct a sparse matrix entry with a value.
template <typename T>
Entry<T>::Entry(int i, int j, T v): i_(i), j_(j), v_(v), is_empty_(false) {}

// Construct a square sparse matrix given its dimensions.
template <typename T>
SparseMatrix<T>::SparseMatrix(int n): m_(n), n_(n), a_(), ia_(n + 1), ja_() {}

// Construct a sparse matrix given its dimensions.
template <typename T>
SparseMatrix<T>::SparseMatrix(int m, int n): m_(m), n_(n), a_(), ia_(m + 1), ja_() {}

// Get an entry at (i, j); return an empty entry if there is no match.
template <typename T> 
Entry<T>* SparseMatrix<T>::Get(int i, int j) const {
    if (i < 0 || i >= m_ || j < 0 || j >= n_) {
        throw std::out_of_range("invalid coordinates (i, j)");
    }
    for (int pos = ia_[i]; pos < ia_[i + 1]; ++pos) {
        if (ja_[pos] == j) {
            return a_[pos];
        }
    }
    // If there's no match, return a new empty entry.
    return new Entry<T>(i, j);
}

// Set an element at (i, j) with v.
template <typename T> 
void SparseMatrix<T>::Set(int i, int j, T v) {
    int pos = ia_[i];
    while (pos < ia_[i + 1] && ja_[pos] != j) {
        pos++;
    }
    if (ja_[pos] != j) {
        // If the argument position is empty, insert a new entry.
        // Same as in Get(), if the correct column is found, there is
        // a nonzero entry.
        a_.insert(a_.begin() + pos, new Entry<T>(i, j, v));
        ja_.insert(ja_.begin() + pos, j);
        for (int r = i + 1; r <= m_; ++r) {
            ia_[r] += 1;
        }
    } else {
        // There is already a value at (i, j); set a different value.
        for (int pos = ia_[i]; pos < ia_[i + 1]; ++pos) {
            if (ja_[pos] == j) {
                a_[pos].SetV(v);
                return;
            }
        }
    }
}