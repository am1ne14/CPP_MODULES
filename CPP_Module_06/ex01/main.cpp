#include "Serializer.hpp"

#include <iostream>

int	main(void)
{
	Data		data;
	Data		*restored;
	uintptr_t	raw;

	data.id = 42;
	data.label = "module06";
	raw = Serializer::serialize(&data);
	restored = Serializer::deserialize(raw);
	std::cout << "original:   " << &data << std::endl;
	std::cout << "serialized: " << raw << std::endl;
	std::cout << "restored:   " << restored << std::endl;
	if (restored == &data)
		std::cout << "Result: OK" << std::endl;
	else
		std::cout << "Result: KO" << std::endl;
	return (0);
}
