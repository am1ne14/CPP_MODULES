#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span& other) : _n(other._n), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _n)
		throw std::runtime_error("Span is full");

	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("No span found");

	std::vector<int> tmp(_numbers);

	std::sort(tmp.begin(), tmp.end());

	unsigned int shortest = static_cast<unsigned int>(tmp[1]) - static_cast<unsigned int>(tmp[0]);

	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		unsigned int span = static_cast<unsigned int>(tmp[i + 1]) - static_cast<unsigned int>(tmp[i]);
		if (span < shortest)
			shortest = span;
	}

	return (shortest);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("No span found");

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (static_cast<unsigned int>(max) - static_cast<unsigned int>(min));
}
