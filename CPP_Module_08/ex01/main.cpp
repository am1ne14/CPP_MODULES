#include "Span.hpp"


int	main()
{
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "-----" << std::endl;

	Span big(10000);

	std::vector<int> values;

	for (int i = 0; i < 10000; i++)
		values.push_back(i);
	big.addRange(values.begin(), values.end());
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;

	return (0);
}
