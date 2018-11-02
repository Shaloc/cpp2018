//
// Created Cy shaloc on 2018/10/25.
//
#include <iostream>
#include "member.h"

using namespace std;

A::A() {
    cout << "A::A()" << endl;
}

A::A(const A &rhs) {
    cout << "A::A(const A &rhs)" << endl;
}

A::~A() {
    cout << "A::~A" << endl;
}

B::B() {
    cout << "B::B()" << endl;
}

B::~B() {
    cout << "B::~B" << endl;
}

C::C() {
    cout << "C::C()" << endl;
}

C::~C() {
    cout << "C::~C" << endl;
}