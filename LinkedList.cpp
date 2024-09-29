#include "LinkedList.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

~LinkedList()
{

}


void append(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    if (tail == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void remove(int position)
{

}

int getSize() const
{
    return size;
}

void printList() const {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
