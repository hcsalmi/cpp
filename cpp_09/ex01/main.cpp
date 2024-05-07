#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Incorrect number of arguments. Usage: ./RPN <rpn math expression in quotes>" << std::endl;
        return (1);
    }
    RPN rpn;
    rpn.handleRpn(argv[1]);

    return (0);
}

/*
    8 9 * 9 - 9 - 9 - 4 - 1 +
	Result: 42
	
    9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -
    Result: 42
	
	1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / 
	Result: 15

    //./RPN "777+" cases with spaces
*/