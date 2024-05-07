#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Incorrect number of arguments. Usage: ./PmergeMe <positive int sequence>" << std::endl;
        return (1);
    }
    if (argc == 2)
    {
        std::cout << "Cannot sort. More than one value needed." << std::endl;
        return (1);
    }
    PmergeMe merge;
    merge.sortSequence(argc, argv);

    return (0);
}
