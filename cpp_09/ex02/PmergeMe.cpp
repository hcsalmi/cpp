 #include "PmergeMe.hpp"
 
 PmergeMe::PmergeMe()
 {
    this->_oddNumber = -1;
 }

PmergeMe::PmergeMe(const PmergeMe &src)
{
    this->_vector = src._vector;
    this->_vectorChainA = src._vectorChainA;
    this->_vectorChainB = src._vectorChainB;
    this->_vectorPaired = src._vectorPaired;
    this->_deque = src._deque;
    this->_dequeChainA = src._dequeChainA;
    this->_dequeChainB = src._dequeChainB;
    this->_dequePaired = src._dequePaired;
    this->_oddNumber = src._oddNumber;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_vector = src._vector;
        this->_vectorChainA = src._vectorChainA;
        this->_vectorChainB = src._vectorChainB;
        this->_vectorPaired = src._vectorPaired;
        this->_deque = src._deque;
        this->_dequeChainA = src._dequeChainA;
        this->_dequeChainB = src._dequeChainB;
        this->_dequePaired = src._dequePaired;
        this->_oddNumber = src._oddNumber;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{

}

/*-------------------------------   Print   ----------------------------------*/

void    PmergeMe::printVector()
{
    std::vector<unsigned int>::iterator it;

    for (it = this->_vector.begin(); it != this->_vector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printChainA()
{
    std::vector<unsigned int>::iterator it;

    for (it = this->_vectorChainA.begin(); it != this->_vectorChainA.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printDeque()
{
    std::deque<unsigned int>::iterator it;

    for (it = this->_deque.begin(); it != this->_deque.end(); ++it)
    {
       std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printChainADeque()
{
    std::deque<unsigned int>::iterator it;

    for (it = this->_dequeChainA.begin(); it != this->_dequeChainA.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/*----------------------------   Validation   --------------------------------*/

void    PmergeMe::check_duplicate()
{
    std::vector<unsigned int>::iterator it;
    std::vector<unsigned int>::iterator it2;
    int found = 0;

    for (it = this->_vector.begin(); it != this->_vector.end(); ++it)
    {
        unsigned int value = *it;
        for (it2 = this->_vector.begin(); it2 != this->_vector.end(); ++it2)
        {
            if (*it2 == value)
                found++;
        }
        if (found > 1)
            throw std::runtime_error("Duplicate value");
        found = 0;
    }
}

void    PmergeMe::validateAndStore(int argc, char **argv)
{   
    for (int i = 1; i < argc; i++)
    {
        int value = std::stoi(argv[i]);
        if (value < 0)
            throw std::runtime_error("Invalid input. Only positive integers allowed.");
        else
        {
            this->_vector.push_back(value);
            this->_deque.push_back(value);
        }
    }
    check_duplicate();
}

/*-------------------------------   Vector  ----------------------------------*/

void   PmergeMe::initialVectorPairing()
{
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (this->_vector[i] < this->_vector[i + 1])
            this->_vectorPaired.push_back(std::make_pair(this->_vector[i], this->_vector[i + 1]));
        else
            this->_vectorPaired.push_back(std::make_pair(this->_vector[i + 1], this->_vector[i]));
    }

    if (this->_vector.size() % 2 == 1)
    {
        this->_oddNumber = this->_vector.back();
    }
}

void    PmergeMe::sortVectorPairs(std::vector<std::pair<unsigned int, unsigned int>> &pairs, int start, int end)
{
    if (start == end)
    {
        return ;
    }
    int mid = start + (end - start) / 2;
    sortVectorPairs(pairs, start, mid);      // recursively sort left half
    sortVectorPairs(pairs, mid + 1, end);    // recursively sort right half

    // merge sorted halves
    std::vector<std::pair<int, int>> temp(end - start + 1);
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (pairs[i].first <= pairs[j].first)
        {
            temp[k++] = pairs[i++];
        }
        else
        {
            temp[k++] = pairs[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = pairs[i++];
    }
    while (j <= end)
    {
        temp[k++] = pairs[j++];
    }
    for (int m = 0; m < k; m++)
    {
        pairs[start + m] = temp[m];
    }
}

void    PmergeMe::insertionSortVector()
{
    std::vector<std::pair<unsigned int, unsigned int>>::iterator it;

    for (it = this->_vectorPaired.begin(); it != this->_vectorPaired.end(); it++)
    {
        _vectorChainA.push_back(it->first);
        _vectorChainB.push_back(it->second);
    }
    if (this->_oddNumber != -1)
        _vectorChainB.push_back(this->_oddNumber);
    insertIntoV();
}

void	PmergeMe::insertIntoV()
{
    unsigned int toInsert;

    for (unsigned int i = 0; i < this->_vectorChainB.size(); i++)
    {
        toInsert = this->_vectorChainB[i];
        unsigned int size = this->_vectorChainA.size();

        if (toInsert <= this->_vectorChainA[0])
        {
            this->_vectorChainA.insert(this->_vectorChainA.begin(), toInsert);
            continue ;
        }
        if (toInsert >= this->_vectorChainA[this->_vectorChainA.size() - 1])
        {
            this->_vectorChainA.insert(this->_vectorChainA.end(), toInsert);
            continue ;
        }
        for (int j = size - 2; j >= 0; j--)
        {
            if (this->_vectorChainA[j] <= toInsert && this->_vectorChainA[j + 1] > toInsert)
            {
                this->_vectorChainA.insert(this->_vectorChainA.begin() + j + 1, toInsert);
                break;
            }
        }
    }
}

/*-------------------------------   Deque   ----------------------------------*/

void PmergeMe::initialDequePairing()
{
    for (size_t i = 0; i + 1 < _deque.size(); i += 2) {
        if (_deque[i] < _deque[i + 1])
            _dequePaired.push_back(std::make_pair(_deque[i], _deque[i + 1]));
        else
            _dequePaired.push_back(std::make_pair(_deque[i + 1], _deque[i]));
    }

    if (_deque.size() % 2 == 1) {
        _oddNumber = _deque.back();
    }
}

void PmergeMe::sortDequePairs(std::deque<std::pair<unsigned int, unsigned int>> &pairs, int start, int end)
{
    if (start == end) {
        return;
    }
    int mid = start + (end - start) / 2;
    sortDequePairs(pairs, start, mid);      // Recursively sort left half
    sortDequePairs(pairs, mid + 1, end);    // Recursively sort right half

    // Merge sorted halves
    std::deque<std::pair<int, int>> temp;
    temp.resize(end - start + 1);
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (pairs[i].first <= pairs[j].first) {
            temp[k++] = pairs[i++];
        } else {
            temp[k++] = pairs[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = pairs[i++];
    }
    while (j <= end) {
        temp[k++] = pairs[j++];
    }
    for (int m = 0; m < k; m++) {
        pairs[start + m] = temp[m];
    }
}

void PmergeMe::insertionSortDeque()
{
    std::deque<std::pair<unsigned int, unsigned int>>::iterator it;

    for (it = _dequePaired.begin(); it != _dequePaired.end(); it++) {
        _dequeChainA.push_back(it->first);
        _dequeChainB.push_back(it->second);
    }
    if (_oddNumber != -1)
        _dequeChainB.push_back(_oddNumber);
    insertIntoD();
}

void PmergeMe::insertIntoD()
{
    unsigned int toInsert;

    for (unsigned int i = 0; i < _dequeChainB.size(); i++) {
        toInsert = _dequeChainB[i];
        unsigned int size = _dequeChainA.size();

        if (toInsert <= _dequeChainA[0]) {
            _dequeChainA.push_front(toInsert);
            continue;
        }
        if (toInsert >= _dequeChainA.back()) {
            _dequeChainA.push_back(toInsert);
            continue;
        }
        for (int j = size - 2; j >= 0; j--) {
            if (_dequeChainA[j] <= toInsert && _dequeChainA[j + 1] > toInsert) {
                _dequeChainA.insert(_dequeChainA.begin() + j + 1, toInsert);
                break;
            }
        }
    }
}

/*-------------------------------    Hub    ----------------------------------*/

void    PmergeMe::sortSequence(int argc, char **argv)
{
    try
	{
        std::clock_t startVec, startDeq, endVec, endDeq; 
	    double	time;

        validateAndStore(argc, argv);
        std::cout << "Before: ";
        printVector();
//        std::cout << "Before (deque): ";
//        printDeque();

        startVec = std::clock();
        initialVectorPairing();
        sortVectorPairs(this->_vectorPaired, 0, this->_vectorPaired.size() - 1);
        insertionSortVector();
        endVec = std::clock();

        startDeq = std::clock();
        initialDequePairing();
        sortDequePairs(this->_dequePaired, 0, this->_dequePaired.size() - 1);
        insertionSortDeque();
        endDeq = std::clock();

        std::cout << "After: ";
        printChainA();
//        std::cout << "After (deque): ";
//        printChainADeque();

        time = double(endVec - startVec) / CLOCKS_PER_SEC;
	    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << (time * 1000) << " ms" << std::endl;
	    time = double(endDeq - startDeq) / CLOCKS_PER_SEC;
	    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << (time * 1000) << " ms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
