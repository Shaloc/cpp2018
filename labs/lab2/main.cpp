#include <iostream>
#include "owner.h"
#include "member.h"

using namespace std;

int main(int argc, const char** argv) {
    owner owner1;
    cout << "==================" << endl;
    owner owner2 = owner1;
    cout << "==================" << endl;
    owner owner3;
    owner3 = owner1;
    cout << "==================" << endl;
    return 0;
}