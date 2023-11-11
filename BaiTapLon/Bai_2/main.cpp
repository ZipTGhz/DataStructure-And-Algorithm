#include "zHeap.cpp"

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    zHeap<int> myPQueue;
    while (n--)
    {
        int x;
        cin >> x;
        myPQueue.push(x);
    }

    cout << "Day giam dan la: ";
    while (!myPQueue.empty())
    {
        int temp = myPQueue.top();
        myPQueue.pop();
        cout << temp << " ";
    }
    return 0;
}