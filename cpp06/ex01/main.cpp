#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.data = "Hello";
	data.data1 = "World";

	std::cout << "Original Data:\n";
	std::cout << "  data: " << data.data << "\n";
	std::cout << "  data1: " << data.data1 << "\n\n";

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t value: " << raw << "\n\n";

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data pointer:\n";
	std::cout << "  data: " << ptr->data << "\n";
	std::cout << "  data1: " << ptr->data1 << "\n";

	return 0;
}