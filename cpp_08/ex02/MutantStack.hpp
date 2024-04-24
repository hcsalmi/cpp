#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        typedef typename std::deque<T>::iterator iterator;

        MutantStack() {};
        MutantStack(const MutantStack &src) : std::stack<T>(src) {};
        MutantStack &operator=(const MutantStack& src)
        {
            std::stack<T, std::deque<T>>::operator=(src);
            return *this;
        };

        ~MutantStack() {};

        iterator begin()
	    {
    	    return (this->c.begin());
	    }

	    iterator end()
	    {
     	    return (this->c.end());
	    }
};

#endif
