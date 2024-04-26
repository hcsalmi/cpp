#include "BitcoinExchange.hpp"
#include <iostream>


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: please provide input file." << std::endl;
        return (0);
    }
    BitcoinExchange btc;
    btc.handleExchange(argv[1]);

    return (0);
}
