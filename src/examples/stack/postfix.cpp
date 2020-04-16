#include "postfix.h"
#include <iostream>

Postfix::Postfix(std::string infix)
{
    this->convert(infix);
}

std::string Postfix::get()
{
    return this->postfixExp;
}

void Postfix::convert(std::string infix)
{
    Stack<char> operatorsStack;
    int length = infix.length();
    bool pushed = false;
    char currentChar = ' ';
    char topOperator = ' ';

    for(int i = 0; i < length; i++)
    {
        currentChar = infix[i];
        if(this->isOperator(currentChar))
        {
            /*
                Push the aritmetic operators in the stack
            */
            pushed = false;
            while(!pushed)
            {
                if(
                    operatorsStack.isEmpty() ||
                    operatorsStack.getTop() == '(' ||
                    this->getOperatorPriority(currentChar) > this->getOperatorPriority(operatorsStack.getTop())
                )
                {
                    operatorsStack.push(currentChar);
                    pushed = true;
                }
                else
                {
                    this->postfixExp += operatorsStack.pop();
                }
            }
        }
        else if(this->isOperand(currentChar))
        {
            /*
                Put the operand in the postfix expression
            */
            this->postfixExp += currentChar;
        }

        /*
            If the operator is a close parenthesis then pop from the stack
        */
        else if(currentChar == ')')
        {
            while(!operatorsStack.isEmpty() && (topOperator = operatorsStack.pop()) != '(')
            {
                this->postfixExp += topOperator;
            }
        }

        /*
            If the operator is a open parenthesis then push in the stack
        */
        else if(currentChar == '(')
        {
            operatorsStack.push(currentChar);
        }
    }

    /*
        Pop all operators from the stack
    */
    while(!operatorsStack.isEmpty())
    {
        this->postfixExp += operatorsStack.pop();

    }
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
            val == '^';
}

bool Postfix::isOperand(char c)
{
    if(
        (c >= '0' && c <= '9') ||
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z')
    )
        return true;
    
    return false;
}
