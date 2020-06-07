#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vectorOfPointers;
    for (size_t i = 0; i < count; ++i) {
        vectorOfPointers.emplace_back(std::make_shared<int>(i));
    }

    return vectorOfPointers;
}

void print(const std::vector<std::shared_ptr<int>>& vectorOfPointers) {
    for (const auto& element : vectorOfPointers) {
        std::cout << *element << ' ';
    }
    std::cout << '\n';
}
void add10(const std::vector<std::shared_ptr<int>>& vectorOfPointers) {
    for (auto& element : vectorOfPointers) {
        if (element) {
            *element += 10;
        }
    }
}

void sub10(int* const vPtr) {
    if (vPtr) {
        *vPtr -= 10;
    }
}
void sub10(const std::vector<std::shared_ptr<int>>& vectorOfPointers) {
    for (auto& element : vectorOfPointers) {
        sub10(element.get());
    }
}