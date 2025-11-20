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

    void insert(int rating) {
        heap[size] = rating;
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
    MaxHeap matchmakingQueue;

    matchmakingQueue.insert(1500);
    matchmakingQueue.insert(1200);
    matchmakingQueue.insert(1800);
    matchmakingQueue.insert(1600);

    cout << "Initial player queue (by rating): ";
    matchmakingQueue.printHeap();

    matchmakingQueue.insert(1700);
    cout << "After adding player with rating 1700: ";
    matchmakingQueue.printHeap();

    matchmakingQueue.removeMax();
    cout << "After matching highest-rated player: ";
    matchmakingQueue.printHeap();

    return 0;
}
