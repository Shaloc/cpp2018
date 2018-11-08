//
// Created by shaloc on 2018/11/8.
//

#include <iostream>
#include "value.h"

using namespace std;

int main(int argc, char** argv) {
    Value a(3);
    Value b(4);
    Value c;
    c += a;
    cout << c << endl;
    ValuePtr ptr(&a);
    cout << (*ptr)[3] << endl;
    cout << ptr->value() << endl;
    return 0;
}