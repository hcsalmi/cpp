#include "MutantStack.hpp"
#include <iostream>
#include <list>


int main()
{
    std::cout << std::endl;
    std::cout << "\e[0;32m" << "* * * * * Subject test modified * * * * *" << "\e[0m" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        std::cout << "Pushed: 5" << std::endl;
        mstack.push(17);
        std::cout << "Pushed: 17" << std::endl;

        std::cout << "Current top element: " << mstack.top() << std::endl;
        std::cout << "Removing top element" << std::endl;
        mstack.pop();
        std::cout << std::endl;
        std::cout << "Stack size: " << mstack.size() << std::endl;

        std::cout << std::endl;
        mstack.push(3);
        std::cout << "Pushed: 3" << std::endl;
        mstack.push(4);
        std::cout << "Pushed: 4" << std::endl;
        mstack.push(737);
        std::cout << "Pushed: 737" << std::endl;
        mstack.push(0);
        std::cout << "Pushed: 0" << std::endl;
        std::cout << std::endl;

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator itend = mstack.end();

        std::cout << "\e[0;36m" << "Iterating through the whole stack" << "\e[0m" << std::endl;
        while (it != itend)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << std::endl;
        std::cout << "\e[0;36m" << "Moving iterators by one position and reiterating" << "\e[0m" << std::endl;
        MutantStack<int>::iterator it2 = mstack.begin();
        MutantStack<int>::iterator itend2 = mstack.end();
        it2++;
        itend2--;
        while (it2 != itend2)
        {
            std::cout << *it2 << std::endl;
            ++it2;
        }
    }

    std::cout << std::endl;
    std::cout << "\e[0;32m" << "* * * * * Testing with list * * * * *" << "\e[0m" << std::endl;
    {
        std::list<int> mstack;

        mstack.push_back(5);
        std::cout << "Pushed: 5" << std::endl;
        mstack.push_back(17);
        std::cout << "Pushed: 17" << std::endl;

        std::cout << "Current top element: " << mstack.back() << std::endl;
        std::cout << "Removing top element" << std::endl;
        mstack.pop_back();
        std::cout << std::endl;
        std::cout << "Stack size: " << mstack.size() << std::endl;

        std::cout << std::endl;
        mstack.push_back(3);
        std::cout << "Pushed: 3" << std::endl;
        mstack.push_back(4);
        std::cout << "Pushed: 4" << std::endl;
        mstack.push_back(737);
        std::cout << "Pushed: 737" << std::endl;
        mstack.push_back(0);
        std::cout << "Pushed: 0" << std::endl;
        std::cout << std::endl;

        std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator itend = mstack.end();

        std::cout << "\e[0;36m" << "Iterating through the whole stack" << "\e[0m" << std::endl;
        while (it != itend)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << std::endl;
        std::cout << "\e[0;36m" << "Moving iterators by one position and reiterating" << "\e[0m" << std::endl;
        std::list<int>::iterator it2 = mstack.begin();
		std::list<int>::iterator itend2 = mstack.end();
        it2++;
        itend2--;
        while (it2 != itend2)
        {
            std::cout << *it2 << std::endl;
            ++it2;
        }
    }
    std::cout << std::endl;
    return (0);
}
