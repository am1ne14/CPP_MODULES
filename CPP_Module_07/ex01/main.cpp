#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	printElement(const T &value)
{
	std::cout << value << std::endl;
}

void	increment(int &value)
{
	++value;
}

int	main(void)
{
	int				numbers[5] = {0, 1, 2, 3, 4};
	std::string		words[3] = {"hello", "42", "cpp"};
	const int		constNumbers[3] = {7, 8, 9};

	::iter(numbers, 5, increment);
	::iter(numbers, 5, printElement<int>);
	::iter(words, 3, printElement<std::string>);
	::iter(constNumbers, 3, printElement<int>);
	return (0);
}
