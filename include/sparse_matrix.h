#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <vector>

// Sparse matrix entry.
template <typename T>
class Entry {
private:
    bool empty_;    // indicates whether the entry is empty
    T v_;           // value of the entry

public:
    Entry();    // empty entry
    Entry(T v); // nonempty entry

    bool IsEmpty() const { return empty_; }
    T V() const { return v_; }

    void SetEmpty(); { empty_ = true; v_ = T(); }
    void SetV(T v); { empty_ = false; v_ = v; }
};

// Sparse matrix with CSR (Compressed Sparse Row) format.
template <typename T>
class SparseMatrix {
private:
    int m_; // number of rows
    int n_; // number of columns

    std::vector<Entry<T>*> a_;  // nonzero entries
    std::vector<int> ia_;       // indices in JA for each row
    std::vector<int> ja_;       // column indices of elements in A

public:
    SparseMatrix(int n);
    SparseMatrix(int m, int n);

    int M() const { return m_; }
    int N() const { return n_; }
    std::vector<T> A() const { return a_; }
    std::vector<int> IA() const { return ia_; }
    std::vector<int> JA() const { return ja_; }

    // Get an element at (i, j).
    Entry<T>* Get(int i, int j) const;
    // Set an element at (i, j) with v.
    void Set(int i, int j, T v);
};

#endif