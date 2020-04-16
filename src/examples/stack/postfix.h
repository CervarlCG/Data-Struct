#include "../../../libs/datastruct/Stack.h"
#include <string>
class Postfix
{
    private:
        std::string postfixExp;
        unsigned int getOperatorPriority(char op);
        bool isOperator(char val);
        void convert(std::string in);
        bool isOperand(char c);
    public:
        /*
        *   Postfix constructor
        *   @param in A string whith the expression on infix notation
        * */
        Postfix(std::string in);

        /*
        *   Return the postfix expression
        * 
        * */
        std::string get();
};