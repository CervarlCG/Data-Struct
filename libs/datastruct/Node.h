#ifndef NODE_H
#define NODE_H

    template <class T>
    class Node
    {
        private:
            T value;
            Node *next;
        public:
            Node(T value);
            T getValue();
            void setValue(T value);
            Node *getNext();
            void setNext(Node *next);
    };

    template <class T>
    Node<T>::Node(T value)
    {
        this->setValue(value);
        this->next = nullptr;
    }

    template <class T>
    T Node<T>::getValue()
    {
        return this->value;
    }

    template <class T>
    void Node<T>::setValue(T value)
    {
        this->value = value;
    }

    template <class T>
    Node<T> * Node<T>::getNext()
    {
        return this->next;
    }

    template <class T>
    void Node<T>::setNext(Node *next)
    {
        this->next = next;
    }
#endif