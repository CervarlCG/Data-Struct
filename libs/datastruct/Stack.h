#include "Node.h"
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
    private:
        Node<T>* top;
        unsigned int size;
    public:
        Stack();
        unsigned int getSize();
        bool isEmpty();
        void push(T value);
        T pop();
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