#include <iostream>
#include "sort/sort.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int len;
    int ret=DoSort();
    if (ret!=0)
    {
        std::cerr<<"do fail!"<<std::endl;
    }
    return 0;
}