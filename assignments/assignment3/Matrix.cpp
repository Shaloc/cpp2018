#include <iostream>
#include <memory>
#include "Matrix.h"

Matrix Matrix::INVALID_MATRIX;

Matrix::Matrix(int rows, int cols, double* data): _valid(1) {
    _rows = rows;
    _cols = cols;
    _data = new double[rows*cols];
    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            _data[cols * i + j] = data[cols * i + j];
        }
    }
}

Matrix::Matrix(int rows, int cols, double data): _valid(1) {
    _rows = rows;
    _cols = cols;
    _data = new double[rows*cols];
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            _data[cols * i + j] = data;
}

Matrix::Matrix(const Matrix &rhs): _valid(1) {
    _rows = rhs.rows();
    _cols = rhs.cols();
    _data = new double[_rows*_cols];
    for(int i = 0; i < _rows; ++i)
        for(int j = 0; j < _cols; ++j)
            _data[_cols * i + j] = rhs[i][j];
}

Matrix::Matrix(const Vector &rhs): _valid(1)  {
    _rows = 1;
    _cols = rhs.size();
    _data = new double[_cols];
    for(int j = 0; j < _cols; ++j)
        _data[j] = rhs[j];
}

int Matrix::rows() const {
    return _rows;
}

int Matrix::cols() const {
    return _cols;
}

double* const Matrix::operator[](int row) const {
    double* temp = new double[_rows*_cols];
    for(int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            temp[_cols * i + j] = _data[_cols * i + j];
        }
    }
    return &temp[row*_cols];
}

bool Matrix::operator==(const Matrix &rhs) const {
    if (&(*this) == &rhs && &rhs == &Matrix::INVALID_MATRIX)
        return true;
    if (_rows != rhs.rows() || _cols != rhs.cols())
        return false;
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            if (_data[_cols * i + j] != rhs[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &rhs) const {
    return !((*this) == rhs);
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    if (_cols != rhs.cols() || _rows != rhs.rows())
        return Matrix::INVALID_MATRIX;
    else {
        double* temp = new double[_rows * _cols];
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                temp[_cols * i + j] = (*this)[i][j] + rhs[i][j];
            }
        }
        return Matrix(_rows, _cols, temp);
    }
}

Matrix Matrix::operator-(const Matrix &rhs) const {
    if (_cols != rhs.cols() || _rows != rhs.rows())
        return Matrix::INVALID_MATRIX;
    double* temp = new double[_rows*_cols];
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            temp[_cols * i + j] = (*this)[i][j] - rhs[i][j];
        }
    }
    return Matrix(_rows, _cols, temp);
}

Matrix Matrix::operator-() const {
    double* temp = new double[_rows*_cols];
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            temp[_cols * i + j] = -(*this)[i][j];
        }
    }
    return Matrix(_rows, _cols, temp);
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    if (_cols != rhs.rows())
        return Matrix::INVALID_MATRIX;
    double* temp = new double[_rows*rhs.cols()];
    int result_cols = rhs.cols();
    int result_rows = _rows;
    int calc_time = _cols;
    for (int i = 0; i < result_rows; ++i) {
        for (int j = 0; j < result_cols; ++j) {
            temp[result_cols*i + j] = 0;
            for(int k = 0; k < calc_time; ++k)
                temp[result_cols*i + j] += rhs[k][j] * (*this)[i][k];
        }
    }
    return Matrix(_rows, rhs.cols(), temp);
}

Matrix Matrix::operator*(int rhs) const {
    double* temp = new double[_rows*_cols];
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            temp[_cols * i + j] = _data[_cols*i + j] * rhs;
        }
    }
    return Matrix(_rows, _cols, temp);
}

Matrix Matrix::trans() const {
    double* temp = new double[_rows*_cols];
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            temp[_rows * j + i] = _data[_cols * i + j];
        }
    }
    return Matrix(_cols, _rows, temp);
}

void Matrix::display() {
    std::cout << "============";
    for (int i = 0; i < _rows; ++i) {
        std::cout << "\n";
        for (int j = 0; j < _cols; ++j) {
            std::cout << (*this)[i][j] << " ";
        }
    }
    std::cout << "\n============\n";
}

Matrix::~Matrix() {
    delete[](_data);
    _data = NULL;
    _valid = 0;
}