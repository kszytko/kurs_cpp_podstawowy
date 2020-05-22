#pragma once
#include <string>

int NWD(const int lhs, const int rhs) {
    int a = abs(lhs), b = abs(rhs), diff = 0;

    if(lhs == 0){ return rhs; }
    if(rhs == 0){ return lhs; }

    while(b != 0){
        diff = a % b;
        a = b;
        b = diff;
    }
    
    return a;
}

int NWW(const int lhs, const int rhs) {
    if(lhs && rhs){
        return abs(lhs * rhs) / NWD(lhs, rhs);
    }
    return 0;
}
