#include "easyfind.hpp"

int main(void)
{
    {
        std::cout << std::endl;
        std::cout << "* * * * * Test with std::vector<int> * * * * *" << std::endl;
        std::cout << std::endl;

        std::vector<int> myVector {0,1,2,4,5};
        try
        {
            std::cout << "Looking for 2 ..." << std::endl;
            std::vector<int>::iterator it = easyfind(myVector, 2);
            int index = std::distance(myVector.begin(), it);
            std::cout << "\e[0;36m" << "Found at index: " << index << "\e[0m" << std::endl;
            std::cout << std::endl;

            std::cout << "Looking for 80 ..." << std::endl;
            std::vector<int>::iterator it2 = easyfind(myVector, 80);
            int index2 = std::distance(myVector.begin(), it2);
            std::cout << "\e[0;36m" << "Found at index: " << index2 << "\e[0m" << std::endl;
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* * * * * Test with std::list<char> * * * * *" << std::endl;
        std::cout << std::endl;

        std::list<char> myList;
		myList.push_back('a');
		myList.push_back('b');
		myList.push_back('c');
		myList.push_back('d');
		myList.push_back('e');
        try
        {

            std::cout << "Looking for d ..." << std::endl;
            std::list<char>::iterator it = easyfind(myList, 'd');
            int index = std::distance(myList.begin(), it);
            std::cout << "\e[0;36m" << "Found at index: " << index << "\e[0m" << std::endl;
            std::cout << std::endl;

            std::cout << "Looking for f ..." << std::endl;
            std::list<char>::iterator it2 = easyfind(myList, 'f');
            int index2 = std::distance(myList.begin(), it2);
            std::cout << "\e[0;36m" << "Found at index: " << index2 << "\e[0m" << std::endl;
            std::cout << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return (0);
}
