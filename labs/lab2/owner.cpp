//
// Created by shaloc on 2018/10/25.
//
#include <iostream>
#include "owner.h"

using namespace std;

owner::owner() : a(), c(), b() {
    cout << "owner::owner()" << endl;
}

owner::~owner() {
    cout << "owner::~owner()" << endl;
}

owner::owner(const owner& rhs) : a(rhs.a), c(rhs.c) {
    cout << "owner::owner(const owner& x)" << endl;
}

owner& owner::operator=(const owner &rhs) {
    cout << "owner::operator=(const owner &rhs)" << endl;
    return *this;
}