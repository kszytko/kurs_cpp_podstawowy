#pragma once
#include <string>

int NWD(const int lhs, const int rhs) {
    int first = abs(lhs), 
        second = abs(rhs), 
        diff = 0;

    if(lhs == 0 || rhs == 0){ 
        return lhs + rhs; 
    }

    while(second != 0){
        diff = a % b;
        first = second;
        second = diff;
    }
    
    return first;
}

int NWW(const int lhs, const int rhs) {
    if(lhs && rhs){
        return abs(lhs * rhs) / NWD(lhs, rhs);
    }
    return 0;
}
