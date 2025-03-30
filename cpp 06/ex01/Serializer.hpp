#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

#ifndef uintptr_t
typedef unsigned long uintptr_t;
#endif

struct Data {
    int id;
    std::string name;
};

class Serializer {
public:
    Serializer();
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer& operator=(const Serializer& other);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
