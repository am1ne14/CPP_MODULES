#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) {
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        this->_vec = rhs._vec;
        this->_deq = rhs._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseArguments(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) return false;
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j])) return false;
        }
        long val = std::atol(arg.c_str());
        if (val < 0 || val > 2147483647) return false;
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
    return true;
}

std::vector<int> PmergeMe::_generateJacobsthal(int n) {
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (true) {
        int next = jacob.back() + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
        if (next >= n) break;
    }
    return jacob;
}

// Vector implementation
void mergeSortPairsVec(std::vector<std::pair<int, int> >& pairs, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortPairsVec(pairs, left, mid);
    mergeSortPairsVec(pairs, mid + 1, right);

    std::vector<std::pair<int, int> > temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (pairs[i].first <= pairs[j].first) temp.push_back(pairs[i++]);
        else temp.push_back(pairs[j++]);
    }
    while (i <= mid) temp.push_back(pairs[i++]);
    while (j <= right) temp.push_back(pairs[j++]);

    for (int k = 0; k < (int)temp.size(); ++k) {
        pairs[left + k] = temp[k];
    }
}

void PmergeMe::_fordJohnsonVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() / 2; ++i) {
        if (arr[2*i] > arr[2*i+1]) pairs.push_back(std::make_pair(arr[2*i], arr[2*i+1]));
        else pairs.push_back(std::make_pair(arr[2*i+1], arr[2*i]));
    }

    int straggler = -1;
    bool hasStraggler = (arr.size() % 2 != 0);
    if (hasStraggler) straggler = arr.back();

    mergeSortPairsVec(pairs, 0, pairs.size() - 1);

    std::vector<int> mainChain;
    std::vector<int> pending;

    mainChain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        if (i > 0) pending.push_back(pairs[i].second);
    }

    std::vector<int> jacob = _generateJacobsthal(pairs.size());
    int last_jacob = 1;
    for (size_t k = 3; k < jacob.size(); ++k) {
        int current_jacob = jacob[k];
        if (current_jacob > (int)pairs.size()) current_jacob = pairs.size();

        for (int p = current_jacob; p > last_jacob; --p) {
            int pending_idx = p - 2;
            if (pending_idx < 0 || pending_idx >= (int)pending.size()) continue;
            int val = pending[pending_idx];
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
            mainChain.insert(it, val);
        }
        last_jacob = current_jacob;
    }

    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

// Deque implementation
void mergeSortPairsDeq(std::deque<std::pair<int, int> >& pairs, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortPairsDeq(pairs, left, mid);
    mergeSortPairsDeq(pairs, mid + 1, right);

    std::deque<std::pair<int, int> > temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (pairs[i].first <= pairs[j].first) temp.push_back(pairs[i++]);
        else temp.push_back(pairs[j++]);
    }
    while (i <= mid) temp.push_back(pairs[i++]);
    while (j <= right) temp.push_back(pairs[j++]);

    for (int k = 0; k < (int)temp.size(); ++k) {
        pairs[left + k] = temp[k];
    }
}

void PmergeMe::_fordJohnsonDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() / 2; ++i) {
        if (arr[2*i] > arr[2*i+1]) pairs.push_back(std::make_pair(arr[2*i], arr[2*i+1]));
        else pairs.push_back(std::make_pair(arr[2*i+1], arr[2*i]));
    }

    int straggler = -1;
    bool hasStraggler = (arr.size() % 2 != 0);
    if (hasStraggler) straggler = arr.back();

    mergeSortPairsDeq(pairs, 0, pairs.size() - 1);

    std::deque<int> mainChain;
    std::deque<int> pending;

    mainChain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        if (i > 0) pending.push_back(pairs[i].second);
    }

    std::vector<int> jacob = _generateJacobsthal(pairs.size());
    int last_jacob = 1;
    for (size_t k = 3; k < jacob.size(); ++k) {
        int current_jacob = jacob[k];
        if (current_jacob > (int)pairs.size()) current_jacob = pairs.size();

        for (int p = current_jacob; p > last_jacob; --p) {
            int pending_idx = p - 2;
            if (pending_idx < 0 || pending_idx >= (int)pending.size()) continue;
            int val = pending[pending_idx];
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
            mainChain.insert(it, val);
        }
        last_jacob = current_jacob;
    }

    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

void PmergeMe::process() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    struct timeval start, end;

    // Vector sort
    gettimeofday(&start, NULL);
    _fordJohnsonVector(_vec);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    // Deque sort
    gettimeofday(&start, NULL);
    _fordJohnsonDeque(_deq);
    gettimeofday(&end, NULL);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
