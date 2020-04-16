#include "delimitators.h"

Delimitator::Delimitator(char openLimitator, char closeLimitator)
{
    this->open = openLimitator;
    this->close = closeLimitator;
}

bool Delimitator::check(std::string exp)
{
    Stack<char> limitatorStack;
    int length = exp.length();

    for(int i = 0; i < length; i++)
    {
        if(exp[i] == this->open)
            limitatorStack.push(this->open);
        else if(exp[i] == this->close)
            limitatorStack.pop();
    }

    return limitatorStack.isEmpty();
}