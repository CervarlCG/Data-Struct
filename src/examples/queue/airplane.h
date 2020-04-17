#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <string>
#include "../../../libs/datastruct/Queue.h"


class Airplane
{
    private:
        Queue<std::string> flights;
    public:
        void addFlight(std::string name);
        void start();

};

#endif