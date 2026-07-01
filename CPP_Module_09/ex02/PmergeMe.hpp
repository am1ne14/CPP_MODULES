#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int>  _deq;

	bool isValidNumber(const std::string &s);

	std::vector<size_t> jacobsthal(size_t n);

	template <typename T>
	void fordJohnson(T &c);

	template <typename T>
	void insertPend(T &main, T &pend);

	template <typename T>
	void binaryInsert(T &c, int value);

public:
	PmergeMe();

	bool parse(int argc, char **argv);
	void run();
};

#endif
