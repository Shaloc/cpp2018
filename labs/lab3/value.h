//
// Created by shaloc on 2018/11/8.
//

#ifndef __VALUE_H__
#define __VALUE_H__

#include <iostream>

using namespace std;

class Value {
private:
    double _value;

public:
    Value() :_value(0) { }
    Value(double value) : _value(value) { }
    Value(const Value & rhs) : _value(rhs._value) { }

public:
    double value() const {
        return _value;
    }
    void set_value(double value) {
        _value = value;
    }

public:
    Value operator+(const Value& rhs) const;
    Value operator-(const Value& rhs) const;
    Value operator*(const Value& rhs) const;
    Value operator/(const Value& rhs) const;
    Value operator-() const;
    Value operator+=(const Value& rhs) {
        _value += rhs._value;
        return (*this);
    }

    Value operator-=(const Value& rhs) {
        _value -= rhs._value;
        return (*this);
    }

    bool operator>=(const Value& rhs) const {
        return _value >= rhs._value;
    }

    bool operator<=(const Value& rhs) const {
        return _value <= rhs._value;
    }

    bool operator>(const Value& rhs) const {
        return !((*this) <= rhs);
    }

    bool operator<(const Value& rhs) const {
        return !((*this) >= rhs);
    }

    bool operator==(const Value& rhs) const {
        return _value == rhs._value;
    }

    bool operator!=(const Value& rhs) const {
        return !((*this) == rhs);
    }

    Value operator[](double rhs) const {
        return Value(_value*rhs);
    }

    Value operator[](Value& rhs) const {
        return Value(_value * rhs.value());
    }

    Value& operator=(const Value& rhs) {
        if(&rhs == this)
            return *this;
        _value = rhs._value;
        return *this;
    }

};

class ValuePtr {
private:
    Value* _ptr;
public:
    ValuePtr(Value* ptr) : _ptr(ptr) { }
public:
    Value *operator->() { return _ptr; }
    Value &operator*() { return *_ptr; }
};

ostream& operator<<(ostream &os, const Value& value);
istream& operator>>(istream &is, Value &value);

#endif // __VALUE_H__