#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;
};

class MaxHeap {
private:
    Task heap[100];
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while(index != 0 && heap[parent(index)].priority < heap[index].priority) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int l = leftChild(index);
        int r = rightChild(index);

        if(l < size && heap[l].priority > heap[largest].priority) largest = l;
        if(r < size && heap[r].priority > heap[largest].priority) largest = r;

        if(largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() { size = 0; }

    void insert(string taskName, int taskPriority) {
        heap[size] = {taskName, taskPriority};
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
            cout << "(" << heap[i].name << ", " << heap[i].priority << ") ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap taskScheduler;

    taskScheduler.insert("A", 5);
    taskScheduler.insert("B", 3);
    taskScheduler.insert("C", 8);

    cout << "Heap after inserting tasks A, B, C: ";
    taskScheduler.printHeap();

    taskScheduler.removeMax();
    cout << "Heap after removing highest priority task: ";
    taskScheduler.printHeap();

    taskScheduler.insert("D", 6);
    cout << "Heap after adding task D: ";
    taskScheduler.printHeap();

    return 0;
}
