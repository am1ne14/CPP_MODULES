#include "identify.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	Base	*instance;
	int		i;

	std::srand(static_cast<unsigned int>(std::time(0)));
	i = 0;
	while (i < 10)
	{
		instance = generate();
		std::cout << "identify(Base*): ";
		identify(instance);
		std::cout << "identify(Base&): ";
		identify(*instance);
		delete instance;
		++i;
	}
	return (0);
}
