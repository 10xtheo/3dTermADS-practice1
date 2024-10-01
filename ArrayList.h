#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using namespace std;

template <typename T>
class ArrayList
{
private:
    T* arr;
    int size;
    int capacity;
    void ensureCapacity();

public:
    ArrayList(int cap = 10);
    ~ArrayList();

    T& operator[](int index);

    void append(T element);
    void add(T element, int index);
    int getSize();
    bool isEmpty();
    void print();
    void remove(int index);
};

template <typename T>
T& ArrayList<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return arr[index];
}


template <typename T>
void ArrayList<T>::ensureCapacity()
{
    capacity *= 2;
    T* temp = new T[capacity];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

template <typename T>
ArrayList<T>::ArrayList(int cap)
{
    capacity = cap;
    size = 0;
    arr = new T[capacity];
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] arr;
}

template <typename T>
void ArrayList<T>::append(T element)
{
    if (size == capacity)
    {
        ensureCapacity();
    }
    arr[size++] = element;
}

template <typename T>
void ArrayList<T>::add(T element, int index)
{
    if (size == capacity)
    {
        ensureCapacity();
    }
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    size++;
}

template <typename T>
int ArrayList<T>::getSize()
{
    return size;
}

template <typename T>
bool ArrayList<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
void ArrayList<T>::print()
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
template <typename T>
void ArrayList<T>::remove(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    --size;
}

#endif // ARRAYLIST_H
