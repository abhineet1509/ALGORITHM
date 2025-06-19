#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int smallest = i;
        int left = 2*i + 1, right = 2*i + 2;

        if (left < n && heap[left] < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMin() {
        if (heap.empty()) return;
        cout << "Deleted: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(20);
    h.insert(10);
    h.insert(30);
    h.insert(5);
    h.insert(15);
    h.display();      // Output: 5 10 30 20 15
    h.deleteMin();    
    h.display();      // Output: 10 15 30 20
}
