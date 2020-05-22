#include <iostream>
#include <vector>
#include <list>

// Implement createSortedList
// add proper include :)

std::list<int> createSortedList(const std::vector<int> vec){
    return std::list<int> {vec.begin(), vec.end()};
}

int main() {
    std::vector<int> vec{2, 3, 4, 1, 6, 5, 8, 7, 9, 0};
    auto list = createSortedList(vec);

    for (const auto& el : list)
        std::cout << el << " ";

    return 0;
}
