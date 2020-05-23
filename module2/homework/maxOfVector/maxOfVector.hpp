#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    
    int max = vec[0];
    for (const auto& element : vec){
        if (element > max) max = element;
    }
    return max;
}
