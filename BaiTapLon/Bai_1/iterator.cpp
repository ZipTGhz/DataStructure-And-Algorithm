#ifndef iterator__cpp
#define iterator__cpp

template <class T>
class zVector_reverse_iterator
{
    T *pointer;

public:
    zVector_reverse_iterator(T *pointer = nullptr) : pointer(pointer) {}
    void operator=(zVector_reverse_iterator<T> it) { pointer = it.pointer; }
    T &operator*() { return *pointer; }
    T &operator*() const { return *pointer; }

    zVector_reverse_iterator<T> operator++() { return --pointer; }    //++pointer
    zVector_reverse_iterator<T> operator++(int) { return pointer--; } // pointer++
    zVector_reverse_iterator<T> operator--() { return ++pointer; }    //--pointer
    zVector_reverse_iterator<T> operator--(int) { return pointer++; } // pointer--

    bool operator>=(zVector_reverse_iterator<T> it) { return pointer <= it.pointer; }
    bool operator>(zVector_reverse_iterator<T> it) { return pointer < it.pointer; }
    bool operator<=(zVector_reverse_iterator<T> it) { return pointer >= it.pointer; }
    bool operator<(zVector_reverse_iterator<T> it) { return pointer > it.pointer; }
    bool operator!=(zVector_reverse_iterator<T> it) { return pointer != it.pointer; }

    zVector_reverse_iterator<T> operator+(long long val) { return pointer - val; }
    zVector_reverse_iterator<T> operator+(long long val) const { return pointer - val; }

    long long operator-(zVector_reverse_iterator<T> it) { return pointer - it.pointer; }
    long long operator-(zVector_reverse_iterator<T> it) const { return pointer - it.pointer; }
    zVector_reverse_iterator<T> operator-(long long val) { return pointer + val; }
    zVector_reverse_iterator<T> operator-(long long val) const { return pointer + val; }
};

template <class T>
class zVector_iterator
{
    T *pointer;

public:
    zVector_iterator(T *pointer = nullptr) : pointer(pointer) {}

    void operator=(zVector_iterator<T> it) { pointer = it.pointer; }
    T &operator*() { return *pointer; }
    T &operator*() const { return *pointer; }

    zVector_iterator<T> operator++() { return ++pointer; }    //++pointer
    zVector_iterator<T> operator++(int) { return pointer++; } // pointer++
    zVector_iterator<T> operator--() { return --pointer; }    //--pointer
    zVector_iterator<T> operator--(int) { return pointer--; } // pointer--

    bool operator>=(zVector_iterator<T> it) { return pointer >= it.pointer; }
    bool operator>(zVector_iterator<T> it) { return pointer > it.pointer; }
    bool operator<=(zVector_iterator<T> it) { return pointer <= it.pointer; }
    bool operator<(zVector_iterator<T> it) { return pointer < it.pointer; }
    bool operator!=(zVector_iterator<T> it) { return pointer != it.pointer; }

    zVector_iterator<T> operator+(long long val) { return pointer + val; }
    zVector_iterator<T> operator+(long long val) const { return pointer + val; }

    long long operator-(zVector_iterator<T> it) { return pointer - it.pointer; }
    long long operator-(zVector_iterator<T> it) const { return pointer - it.pointer; }
    zVector_iterator<T> operator-(long long val) { return pointer - val; }
    zVector_iterator<T> operator-(long long val) const { return pointer - val; }
};
#endif