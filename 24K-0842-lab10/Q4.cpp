#include <iostream>
using namespace std;

class MinHeap {
private:
    int heap[100];
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while(index != 0 && heap[parent(index)] > heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int l = leftChild(index);
        int r = rightChild(index);

        if(l < size && heap[l] < heap[smallest]) smallest = l;
        if(r < size && heap[r] < heap[smallest]) smallest = r;

        if(smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() { size = 0; }

    void insert(int price) {
        heap[size] = price;
        size++;
        heapifyUp(size - 1);
    }

    void removeMin() {
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
    MinHeap stockOrders;

    stockOrders.insert(100);
    stockOrders.insert(50);
    stockOrders.insert(75);
    stockOrders.insert(60);

    cout << "Initial min-heap of orders: ";
    stockOrders.printHeap();

    stockOrders.insert(55);
    cout << "After adding order with price 55: ";
    stockOrders.printHeap();

    stockOrders.removeMin();
    cout << "After executing order with lowest price: ";
    stockOrders.printHeap();

    return 0;
}
