#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || (argc == 2 && argv[1][0] == '\0'))
    {
        std::cout << "Invalid arguments. Usage: ./RPN <rpn math expression in quotes>" << std::endl;
        return (1);
    }
    std::string emptyTest(argv[1]);
    if (emptyTest.find_first_not_of(" \t") == std::string::npos)
    {
        std::cout << "Invalid arguments. Usage: ./RPN <rpn math expression in quotes>" << std::endl;
        return (1);
    }
    RPN rpn;
    rpn.handleRpn(argv[1]);

    return (0);
}
