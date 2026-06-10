#include "easyfind.hpp"

int	main()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
