#ifndef PYRAMIDHOLDER_H
#define PYRAMIDHOLDER_H
#include <ostream>

template <typename T> class pyramidHolder
{
    unsigned long size;
public:
    pyramidHolder(int size);
    T ** dynamicArray = new T[size];
    bool push(T aValue);
    T* pop(int index);
    unsigned long length();
    bool empty();
    T* top();
    friend std::ostream & operator << (std::ostream & os, pyramidHolder<T> &);

};

#endif // PYRAMIDHOLDER_H
