#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    // Helper functions for vector
    void _fordJohnsonVector(std::vector<int>& arr);
    void _insertVector(std::vector<int>& mainChain, std::vector<int>& pendingElements, const std::vector<int>& jacobsthal);
    
    // Helper functions for deque
    void _fordJohnsonDeque(std::deque<int>& arr);
    void _insertDeque(std::deque<int>& mainChain, std::deque<int>& pendingElements, const std::vector<int>& jacobsthal);

    std::vector<int> _generateJacobsthal(int n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    bool parseArguments(int argc, char** argv);
    void process();
};

#endif
