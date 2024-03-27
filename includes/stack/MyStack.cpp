#ifndef MyStack_CPP
#define MyStack_CPP

#include "MyStack.h"
#include <iostream>

using namespace std;

template <typename T>
Stack<T>::Stack() : _size(0), _top(nullptr)
{
}
template <typename T>
Stack<T>::Stack(const Stack<T> &copyMe) : _size(copyMe.size())
{
    _top = _copy_list(copyMe._top);
}

template <typename T>
Stack<T>::~Stack()
{
    _clear_list(_top);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &RHS)
{
    _size = RHS._size;
    _clear_list(_top);
    _top = _copy_list(RHS._top);
    return *this;
}

template <typename T>
T Stack<T>::top()
{
    return _top->_item;
}

template <typename T>
bool Stack<T>::empty()
{
    return _size == 0 && _top == nullptr;
}

template <typename T>
void Stack<T>::push(T item)
{
    _insert_head(_top, item);
    _size++;
}

template <typename T>
T Stack<T>::pop()
{
    assert(!empty());
    _size--;
    return _delete_node(_top, _top);
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const
{
    return _top;
} // Iterator to the head node

template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const
{
    return nullptr;
} // Iterator to NULL

#endif