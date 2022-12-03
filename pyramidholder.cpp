#include "pyramidholder.h"
template<typename T>
pyramidHolder<T>::pyramidHolder(int size)
{
    this->size = size;
    this->empty();
}

template<typename T>
bool pyramidHolder<T>::push(T aValue)
{
    if (aValue = nullptr) return false;
    for (unsigned long iteratorI = 0; iteratorI < size; iteratorI++)
    {
        if (this->dynamicArray[iteratorI] == nullptr)
        {
            this->dynamicArray[iteratorI] = new T(*aValue);
            return true;
        }
    }
    return false;
}
template<typename T>
T* pyramidHolder<T>::pop(int index)
{
    if (index < size) return this->dynamicArray[index];
    return nullptr;
}

template<typename T>
unsigned long pyramidHolder<T>::length()
{
    for (unsigned long iteratorI = 0; iteratorI < size; iteratorI++)
    {
        if (this->dynamicArray[iteratorI] == nullptr)
        {
            return ++iteratorI;
        }
    }
    return 0;
}

template<typename T>
bool pyramidHolder<T>::empty()
{
    for (unsigned long iteratorI = 0; iteratorI < size; iteratorI++)
    {

        if(this->dynamicArray[iteratorI] == nullptr)continue;
        delete this->dynamicArray[iteratorI];
    }
    return true;
}

template<typename T>
T* pyramidHolder<T>::top()
{
    return this->dynamicArray[0];
}
/*
template<typename T>
std::ostream& pyramidHolder<T>::operator << (std::ostream & os, pyramidHolder<T> & cur)
{
    for (unsigned long iteratorI = 0; iteratorI < size; iteratorI++)
    {
        if (this->dynamicArray[iteratorI] == nullptr) return os;
        os << dynamicArray[iteratorI];
    }
    return os;
}*/
