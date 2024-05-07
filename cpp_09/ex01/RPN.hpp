#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
    private:
        std::stack<int>  _stack;
        
        void    formatCheck(std::string &input);
        void    validateOperatePrint(std::string input);
        void    calculate(char op);

    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        ~RPN();

        void   handleRpn(std::string input);
};

#endif