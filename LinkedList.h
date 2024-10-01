#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;


template <typename T>
class Node
{
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();
    void clear();
    T& operator[](int index);

    void append(T value);
    void remove(int position);
    int getSize();
    void print();
    void sort();
    T get(int index);
    int find(T value);
    void insert(T newData, int position);
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
void LinkedList<T>::clear()
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}


template <typename T>
void LinkedList<T>::append(T value)
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

template <typename T>
void LinkedList<T>::remove(int position)
{
    if (position < 0 || position >= size)
    {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node<T>* current = head;


    for (int i = 0; i < position; i++)
    {
        current = current->next;
    }


    if (current == head)
    {
        head = current->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        else
        {
            tail = nullptr;
        }
    }
    else if (current == tail)
    {
        tail = current->prev;
        tail->next = nullptr;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    size--;
}

template <typename T>
int LinkedList<T>::getSize()
{
        return size;
}

template <typename T>
void LinkedList<T>::print()
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
T& LinkedList<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    Node<T>* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data; // Return reference to data
}

template <typename T>
T LinkedList<T>::get(int index)
{
    T res = 11;
    return (*this)[index];
}

template <typename T>
void quickSort(T* list, int low, int high)
{
    int i = low;
    int j = high;

    int pivot = (*list)[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while ((*list)[i] < pivot)
            i++;
        while ((*list)[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = (*list)[i];
            (*list)[i] = (*list)[j];
            (*list)[j] = temp;
            i++;
            j--;
        }
    }
    // Recursively sort the partitions
    if (j > low)
        quickSort(list, low, j);
    if (i < high)
        quickSort(list, i, high);
}

template <typename T>
void LinkedList<T>::sort()
{
    quickSort(this, 0, size-1   );
}

template <typename T>
int LinkedList<T>::find(T value)
{
    for (int i = 0; i < this->size; ++i)
    {
        if ((*this)[i] == value)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void LinkedList<T>::insert(T newData, int position)
{
    Node<T>* newNode = new Node<T>(newData); // Create a new node
    newNode->data = newData;    // Assign data to the new node
    newNode->next = nullptr;    // Initialize next pointer
    newNode->prev = nullptr;    // Initialize prev pointer

    // If inserting at the head (position 0)
    if (position == 0) {
        newNode->next = head;     // Point new node to current head
        if (head != nullptr) {
            head->prev = newNode; // Update previous head's prev pointer
        }
        head = newNode;           // Update head to be the new node
        return;
    }

    Node<T>* current = head;       // Start from the head
    for (int i = 0; current != nullptr && i < position - 1; i++) {
        current = current->next; // Traverse to the node before the desired position
    }

    if (current == nullptr) {
        cout << "Position out of bounds. Insertion failed." << endl;
        delete newNode;          // Clean up memory if insertion fails
        return;
    }

    // Insert the new node at the desired position
    newNode->next = current->next; // Link new node to the next node
    if (current->next != nullptr) {
        current->next->prev = newNode; // Link next node's prev to new node
    }

    current->next = newNode;        // Link previous node to the new node
    newNode->prev = current;        // Link new node's prev to previous node
}
#endif // LINKEDLIST_H
