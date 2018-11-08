//
// Created by shaloc on 2018/11/8.
//

#include <iostream>
#include <vector>
#include <list>
#include "value.h"

using namespace std;

int main(int argc, char** argv) {
    // ops
    Value a(3);
    Value b(4);
    Value c;
    c += a;
    cout << c << endl;
    ValuePtr ptr(&a);
    cout << (*ptr)[3] << endl;
    cout << ptr->value() << endl;
    cout << "=====================" << endl;
    // vector

    vector<Value> vector1;
    for (int idx = 0; idx < 20; ++idx) {
        Value value(idx);
        // 从后存入
        vector1.push_back(value);
    }
    for (int idx = 0; idx < 20; ++idx) {
        // 循秩访问
        cout << vector1[idx] << " ";
    }
    cout << "\n";
    // 使用迭代器访问，迭代器可以看做元素的指针
    for (vector<Value>::iterator iter = vector1.begin(); iter != vector1.end(); ++iter) {
        cout << *iter << " ";
    }

    return 0;
}