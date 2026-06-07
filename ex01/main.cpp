#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data memory;

    memory.memoryName = "Extraordinary Rock";
    memory.memoryRank = "Awakened";
    memory.memoryPower = 50;
    memory.fragments = 1;
    memory.isBound = true;

    std::cout << "Original address: " << &memory << std::endl;
    std::cout << "Name: " << memory.memoryName << std::endl;

    uintptr_t raw = Serializer::serialize(&memory);

    std::cout << "\nRaw value: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    std::cout << "\nRecovered address: " << ptr << std::endl;
    std::cout << "Name: " << ptr->memoryName << std::endl;

    if (ptr == &memory)
        std::cout << "\nOK" << std::endl;

    return 0;
}