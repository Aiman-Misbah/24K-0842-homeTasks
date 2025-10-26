#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

    Node *getTail(Node *current)
    {
        while (current != nullptr && current->next != nullptr)
        {
            current = current->next;
        }
        return current;
    }

    Node *partition(Node *start, Node *end, Node **newStart, Node **newEnd)
    {
        Node *pivot = end;
        Node *previous = nullptr;
        Node *current = start;
        Node *tail = pivot;

        while (current != pivot)
        {
            if (current->data < pivot->data)
            {
                if (*newStart == nullptr)
                {
                    *newStart = current;
                }
                previous = current;
                current = current->next;
            }
            else
            {
                if (previous != nullptr)
                {
                    previous->next = current->next;
                }
                Node *temp = current->next;
                current->next = nullptr;
                tail->next = current;
                tail = current;
                current = temp;
            }
        }

        if (*newStart == nullptr)
        {
            *newStart = pivot;
        }

        *newEnd = tail;
        return pivot;
    }

    Node *quickSortHelper(Node *start, Node *end)
    {
        if (start == nullptr || start == end)
        {
            return start;
        }

        Node *newStart = nullptr;
        Node *newEnd = nullptr;

        Node *pivot = partition(start, end, &newStart, &newEnd);

        if (newStart != pivot)
        {
            Node *temp = newStart;
            while (temp->next != pivot)
            {
                temp = temp->next;
            }
            temp->next = nullptr;

            newStart = quickSortHelper(newStart, temp);

            temp = getTail(newStart);
            temp->next = pivot;
        }

        pivot->next = quickSortHelper(pivot->next, newEnd);

        return newStart;
    }

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void quickSort()
    {
        head = quickSortHelper(head, getTail(head));
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    SinglyLinkedList list;

    int testScores[] = {85, 92, 78, 95, 88, 76, 90};
    int size = sizeof(testScores) / sizeof(testScores[0]);

    for (int i = 0; i < size; i++)
    {
        list.insert(testScores[i]);
    }

    cout << "Original Test scores: ";
    list.display();

    list.quickSort();

    cout << "Sorted test scores: ";
    list.display();

    SinglyLinkedList assignmentList;
    int assignmentNumbers[] = {10, 7, 8, 9, 1, 5, 3};
    int assignmentSize = sizeof(assignmentNumbers) / sizeof(assignmentNumbers[0]);

    for (int i = 0; i < assignmentSize; i++)
    {
        assignmentList.insert(assignmentNumbers[i]);
    }

    cout << endl
         << "Original assignment numbers: ";
    assignmentList.display();

    assignmentList.quickSort();

    cout << "Sorted assignment numbers: ";
    assignmentList.display();

    return 0;
}
