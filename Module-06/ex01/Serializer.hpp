#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> 

class Serializer {
    
    public:
        static uintptr_t serialize(void* ptr);
        static void* deserialize(uintptr_t raw);

    private:
        Serializer(); 
        Serializer(const Serializer &other); 
        Serializer& operator=(const Serializer &other); 
        ~Serializer();

};


#endif


/*
🛠️ 3. reinterpret_cast
❗ Dangerous and low-level cast; bitwise reinterpretation
Used for:
Casting between unrelated pointer types
Casting an integer to a pointer or vice versa
For very low-level system code, such as implementing custom memory management or interfacing with hardware

eg:
cast int * to char *

10101010 10101010 10101010 10101010

to 

10101010

both pointer points to the first bit of the same memory address, 
but where they stop reading is different.
*/