#pragma once
#include <vector>

int fibonacci_iterative(int sequence) {
    std::vector<int> fib(sequence + 1);

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < sequence + 1; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    return fib.back();
}

int fibonacci_recursive(int sequence) {
    if(sequence <= 1)
        return sequence;
    return fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1);
}


//0 1 2 3 4 5 6 7
//0 1 1 2 3 5 8 13
