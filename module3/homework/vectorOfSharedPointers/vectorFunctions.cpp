#include "vectorFunctions.hpp"


std::vector<std::shared_ptr<int>> generate(int count) 
{ 
    std::vector<std::shared_ptr<int> vectorOfPointers;
    //vectorOfPointers.reserve(count);
    for (size_t i = 0; i < count; ++i)
    {
        vectorOfPointers.push_back(std::make_shared<int>(i));
    }

    return vectorOfPointers;
}