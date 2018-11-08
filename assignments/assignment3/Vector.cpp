#include <iostream>
#include "Vector.h"

Vector Vector::INVALID_VECTOR;

double Vector::operator[](int rank) const {
    return _data[rank];
}

Vector Vector::operator+(const Vector &rhs) const {
    if(rhs.size() != _length)
        return Vector::INVALID_VECTOR;
    auto temp_data = new double[rhs.size()];
    for(int i = 0; i < rhs.size(); ++i) {
        temp_data[i] = rhs[i] + _data[i];
    }
    return Vector(rhs.size(), temp_data);
}

Vector Vector::operator+(double rhs) const {
    auto temp_data = new double[_length];
    for(int i = 0; i < _length; ++i) {
        temp_data[i] = rhs + _data[i];
    }
    return Vector(_length, temp_data);
}

Vector Vector::operator-(const Vector &rhs) const {
    if(rhs.size() != _length)
        return Vector::INVALID_VECTOR;
    auto temp_data = new double[rhs.size()];
    for(int i = 0; i < rhs.size(); ++i) {
        temp_data[i] = rhs[i] - _data[i];
    }
    return Vector(rhs.size(), temp_data);
}

Vector Vector::operator-(double rhs) const {
    auto temp_data = new double[_length];
    for(int i = 0; i < _length; ++i) {
        temp_data[i] = rhs - _data[i];
    }
    return Vector(_length, temp_data);
}

Vector Vector::operator-() const {
    auto temp_data = new double[_length];
    for(int i = 0; i < _length; ++i) {
        temp_data[i] = -_data[i];
    }
    return Vector(_length, temp_data);
}

bool Vector::operator==(const Vector &rhs) const {
    if (&(*this) == &rhs && &rhs == &Vector::INVALID_VECTOR)
        return true;

    if(_length == rhs.size()) {
        for(int i = 0; i < _length; ++i) {
            if(_data[i] != rhs[i])
                return false;
        }
        return true;
    }
    return false;
}

bool Vector::operator!=(const Vector &rhs) const {
    return !((*this) == rhs);
}

Vector Vector::operator*(double rhs) const {
    auto temp_data = new double[_length];
    for(int i = 0; i < _length; ++i) {
        temp_data[i] = rhs * _data[i];
    }
    return Vector(_length, temp_data);
}

Vector& Vector::operator=(double rhs) {
    for(int i = 0; i < _length; ++i) {
        _data[i] = rhs;
    }
    return (*this);
}

Vector& Vector::operator=(int rhs) {
    for(int i = 0; i < _length; ++i) {
        _data[i] = rhs;
    }
    return (*this);
}

void Vector::display() {
    std::cout << "\n============";
    for ( int i = 0; i < _length; ++i) {
        std::cout << _data[i] << ' ';
    }
    std::cout << "\n============\n";
}

Vector::~Vector() {
    delete [] _data;
    _data = nullptr;
}