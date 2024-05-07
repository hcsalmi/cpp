#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: incorrect number of arguments. Usage: ./btc <filename>" << std::endl;
        return (1);
    }
    BitcoinExchange btc;
    btc.handleExchange(argv[1]);

    return (0);
}
