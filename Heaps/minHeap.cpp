#include <bits/stdc++.h>
using namespace std;

using namespace std;

class minHeap
{

    int *arr;
    int size;
    int total_size;

public:
    minHeap(int n)
    {
        total_size = n;
        size = 0;
        arr = new int[n];
    }

    // insert a new element into the min heap
    void insert(int x);
    // print the heap
    void print();

    // heapifying the heap
    void heapify(int i);

    // delete the root element of the heap
    void deleteRoot();
};

void minHeap::insert(int x)
{
    if (size == total_size)
    {
        cout << "Heap overflow ! " << endl;
        return;
    }

    size++;
    arr[size - 1] = x;
    int i = size - 1;

    // compare the new element with its ancestors
    // also known as set up
    while (i > 0 && arr[(i - 1) / 2] > arr[i])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    cout << "Element inserted successfully" << endl;

    return;
}

void minHeap::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return;
}

void minHeap::heapify(int i)
{
    // smallest will store the index of the smallest element among the root, left child and right child
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right < size && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(smallest);
    }

    return;
}

void minHeap::deleteRoot()
{
    if (size == 0)
    {
        cout << "Heap underflow ! " << endl;
        return;
    }

    arr[0] = arr[size - 1];
    size--;

    // heapify the heap
    heapify(0);

    cout << "Root element deleted successfully" << endl;
    return;
}

int main()
{
    minHeap h1(6); // 6 is the total size of the heap
    h1.insert(10);
    h1.insert(20);
    h1.insert(30);
    h1.insert(40);
    h1.insert(50);
    h1.insert(60);
    h1.insert(70);
    h1.print(); // here we are doing nothing but level order traversal of the heap
    h1.deleteRoot();
    h1.print();

    return 0;
}
