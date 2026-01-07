#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

#define BLACK   "\033[30m"
#define RESET   "\033[0m"

void printData(const Data* data) {
    std::cout << "Name: " << data->name << std::endl;
    std::cout << "Age: " << data->age << std::endl;
}

int main() {
    Data data1;
    data1.name = "Alice";
    data1.age = 18;
    std::cout << BLACK << "Original Data:" << RESET << std::endl;
    printData(&data1);

    uintptr_t raw = Serializer::serialize(&data1);
    std::cout << BLACK << "After serialization" << RESET << std::endl;
    std::cout << "Raw value: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << BLACK << "After deserialization:" << RESET << std::endl;
    printData(deserializedData);
    return 0;
}