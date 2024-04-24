
#include "Span.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "* * * * * Subject test * * * * *" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << std::endl;

        std::cout << "\e[0;35m" << "shortest span: " << sp.shortestSpan() << "\e[0m" << std::endl;
        std::cout << "\e[0;36m" << "longest span: " << sp.longestSpan() << "\e[0m" << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "* * * * * Basic test * * * * *" << std::endl;
        Span mySpan = Span(3);
		try
        {
            mySpan.addNumber(500);
		    mySpan.addNumber(20);
		    mySpan.addNumber(-1000);
            mySpan.addNumber(8);
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
        }
        std::cout << std::endl;
		std::cout << "\e[0;35m" << "shortest span: " << mySpan.shortestSpan() << "\e[0m" << std::endl;
        std::cout << "\e[0;36m" << "longest span: " << mySpan.longestSpan() << "\e[0m" << std::endl;
    }
    
    {
        std::cout << std::endl;
        std::cout << "* * * * * Large span test * * * * *" << std::endl;
        try 
	    {
	    	Span s(10000);
	    	s.addNumbers(10000);
	    	std::cout << "\e[0;35m" << "shortest span: " << s.shortestSpan() << "\e[0m" << std::endl;
	    	std::cout << "\e[0;36m" << "longest span: " << s.longestSpan() << "\e[0m" << std::endl;
    	} 
	    catch (std::exception& e) 
	    {
	    	std::cerr << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	    }
    }

    {
        std::cout << std::endl;
        std::cout << "* * * * * No span test * * * * *" << std::endl;
        Span mySpan = Span(0);
		try
		{
            std::cout << "Trying to add a number ..." << std::endl;
			mySpan.addNumbers(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		}
        std::cout << std::endl;
		try
		{
			std::cout << "\e[0;36m" << "longest span " << mySpan.longestSpan() << "\e[0m" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		}
        std::cout << std::endl;

        Span mySpan2 = Span(1);
        try
		{
            mySpan2.addNumber(8);
			std::cout << "\e[0;35m" << "shortest span " << mySpan2.shortestSpan() << "\e[0m" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		}
        std::cout << std::endl;
    }
    return (0);
}
