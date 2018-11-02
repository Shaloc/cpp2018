//
// Created by shaloc on 2018/10/25.
//

#ifndef CPPLAB_OWNER_H
#define CPPLAB_OWNER_H

#include "member.h"

class owner {
private:
    A a;
    B b;
    C c;
public:
    owner();
    owner(const owner& x);
    ~owner();
    owner& operator=(const owner& rhs);
public:

};

#endif //CPPLAB_OWNER_H
