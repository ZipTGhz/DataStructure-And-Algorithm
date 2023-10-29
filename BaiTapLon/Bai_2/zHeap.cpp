#include "zVector.cpp"

using namespace std;

template <class T, class Comparator = less<T>>
class zHeap
{
private:
    zVector<T> heap;
    Comparator comp;
    void adjust_zHeap(size_t children)
    {
        size_t parent = children >> 1;
        if (parent < 1)
            return;
        if (!comp(heap[children], heap[parent]))
        {
            swap(heap[children], heap[parent]);
            adjust_zHeap(parent);
        }
    }

    void reverse_adjust_zHeap(size_t parent)
    {
        size_t larger;
        size_t left = parent << 1, right = (parent << 1) + 1;

        if (right < heap.size() && comp(heap[parent], heap[right]))
            larger = right;
        else
            larger = parent;
        if (left < heap.size() && comp(heap[parent], heap[left]))
            larger = left;

        if (larger != parent)
        {
            swap(heap[larger], heap[parent]);
            reverse_adjust_zHeap(larger);
        }
    }

public:
    zHeap() { heap = zVector<T>(1, -1); }

    void push(T __data)
    {
        heap.push_back(__data);
        adjust_zHeap(heap.size() - 1);
    }

    void pop()
    {
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        reverse_adjust_zHeap(1);
    }

    size_t size() { return heap.size() - 1; }
    size_t size() const { return heap.size() - 1; }
    T top() { return heap[1]; }
    T top() const { return heap[1]; }
    bool empty() { return heap.size() == 1; }
    bool empty() const { return heap.size() == 1; }
};

int main()
{
    int n;
    cin >> n;
    zHeap<int, greater<int>> myPQueue;
    while (n--)
    {
        int x;
        cin >> x;
        myPQueue.push(x);
    }

    int res = 0;

    while (myPQueue.size() != 1)
    {
        int first = myPQueue.top();
        myPQueue.pop();
        int second = myPQueue.top();
        myPQueue.pop();
        int sum = first + second;
        res += sum;
        myPQueue.push(sum);
    }
    cout << res;
    return 0;
}