#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>

PmergeMe::PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string &s)
{
	if (s.empty())
		return false;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			return false;
	}

	long v = std::atol(s.c_str());
	if (v < 0 || v > INT_MAX)
		return false;

	return true;
}

bool PmergeMe::parse(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string s(argv[i]);

		if (!isValidNumber(s))
			return false;

		int v = std::atoi(argv[i]);

		_vec.push_back(v);
		_deq.push_back(v);
	}
	return true;
}

std::vector<size_t> PmergeMe::jacobsthal(size_t n)
{
	std::vector<size_t> j;

	if (n == 0)
		return j;

	j.push_back(1);

	size_t a = 1;
	size_t b = 3;

	while (b < n)
	{
		j.push_back(b);
		size_t next = b + 2 * a;
		a = b;
		b = next;
	}

	return j;
}


template <typename T>
void PmergeMe::binaryInsert(T &c, int value)
{
	typename T::iterator it = std::lower_bound(c.begin(), c.end(), value);
	c.insert(it, value);
}

template <typename T>
void PmergeMe::insertPend(T &main, T &pend)
{
	if (pend.empty())
		return;

	std::vector<size_t> jac = jacobsthal(pend.size());
	std::vector<bool> used(pend.size(), false);

	for (size_t i = 0; i < jac.size(); i++)
	{
		size_t idx = jac[i] - 1;
		if (idx < pend.size() && !used[idx])
		{
			binaryInsert(main, pend[idx]);
			used[idx] = true;
		}
	}

	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!used[i])
			binaryInsert(main, pend[i]);
	}
}


template <typename T>
void PmergeMe::fordJohnson(T &c)
{
	if (c.size() <= 1)
		return;

	T main;
	T pend;

	for (size_t i = 0; i < c.size(); i += 2)
	{
		if (i + 1 < c.size())
		{
			int a = c[i];
			int b = c[i + 1];

			if (a > b)
				std::swap(a, b);

			main.push_back(b);
			pend.push_back(a);
		}
		else
			main.push_back(c[i]);
	}

	if (main.size() > 1)
		fordJohnson(main);

	insertPend(main, pend);

	c = main;
}

void PmergeMe::run()
{
	std::cout << "Before: ";

	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";

	std::cout << std::endl;

	clock_t start = clock();
	fordJohnson(_vec);
	clock_t end = clock();

	double vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clo	fordJohnson(_deq);
ck();
	end = clock();

	double deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of "
			  << _vec.size()
			  << " elements with std::vector : "
			  << vecTime << " us" << std::endl;

	std::cout << "Time to process a range of "
			  << _deq.size()
			  << " elements with std::deque : "
			  << deqTime << " us" << std::endl;
}



