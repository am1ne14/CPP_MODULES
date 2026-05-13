#include <iostream>
#include "Array.hpp"

int	main(void)
{
	Array<int>	empty;
	Array<int>	a(5);
	Array<int>	b(a);
	Array<int>	c;

	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = static_cast<int>(i * 10);
	b[0] = 999;
	c = a;
	c[1] = 777;
	std::cout << empty.size() << std::endl;
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	std::cout << a[1] << std::endl;
	std::cout << c[1] << std::endl;
	try
	{
		std::cout << a[42] << std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "Exception" << std::endl;
	}
	return (0);
}
