#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
class Stack : public LinkedList<T>
{
public:
    void push(T value);
    T pop();
    T& top();
    bool isEmpty();
    void print();

};

template <class T>
void Stack<T>::push(T value)
{
    this->append(value);
}

template <class T>
T Stack<T>::pop()
{
    T res = (*this)[this->getSize()-1];
    this->LinkedList<T>::remove(this->getSize()-1);
    return res;
}

template <class T>
void Stack<T>::print()
{
    this->LinkedList<T>::print();
}

template <class T>
T& Stack<T>::top()
{
    return (*this)[this->getSize()-1];
}

template <class T>
bool Stack<T>::isEmpty()
{
    return this->getSize() == 0;
}



#endif // STACK_H
