// here we will add both insert and delete operation on heap
#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;       // current size
    int total_size; // actual total size
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }
    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "heap overflow\n";
            return;
        }
        arr[size] = value;
        int index = size;
        size++;
        while (index > 0 && arr[((index - 1) / 2)] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        };
    }
    void heapify(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    };
    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    // delete operation
    void deleteNode()
    {
        if (size == 0)
        {
            cout << "heap is empty\n";
            return;
        }
        cout << arr[0] << " deleted \n";
        arr[0] = arr[size - 1];
        size--;
        if (size == 0)
            return;
        heapify(0);
    };
};
int main()
{
    MaxHeap Heap(6);
    Heap.insert(10);
    Heap.insert(20);
    Heap.insert(5);
    Heap.insert(30);
    Heap.insert(15);
    Heap.insert(67);
    Heap.deleteNode();

    cout << "Heap elements: ";
    Heap.display();

    return 0;
}
