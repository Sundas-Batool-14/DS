#include <iostream>
#include "bst.h"
int main()
{
    bst<int> b;
    b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(2);
    b.insert(4);
    b.insert(9);

    std::cout << b.size() << std::endl;

    std::cout<< b.contains(7) << std::endl;

}
