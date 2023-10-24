#include "zVector.cpp"

using namespace std;

template <class T>
class zHeap
{
private:
    zVector<T> heap;

    void max_zHeap(size_t children)
    {
        size_t parent = children >> 1;
        if (parent < 1)
            return;
        if (heap[children] > heap[parent])
        {
            swap(heap[children], heap[parent]);
            max_zHeap(parent);
        }
    }

    void reverse_max_zHeap(size_t parent)
    {
        size_t larger;
        size_t left = parent << 1, right = (parent << 1) + 1;
        if (right < heap.size() && heap[parent] < heap[right])
            larger = right;
        else
            larger = parent;
        if (left < heap.size() && heap[parent] < heap[left])
            larger = left;

        if (larger != parent)
        {
            swap(heap[larger], heap[parent]);
            reverse_max_zHeap(larger);
        }
    }

public:
    zHeap() { heap = zVector<T>(1, -1); }

    void push(T __data)
    {
        heap.push_back(__data);
        max_zHeap(heap.size() - 1);
    }

    void pop()
    {
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        reverse_max_zHeap(1);
    }

    void print_max_zHeap(size_t parent = 1)
    {
    }

    size_t size() { return heap.size() - 1; }
    size_t size() const { return heap.size() - 1; }
    T operator[](size_t i) { return heap[i + 1]; }
    T operator[](size_t i) const { return heap[i + 1]; }
    T top() { return heap[1]; }
};

template <class T>
bool is_max_zHeap(const zHeap<T> &heap)
{
    size_t left, right;
    for (size_t parent = (heap.size() - 1) >> 1; parent >= 1; parent--)
    {
        left = parent << 1, right = (parent << 1) + 1;
        if (heap[left] > heap[parent] || heap[right] > heap[parent])
            return false;
    }
    return true;
}

int main()
{
    zHeap<int> test;
    zVector<int> arr = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        test.push(arr[i]);
    }

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }
    cout << endl;
    test.pop();

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }

    cout << endl;
    cout << is_max_zHeap(test);
    return 0;
}