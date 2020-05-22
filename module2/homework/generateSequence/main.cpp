#include <iostream>
#include "generateSequence.hpp"

int main() {
    for (const int element : generateSequence(-3, 0))
        std::cout << element << " | ";

    return 0;
}
