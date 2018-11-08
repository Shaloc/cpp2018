//
// Created by shaloc on 2018/11/8.
//

#include "value.h"

ostream& operator<<(ostream &os, const Value& value) {
    os << value.value();
    return os;
}

istream& operator>>(istream &is, Value &value) {
    double temp;
    is >> temp;
    value.set_value(temp);
    return is;
}

Value Value::operator+(const Value &rhs) const {
    return Value(_value + rhs.value());
}

Value Value::operator-(const Value &rhs) const {
    return Value(_value - rhs.value());
}

Value Value::operator*(const Value &rhs) const {
    return Value(_value * rhs.value());
}

Value Value::operator/(const Value &rhs) const {
    return Value(_value / rhs.value());
}

Value Value::operator-() const {
    return Value(-_value);
}


