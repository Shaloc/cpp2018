#ifndef __CLIBARRAY__
#define __CLIBARRAY__

#include <iostream>
#define DEF_CAP (10)

typedef int Rank;

class CArray
{
private:
    Rank _size;
    int _capacity;
    int* _elem;

protected:
    void expand();

public:
    CArray() {
        _size = 0;
        _capacity = DEF_CAP;
        _elem = new int[_capacity];
    }
    ~CArray() {
        _size = 0;
        _capacity = 0;
        delete[] _elem;
        _elem = NULL;
    }
    void recap(int c);
    int at(int r) const  { return _elem[r]; }
    int& at(int r)  { return _elem[r]; }
    int size() const { return _size; }
    int capacity() const { return _capacity; }
    void append(int e);
    void insert(Rank r, int e);
    void copy(const CArray &array);
    bool compare(const CArray& array) const;

};

#endif
