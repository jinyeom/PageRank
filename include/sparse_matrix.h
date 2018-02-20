#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <vector>

// Sparse matrix entry.
template <typename T>
class Entry {
public:
    Entry(int i, int j);        // empty entry
    Entry(int i, int j, T v);   // nonempty entry

    int I() const { return i_; }
    int J() const { return i_; }
    T V() const { return v_; }
    bool IsEmpty() const { return is_empty_; }

    void SetEmpty() { is_empty_ = true; v_ = T(); }
    void SetV(T v) { is_empty_ = false; v_ = v; }

private:
    int i_;         // row index
    int j_;         // column index
    T v_;           // entry value
    bool is_empty_; // true if the entry is empty
};

// Sparse matrix with CSR (Compressed Sparse Row) format.
template <typename T>
class SparseMatrix {
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

private:
    int m_; // number of rows
    int n_; // number of columns

    std::vector<Entry<T>*> a_;  // nonzero entries
    std::vector<int> ia_;       // indices in JA for each row
    std::vector<int> ja_;       // column indices of elements in A
};

#endif