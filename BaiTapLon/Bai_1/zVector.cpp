#include <iostream>
#include "iterator.cpp"
#include <initializer_list>

using namespace std;

#ifndef __vector__cpp__
#define __vector__cpp__

template <class T>
class zVector
{
private:
    size_t cap;
    size_t numOfElement;
    size_t maxHold = (ULLONG_MAX >> 1) / sizeof(T);
    T *array = nullptr;

    void extend(const size_t &newSize)
    {
        if (newSize > maxHold)
            __throw_bad_alloc;
        T *newArray = new T[newSize];
        for (int i = 0; i < numOfElement; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        cap = newSize;
    }

public:
    typedef zVector_iterator<T> iterator;
    typedef zVector_reverse_iterator<T> reverse_iterator;

    zVector() : numOfElement{0}, cap(1), array(new T[1]) {}

    zVector(const size_t &numOfElement, const T &x = 0)
    {
        this->numOfElement = cap = numOfElement;
        array = new T[numOfElement];
        for (size_t i = 0; i < numOfElement; i++)
            array[i] = x;
    }

    zVector(const zVector<T> &_vector)
    {
        if (array)
            delete[] array;
        cap = _vector.cap;
        numOfElement = _vector.numOfElement;
        array = new T[cap];
        for (size_t i = 0; i < cap; i++)
            array[i] = _vector.array[i];
    }

    zVector(initializer_list<T> _vector)
    {
        if (array)
            delete[] array;
        array = new T[_vector.size()];
        numOfElement = cap = _vector.size();
        for (auto it = _vector.begin(); it != _vector.end(); it++)
            array[it - _vector.begin()] = *it;
    }

    void operator=(initializer_list<T> _vector)
    {
        if (array)
            delete[] array;
        array = new T[_vector.size()];
        numOfElement = cap = _vector.size();
        for (auto it = _vector.begin(); it != _vector.end(); it++)
            array[it - _vector.begin()] = *it;
    }

    void operator=(const zVector<T> &_vector)
    {
        if (array)
            delete array;
        cap = _vector.cap;
        numOfElement = _vector.numOfElement;
        array = new T[cap];
        for (size_t i = 0; i < cap; i++)
            array[i] = _vector.array[i];
    }

    void push_back(const T &__x)
    {
        if (!array)
            array = new T[cap];
        if (numOfElement + 1 > cap)
            extend(cap * 2);
        array[numOfElement++] = __x;
    }

    void pop_back()
    {
        if (numOfElement > 0)
            numOfElement--;
    }

    void resize(const size_t newSize, const T __val = 0)
    {
        if (newSize > maxHold)
            __throw_length_error;
        if (newSize <= numOfElement)
        {
            numOfElement = newSize;
            return;
        }
        T *newArray = new T[newSize];
        for (size_t i = 0; i < newSize; i++)
            newArray[i] = (i < numOfElement ? array[i] : __val);
        delete[] array;
        array = newArray;
        numOfElement = cap = newSize;
    }

    void erase(const iterator &__position)
    {
        if (__position >= array + numOfElement)
            return;
        for (iterator it = __position; it != array + numOfElement - 1; it++)
            *it = *(it + 1);
        numOfElement--;
    }
    void erase(const iterator &__first, const iterator &__second)
    {
        if (__second < __first || __first >= array + numOfElement)
            return;
        if (__second >= array + numOfElement)
        {
            numOfElement = __first - array;
            return;
        }
        size_t count = array + numOfElement - 1 - __second;
        iterator it = __first;
        while (count--)
        {
            *it = *(it - __first + __second + 1);
            it++;
        }
        numOfElement = numOfElement - (__second - __first + 1);
    }

    void insert(const iterator &__position, const T &__val)
    {
        long long pos = __position - array;
        if (numOfElement + 1 > cap)
            extend(cap * 2);
        for (iterator it = array + numOfElement; it >= array + pos; it--)
            *(it + 1) = *it;
        *(array + pos) = __val;
        numOfElement++;
    }

    template <class _InputIterator>
    void insert(const iterator &__position, _InputIterator __first, _InputIterator __last)
    {
        long long length = abs(__last - __first);
        long long pos = __position - array;
        if (numOfElement + length > cap)
            extend(numOfElement + length);

        for (iterator it = array + numOfElement - 1; it >= array + pos; it--)
            *(it + length) = *(it);

        iterator temp = array + pos;
        for (_InputIterator it = __first; it != __last; it++)
            *(temp++) = *it;
        numOfElement = cap;
    }

    // Return an iterator pointing to the first element equal val, or end() otherwise.
    iterator find(const T &__val)
    {
        for (iterator it = array; it != array + numOfElement; it++)
        {
            if (*it == __val)
                return it;
        }
        return array + numOfElement;
    }

    void shrink_to_fit()
    {
        T *newArray = new T[numOfElement];
        for (size_t i = 0; i < numOfElement; i++)
            newArray[i] = array[i];
        if (array)
            delete[] array;
        array = newArray;
        cap = numOfElement;
    }

    void clear()
    {
        if (array)
            delete[] array;
        numOfElement = 0, cap = 1;
        array = nullptr;
    }

    T &operator[](size_t i) { return array[i]; }
    const T &operator[](size_t i) const { return array[i]; }

    const size_t &max_size() { return maxHold; }
    const size_t &max_size() const { return maxHold; }
    const bool &empty() { return numOfElement == 0; }
    const bool &empty() const { return numOfElement == 0; }
    const size_t &capacity() { return cap; }
    const size_t &capacity() const { return cap; }
    const size_t &size() { return numOfElement; }
    const size_t &size() const { return numOfElement; }
    const T &front() { return array[0]; }
    const T &front() const { return array[0]; }
    const T &back() { return array[numOfElement - 1]; }
    const T &back() const { return array[numOfElement - 1]; }

    iterator begin() { return array; }
    iterator end() { return array + numOfElement; }
    reverse_iterator rbegin() { return array + numOfElement - 1; }
    reverse_iterator rend() { return array - 1; }

    ~zVector()
    {
        if (array)
            delete[] array;
    }
};
#endif