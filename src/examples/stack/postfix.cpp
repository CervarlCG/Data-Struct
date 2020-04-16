#include "postfix.h"
#include <iostream>

Postfix::Postfix(std::string in)
{
    this->in = in;
}

std::string Postfix::convert()
{
    std::string postfix = "";
    int length = this->in.length();
    char current = ' ';
    char op;
    bool pushed;

    for(int i = 0; i < length; i++)
    {
        current = this->in[i];
        pushed = false;
        if(this->isOperator(current))
        {
            if(current == ')')
            {
                while(!this->s.isEmpty() && (op = this->s.pop()) != '(')
                {
                    postfix += op;
                }
            }
            else if(current == '(')
            {
                this->s.push(current);
            }
            else
            {
                while(!pushed)
                {
                    if(
                        this->s.isEmpty() ||
                        this->getOperatorPriority(current) > this->getOperatorPriority(this->s.getTop())
                    )
                    {
                        this->s.push(current);
                        pushed = true;
                    }
                    else
                    {
                        postfix += this->s.pop();
                    }
                }
            }
        }
        else
        {
            postfix += current;
        }
    }

    while(!this->s.isEmpty())
    {
        postfix += this->s.pop();

    }

    return postfix;
}

unsigned int Postfix::getOperatorPriority(char op)
{
    unsigned int priority = 100;
    switch (op)
    {
    case '^':
        priority = 3;
        break;
    case '*':
        priority = 2;
        break;
    case '/':
        priority = 2;
        break;
    case '+':
        priority = 1;
        break;
    case '-':
        priority = 1;
        break;
    case '(':
        priority = 0;
        break;
    default:
        break;
    }

    return priority;
}

bool Postfix::isOperator(char val)
{
    return  val == '+' || 
            val == '-' || 
            val == '*' || 
            val == '/' || 
            val == '^' ||
            val == '(' || 
            val == ')';
}