#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data = {42, "Test"};
    uintptr_t raw = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Pointer Equality: " << (&data == deserialized ? "PASS" : "FAIL") << std::endl;
    std::cout << "Data Integrity: " 
              << ((deserialized->id == data.id && deserialized->name == data.name) ? "PASS" : "FAIL") << std::endl;

    uintptr_t nullRaw = Serializer::serialize(NULL);
    std::cout << "Null Pointer: " 
              << (Serializer::deserialize(nullRaw) == NULL ? "PASS" : "FAIL") << std::endl;

    return 0;
}
