#include "zHeap.cpp"

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
