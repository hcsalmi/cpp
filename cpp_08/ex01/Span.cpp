
#include "Span.hpp"
#include <iostream>


Span::Span(unsigned int n) : _size(n)
{
     std::cout << "Size constructor called for size " << n << std::endl;
}

Span::Span(const Span &src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_size = src._size;
    this->_container = src._container;
}

Span &Span::operator=(const Span &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_size = src._size;
        this->_container = src._container;
    }
    return (*this);
}

Span::~Span()
{

}

void Span::addNumber(int n)
{
    if (this->_container.size() >= this->_size)
    {
        throw containerFullException();
    }
    else
    {
        this->_container.push_back(n);
    }
}

void Span::addNumbers(unsigned int amount)
{
    for (unsigned int i = 0; i < amount; i++)
    {
        if (this->_container.size() == this->_size)
        {
            throw containerFullException();
        }
        else
        {
            this->_container.push_back(i);  
        }
    }
}

unsigned int Span::shortestSpan()
{
    if (this->_container.size() < 2)
        throw noSpanFoundException();
    
    std::vector<int> sorted = this->_container;
    std::sort(sorted.begin(), sorted.end());

    unsigned int shortest = std::numeric_limits<unsigned int>::max();
    for (unsigned int i = 0; i != sorted.size() - 1; ++i)
    {
        if (std::abs(sorted[i] - sorted[i + 1]) < shortest)
        {
            shortest = std::abs(sorted[i] - sorted[i + 1]);
        }
    }
    return (shortest);
}

unsigned int Span::longestSpan()
{
    if (this->_container.size() < 2)
        throw noSpanFoundException();

    std::vector<int> sorted = this->_container;
    std::sort(sorted.begin(), sorted.end());

    return (std::abs(sorted.back() - sorted.front()));
}
