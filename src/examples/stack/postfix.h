#include "../../../libs/datastruct/Stack.h"
#include <string>
class Postfix
{
    private:
        Stack<char> s;
        std::string in;
        unsigned int getOperatorPriority(char op);
        bool isOperator(char val);
    public:
        /*
        *   Postfix constructor
        *   @param in A string whith the expression on infix notation
        * */
        Postfix(std::string in);
        /*
        *   Get the expression on postfix notation
        *   @return a string with the expression on postfix notation
        * */
        std::string convert();
};