#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "Vector.h"

class Matrix {
private:
    double* _data;
    int _rows;
    int _cols;
public:
    int _valid;
    static Matrix INVALID_MATRIX;
    Matrix(): _valid(0) { }
    Matrix(int rows, int cols, double* data);
    Matrix(int rows, int cols, double data);
    Matrix(const Vector& rhs);
    Matrix(const Matrix& rhs);
    ~Matrix();
    int rows() const;
    int cols() const;
    double* const operator[](int row) const;
    bool operator==(const Matrix& rhs) const;
    bool operator!=(const Matrix& rhs) const;
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;
    Matrix operator-() const;
    Matrix operator*(const Matrix& rhs) const;
    Matrix operator*(double rhs) const;
    Matrix trans() const;
    void display();
};

#endif
