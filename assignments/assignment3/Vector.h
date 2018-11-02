#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

class Vector {
private:
    int _length;
    double* _data;

public:
    int _is_valid;
    static Vector INVALID_VECTOR;

    Vector():_length(0), _data(), _is_valid(0) {
        _data = NULL;
    }
    Vector(int length, const double* data):_length(length), _data(), _is_valid(1) {
        _data = new double[length];
        for(int i = 0; i < length; i++) {
            _data[i] = data[i];
        }
    }
    Vector(int length, double data): _length(length), _data(), _is_valid(1) {
        _data = new double[length];
        for(int i = 0; i < length; i++) {
            _data[i] = data;
        }
    }
    ~Vector();

public:
    int size() const { return _length; }
    bool operator==(const Vector& rhs) const;
    bool operator!=(const Vector& rhs) const;
    double operator[](int rank) const;
    Vector operator+(const Vector& rhs) const;
    Vector operator+(double rhs) const;
    Vector operator-(const Vector& rhs) const;
    Vector operator-(double rhs) const;
    Vector operator-() const;
    Vector& operator=(double rhs);
    Vector& operator=(int rhs);
    Vector operator*(double rhs) const;
    void display();
};
#endif
