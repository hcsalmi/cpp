#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <utility>

class PmergeMe
{
    private:
        std::vector<unsigned int>          _vector;
        std::vector<unsigned int>          _vectorChainA;
        std::vector<unsigned int>          _vectorChainB;
        std::vector<std::pair<unsigned int, unsigned int>>   _vectorPaired;

        std::deque<unsigned int>          _deque;
        std::deque<unsigned int>          _dequeChainA;
        std::deque<unsigned int>          _dequeChainB;
        std::deque<std::pair<unsigned int, unsigned int>>  _dequePaired;

        int _oddNumber;

        void    validateAndStore(int argc, char **argv);
        void    check_duplicate();

        void    initialVectorPairing();
        void    sortVectorPairs(std::vector<std::pair<unsigned int, unsigned int>> &pairs, int start, int end);
        void    insertionSortVector();
        void	insertIntoV();

        void    initialDequePairing();
        void    sortDequePairs(std::deque<std::pair<unsigned int, unsigned int>> &pairs, int start, int end);
        void    insertionSortDeque();
        void    insertIntoD();

        void    printVector();
        void    printChainA();
        void    printDeque();
        void    printChainADeque();

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        void    sortSequence(int argc, char **argv);
};


#endif