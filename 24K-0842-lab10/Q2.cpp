#include <iostream>
using namespace std;

class MaxHeap {
private:
    int heap[100];
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while(index != 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int l = leftChild(index);
        int r = rightChild(index);

        if(l < size && heap[l] > heap[largest]) largest = l;
        if(r < size && heap[r] > heap[largest]) largest = r;

        if(largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() { size = 0; }

    void insert(int severity) {
        heap[size] = severity;
        size++;
        heapifyUp(size - 1);
    }

    void removeMax() {
        if(size == 0) return;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    void printHeap() {
        for(int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap erHeap;

    erHeap.insert(7);
    erHeap.insert(5);
    erHeap.insert(8);
    erHeap.insert(6);

    cout << "Initial heap (patients by severity): ";
    erHeap.printHeap();

    erHeap.insert(10);
    cout << "After adding patient with severity 10: ";
    erHeap.printHeap();

    erHeap.removeMax();
    cout << "After treating patient with highest severity: ";
    erHeap.printHeap();

    return 0;
}
