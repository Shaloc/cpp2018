
#include <iostream>
#include "CLibArray.h"

void CArray::expand() {
    if(_size < _capacity) return;
    if(_capacity < DEF_CAP)
        _capacity = DEF_CAP;
    int* _oldElem = _elem;
    _elem = new int[_capacity <<= 1];
    for(int i = 0; i < _size; i++)
    {
        _elem[i] = _oldElem[i];
    }
}

void CArray::recap(int c) {
    if(c > _size)
    {
        _capacity = c;
        int* _oldElem = _elem;
        delete [] _elem;
        _elem = new int[_capacity];
        if(_size != 0)
        {
            for(int i = 0; i < _size; i++)
            {
                _elem[i] = _oldElem[i];
            }
            delete [] _oldElem;
        }
    } else if(c == _size) {
        return;
    } else if(c < _size) {
        _capacity = c;
        int* _oldElem = _elem;
        delete [] _elem;
        _elem = new int[_capacity];
        if(_size != 0)
        {
            for(int i = 0; i < _capacity; ++i)
            {
                _elem[i] = _oldElem[i];
            }
            _size = _capacity;
        }
    }
}

void CArray::append(int e) {
    expand();
    _elem[_size] = e;
    _size ++;
}

void CArray::insert(Rank r, int e) {
    int i = 0;
    expand();
    for(i = _size; i > r; i--)
        _elem[i] = _elem[i - 1];
    _elem[i] = e;
    _size ++;
}

void CArray::copy(const CArray &array) {
    int size = array.size();
    _capacity = array.capacity();
    _size = 0;
    delete [] _elem;
    _elem = new int[_capacity];
    for(int i = 0; i < size; i++){
        _elem[i] = array.at(i);
        _size++;
    }
}

bool CArray::compare(const CArray& array) const {
    int sizeA = _size;
    int sizeB = array.size();
    int i = 0;
    if(sizeA != sizeB)
        return false;
    else
    {
        for(i = 0; i < sizeA; i++)
        {
            if(_elem[i] != array.at(i))
                break;
        }
        if(i != sizeA)
            return false;
        else
            return true;
    }
}