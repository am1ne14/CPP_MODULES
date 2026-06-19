#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	bool isValidNumber(const std::string &s) const;

	template <typename T>
	void fordJohnsonSort(T &c);

	template <typename T>
	void binaryInsert(T &mainChain, int value);

public:
	PmergeMe();
	~PmergeMe();

	bool parseInput(int argc, char **argv);
	void sortAndPrint();
};

#include "PmergeMe.tpp"

#endif
