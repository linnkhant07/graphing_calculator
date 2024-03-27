#ifndef MyStack_H
#define MyStack_H

#include "../linked_list_functions/linked_list_functions.h"
#include "../node/node.h"

template <typename T>
class Stack
{
public:
    class Iterator
    {
    public:
        friend class Stack;                // give access to list to access _ptr
        Iterator() { _ptr = NULL; }        // default ctor
        Iterator(node<T> *p) { _ptr = p; } // Point Iterator to where
        T &operator*()
        {
            return _ptr->_item;
        } // dereference operator

        T *operator->()
        {
            return &(_ptr->_item);
        } // member access operator

        bool is_null()
        {
            return _ptr ? false : true;
        } // true if _ptr is NULL

        friend bool operator!=(const Iterator &left, const Iterator &right)
        {
            return left._ptr != right._ptr;

        } // true if left != right

        friend bool operator==(const Iterator &left, const Iterator &right)
        {
            return !(left != right);
        } // true if left == right

        Iterator &operator++()
        {
            _ptr = _ptr->_next;
        } // member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator &it, int unused)
        {
            Iterator hold = it;
            ++it;
            return hold;
        } // friend operator: it++

    private:
        node<T> *_ptr; // pointer being encapsulated
    };

    Stack();
    Stack(const Stack<T> &copyMe);
    ~Stack();
    Stack<T> &operator=(const Stack<T> &RHS);
    T top();
    bool empty();
    void push(T item);
    T pop();

    friend ostream &operator<<(ostream &outs, const Stack &printMe)
    {
        Iterator it;
        for (it = printMe.begin(); it != printMe.end(); it++)
        {
            outs << "[" << *it << "]->";
        }
        outs << "||| size: [" << printMe._size << "]";
        return outs;
    }

    Iterator begin() const; // Iterator to the head node
    Iterator end() const;   // Iterator to NULL
    int size() const { return _size; }

private:
    node<T> *_top;
    int _size;
};

#include "MyStack.cpp"

#endif