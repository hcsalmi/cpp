
#include "Span.hpp"


Span::Span(unsigned int n) : _size(n)
{
     std::cout << "Size constructor called" << std::endl;
}

Span::Span(const Span &src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_size = src._size;
    this->_container = src._container;
}

Span::~Span()
{
    std::cout << "Destructor called" << std::endl;
}

Span &operator=(const Span &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_size = src._size;
        this->_container = src._container;
    }
    return (*this);
}

void addNumber(int n)
{
    if (this->_container.size() == this->_size)
    {
        throw containerFullException();
    }
    else
        this->_container.push_back(n);
}

void addNumbers()
{

}

unsigned int shortestSpan()
{

}

unsigned int longestSpan()
{

}
