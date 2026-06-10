#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
	private:
		unsigned int	_n;
		std::vector<int> _numbers;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int number);

		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end)
		{
			if (_numbers.size() + std::distance(begin, end) > _n)
				throw std::runtime_error("Span is full");
			_numbers.insert(_numbers.end(), begin, end);
		}
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};


#endif
