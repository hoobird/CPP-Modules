#include "Singleton.hpp"
#include <stdio.h>

Singleton& Singleton::getInstance()
{
    if (!instance) {
        instance = new Singleton();
    }
    return *instance;
}

Singleton::Singleton()
{
    // Constructor implementation
}

Singleton::~Singleton()
{
    // Destructor implementation
}

void Singleton::doSomething()
{
    // Example method
    printf("Doing something!\n");
}