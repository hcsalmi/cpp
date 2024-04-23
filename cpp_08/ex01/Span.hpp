#ifndef SPAN_HPP
#define SPAN_HPP

# define	RED			"\e[0;31m"
# define	GREEN		"\e[0;32m"
# define	BLUE		"\e[0;34m"
# define	MAG			"\e[0;35m"
# define	CYAN		"\e[0;36m"
# define	COLRESET	"\e[0m"

#include <iostream>


//why does the default constructor not need to be defined anywhere if it's private?

class Span
{
    private:
        std::vector<int>    _container;
        unsigned int        _size;
        Span();

    public:
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();

        Span &operator=(const Span &src);

        void    addNumber();
        void    addNumbers();

        unsigned int    shortestSpan();
        unsigned int    longestSpan();

        class containerFullException : public std::exception {
		    public:
			    virtual const char *what(void) const throw() { return "No room in container"; }
		};

        class noSpanFoundException : public std::exception {
		    public:
			    virtual const char *what(void) const throw() { return "No span found"; }
		};
};

#endif

