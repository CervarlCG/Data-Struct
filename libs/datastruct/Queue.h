#include "Node.h"
#include <stdlib.h>


#ifndef QUEUE_H
#define QUEUE_H


template <class T>
class Queue
{
    private:
        Node<T> *first;
        Node<T> *last;
        unsigned int size;
    public:
        Queue();
        unsigned int getSize();
        bool isEmpty();
        void push(T value);
        T pop();
        T peek();
};

template <class T>
Queue<T>::Queue()
{
    this->first = nullptr;
    this->last = nullptr;
    this->size = 0;
}

template <class T>
unsigned int Queue<T>::getSize()
{
    return this->size;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return this->size == 0;
}

template <class T>
void Queue<T>::push(T value)
{
    void *mem = malloc(sizeof(Node<T>));
    if(mem)
    {
        Node<T> *nodo = new(mem) Node<T>(value);  
        if(!this->isEmpty())
            this->last->setNext(nodo);
        else
            this->first = nodo;
        this->last = nodo;
        this->size++;
    }
}

template <class T>
T Queue<T>::pop()
{
    T value = T();
    Node<T> *tmp = this->first;
    
    if(!this->isEmpty())
    {
        value = this->first->getValue();
        this->first = this->first->getNext();
        this->size--;
    }
    
    free(tmp);
    return value;
}

template <class T>
T Queue<T>::peek()
{
    T value = T();
    Node<T> *tmp = this->first;
    
    if(!this->isEmpty())
    {
        value = this->first->getValue();
    }

    return value;
}
#endif