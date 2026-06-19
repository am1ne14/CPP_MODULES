#ifndef PMERGEME_TPP
#define PMERGEME_TPP

template <typename T>
void PmergeMe::binaryInsert(T &c, int value)
{
	typename T::iterator it = std::lower_bound(c.begin(), c.end(), value);
	c.insert(it, value);
}

template <typename T>
void PmergeMe::fordJohnsonSort(T &c)
{
	if (c.size() <= 1)
		return;

	T mainChain;
	T pend;

	size_t i = 0;
	for (; i + 1 < c.size(); i += 2)
	{
		if (c[i] < c[i + 1])
		{
			mainChain.push_back(c[i + 1]);
			pend.push_back(c[i]);
		}
		else
		{
			mainChain.push_back(c[i]);
			pend.push_back(c[i + 1]);
		}
	}

	if (i < c.size())
		pend.push_back(c[i]);

	fordJohnsonSort(mainChain);

	for (size_t j = 0; j < pend.size(); j++)
		binaryInsert(mainChain, pend[j]);

	c = mainChain;
}

#endif
