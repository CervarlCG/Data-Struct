#include "airplane.h"
#include <iostream>
#include <thread>
#include <chrono>

void Airplane::addFlight(std::string name)
{
    this->flights.push(name);
}

void Airplane::start()
{
    while(!this->flights.isEmpty())
    {
        std::cout << "The flight \"" << this->flights.pop() << "\" is ready" << std::endl;
        std::cout << "The next flight will be ready in 5 seconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
    std::cout << "The flights queue is empty" << std::endl;
}