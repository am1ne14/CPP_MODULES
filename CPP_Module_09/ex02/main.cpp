#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe p;

	if (!p.parse(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	p.run();
	return 0;
}
