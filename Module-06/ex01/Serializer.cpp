#include "Serializer.hpp"

// It takes a pointer and converts it to the unsigned integer type uintptr_t.

uintptr_t Serializer::serialize(void *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// It takes an unsigned integer parameter and converts it to a pointer to Data.
void *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<void *>(raw);
}

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other)
{
    (void) other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void) other;
    return *this;
}

Serializer::~Serializer(){}
