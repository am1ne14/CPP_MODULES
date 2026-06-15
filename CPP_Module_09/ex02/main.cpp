#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: no elements provided." << std::endl;
        return 1;
    }

    PmergeMe pmerge;
    if (!pmerge.parseArguments(argc, argv)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    pmerge.process();

    return 0;
}
