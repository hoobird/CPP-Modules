#include "Serializer.hpp"
#include <iostream>
#include <string>

// Simple data structure for testing
struct Data {
    int id;  // 4 bytes
    std::string name; // after 4 bytes
    
    // Print function for verification
    void print() const {
        std::cout << "[Data] id: "<< id << ", name:  " << name << std::endl;
    }
};

int main() {
    Data* data = new Data;
    data->id = 42;
    data->name = "Example Lorem Ipsum Lmao";
    
    std::cout << "Original data address: " << data << std::endl;
    std::cout << "Original ";
    data->print();
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    // Deserialize back to pointer
    Data* deserialized = static_cast<Data*>(Serializer::deserialize(serialized));
    
    // Verify the deserialized pointer
    std::cout << "Deserialized data address: " << deserialized << std::endl;
    std::cout << "Deserialized ";
    deserialized->print();
    
    // Check if original and deserialized pointers is same
    std::cout << "\nPointer comparison: " 
              << (data == deserialized ? "matchy matchy yay ✅" : "different gg.com ❌") 
              << std::endl;
    
    delete data;
    
    return 0;
}