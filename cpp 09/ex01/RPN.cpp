#include <iostream>
#include <stack>
#include "RPN.hpp"

void RPN_calc(const std::string& eq)
{
    std::stack<int> stack;
    for (size_t i = 0; i < eq.length(); i++)
    {
        if (eq[i] == ' ')
            continue;
        else if (eq[i] >= '0' && eq[i] <= '9')
        {
            stack.push(eq[i] - '0');
        }
        else if (eq[i] == '+' || eq[i] == '-' || eq[i] == '*' || eq[i] == '/')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return ;
            }

            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (eq[i] == '+')
                stack.push(a + b);
            else if (eq[i] == '-')
                stack.push(a - b);
            else if (eq[i] == '*')
                stack.push(a * b);
            else if (eq[i] == '/')
            {
                if (b == 0)
                {
                    std::cout << "Error" << std::endl;
                    return ;
                }
                stack.push(a / b);
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            return ;
        }
    }

    if (stack.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return ;
    }

    std::cout << "Result: " << stack.top() << std::endl;
}
