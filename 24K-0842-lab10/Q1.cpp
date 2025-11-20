#include <iostream>
using namespace std;

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return (2 * i) + 1; }
int rightChild(int i) { return (2 * i) + 2; }

void heapifyUp(int heap[], int index) {
    while (index != 0 && heap[parent(index)] > heap[index]) {
        int temp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = temp;
        index = parent(index);
    }
}

void insertMinHeap(int heap[], int &size, int value) {
    heap[size] = value;
    heapifyUp(heap, size);
    size++;
}

void printHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap[100] = {1, 3, 4, 5};
    int size = 4;

    cout << "Initial package priorities (min-heap): ";
    printHeap(heap, size);

    int newPackage = 2;
    cout << "Inserting new package with priority: " << newPackage << endl;
    insertMinHeap(heap, size, newPackage);

    cout << "Updated heap after insertion: ";
    printHeap(heap, size);

    return 0;
}
