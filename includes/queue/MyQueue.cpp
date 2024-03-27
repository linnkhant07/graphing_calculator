#ifndef MyQueue_CPP
#define MyQueue_CPP

#include <assert.h>
#include "MyQueue.h"
#include <iostream>

using namespace std;

template <typename T>
Queue<T>::Queue() : _front(nullptr), _rear(nullptr), _size(0)
{
}

template <typename T>
Queue<T>::Queue(const Queue<T> &copyMe) : _front(nullptr), _rear(nullptr), _size(copyMe.size())
{
    _rear = _copy_list(_front, copyMe._front);
}

template <typename T>
Queue<T>::~Queue()
{
    _clear_list(_front);
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &RHS)
{
    _size = RHS.size();
    _clear_list(_front);
    _rear = _copy_list(_front, RHS._front);
    return *this;
}

template <typename T>
bool Queue<T>::empty()
{
    return !_size && !_front;
}

template <typename T>
T Queue<T>::front()
{
    return _front->_item;
}

template <typename T>
T Queue<T>::back()
{
    return _rear->_item;
}

template <typename T>
void Queue<T>::push(T item)
{
    _size++;
    _rear = _insert_after(_front, _rear, item);
}

template <typename T>
T Queue<T>::pop()
{
    assert(!empty());
    _size--;
    return _delete_node(_front, _front);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const
{
    return _front;
} // Iterator to the head node

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    return nullptr;
} // Iterator to NULL

template <typename T>
void Queue<T>::print_pointers()
{
    _print_list(_front);
}

#endif