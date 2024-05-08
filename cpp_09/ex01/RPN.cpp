#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &src)
{
    this->_stack = src._stack;
}

RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
    {
        this->_stack = src._stack;
    }
    return (*this);
}

RPN::~RPN()
{

}

void RPN::calculate(char op)
{
    int second = _stack.top();
	_stack.pop();
	int first = _stack.top();
	_stack.pop();

    switch(op)
    {
        case '+' :
        {
            int res = first + second;
            _stack.push(res);
            break ;
        }
        case '-' :
        {
            int res = first - second;
            _stack.push(res);
            break ;
        }
        case '*' :
        {
            int res = first * second;
            _stack.push(res);
            break ;
        }
        case '/' :
        {
            if (second == 0)
                throw std::runtime_error("Division by zero");
            int res = first / second;
            _stack.push(res);
            break ;
        }
    }
}

void    RPN::validateOperatePrint(std::string input)
{
    int count = 0;
    for (unsigned long i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]))
            count++;
    }
    if (count <= 1)
        throw std::runtime_error("Too few numbers");
    bool needSpace = false;
    for (unsigned int i = 0; i < input.size(); i++)
    {
        char c = input[i];
        if (isdigit(c) && needSpace == false)
        {
            std::string nbStr = std::to_string(c - '0');
            this->_stack.push(stoi(nbStr));
            needSpace = true;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (this->_stack.size() < 2)
                throw std::runtime_error("Not enough values to calculate with");
            calculate(c);
            if (this->_stack.size() > 2)
                continue ;
        }
        else if (isspace(c))
        {
            needSpace = false;
            continue ;
        }
        else
            throw std::runtime_error("Wrong format or invalid character");
    }
    if (this->_stack.size() == 1)
        std::cout << "Result: " << this->_stack.top() << std::endl;
    else
        throw std::runtime_error("Not enough operators");
}

void    RPN::handleRpn(std::string input)
{
    try
	{
        validateOperatePrint(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
