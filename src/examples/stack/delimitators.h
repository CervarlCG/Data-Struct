#ifndef LIMITATORS_H
#define LIMITATORS_H
#include "../../../libs/datastruct/Stack.h"
#include <string>

class Delimitator
{
    private:
        char open;
        char close;
    
    public:
        Delimitator(char openLimitator, char closeLimitator);
        bool check(std::string exp);
};


#endif