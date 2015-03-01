#include <iostream>
#include "sort/sort.h"
#include "list/list.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int ret=0;
    ret=DoList();
    if (ret!=0)
    {
        std::cerr<<"do list fail!"<<std::endl;
    }
    return 0;
}