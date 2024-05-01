 #include "PmergeMe.hpp"
 
 PmergeMe::PmergeMe()
 {

 }

PmergeMe::PmergeMe(const PmergeMe &src)
{
    //copy attributes (containers)
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        //copy attributes (containers)
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{

}