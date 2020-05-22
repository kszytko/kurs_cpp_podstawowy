#pragma once
#include <vector>

std::vector<int> generateSequence(const int count, const int step) {
    std::vector<int> result(count);
    int value = 0;

    for(int i = 0; i < count; i++){
        value += step;
        result[i] = value;
    }

    return result;
}
