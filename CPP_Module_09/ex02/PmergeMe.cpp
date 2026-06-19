#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string &s) const
{
	if (s.empty())
		return false;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}

	long val = std::atol(s.c_str());
	return (val > 0 && val <= 2147483647);
}

bool PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string s = argv[i];

		if (!isValidNumber(s))
		{
			std::cerr << "Error" << std::endl;
			return false;
		}

		int n = std::atoi(s.c_str());
		_vec.push_back(n);
		_deq.push_back(n);
	}
	return true;
}

void PmergeMe::sortAndPrint()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::vector<int> v = _vec;
	std::deque<int> d = _deq;

	clock_t start, end;
	double vecTime, deqTime;

	start = clock();
	fordJohnsonSort(v);
	end = clock();
	vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	fordJohnsonSort(d);
	end = clock();
	deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);

	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : "
			  << vecTime << " us" << std::endl;

	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque : "
			  << deqTime << " us" << std::endl;
}
