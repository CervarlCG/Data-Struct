#include "Node.h"
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

/*
*   Data struct STACK
*/
template <class T>
class Stack
{
    private:
        Node<T>* top;
        unsigned int size;
    public:
        /*
        * Constructor
        */
        Stack();
        /*
        *   Get the size of the stack
        *   @return the stack size
        */
        unsigned int getSize();
        /*
        *   Check if the stack is empty
        *   @return true if the stack is empty
        */
        bool isEmpty();
        /*
        *   Push a element in the stack
        * @param value the value to storage
        */
        void push(T value);
        /*
        *   Revome the top element from the stack
        *   @return the element removed
        */
        T pop();
        /*
        *   Retrieve the top element without remove it from top
        *   @return The top element 
        */
        T getTop();
};

template <class T>
Stack<T>::Stack()
{
    this->size = 0;
    this->top = nullptr;
}

template <class T>
unsigned int Stack<T>::getSize()
{
    return this->size;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return this->size == 0;
}

template <class T>
void Stack<T>::push(T value)
{
    void *mem = malloc(sizeof(Node<T>));
    if(mem)
    {
        Node<T> *nodo = new(mem) Node<T>(value);  
        if(!this->isEmpty())
            nodo->setNext(this->top);
        this->top = nodo;
        this->size++;
    }
}

template <class T>
T Stack<T>::pop()
{
    T value = T();
    Node<T> *tmp = this->top;
    
    if(!this->isEmpty())
    {
        value = this->top->getValue();
        this->top = this->top->getNext();
        this->size--;
    }
    
    free(tmp);
    return value;
}

template <class T>
T Stack<T>::getTop()
{
    T value = T();
    if(!this->isEmpty())
    {
        value = this->top->getValue();
    }
    return value;
}


#endif