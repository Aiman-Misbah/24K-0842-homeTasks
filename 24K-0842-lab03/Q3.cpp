#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;
    int price;
    Node* next;
    Node* prev;

    Node(int itemId, string itemName, int itemPrice) {
        id = itemId;
        name = itemName;
        price = itemPrice;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtFront(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void removeFirst() {
        if (head == nullptr) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void removeLast() {
        if (tail == nullptr) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void searchById(int id) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Item found: ID " << temp->id << ", " 
                     << temp->name << ", PKR " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    void updatePriceById(int id, int newPrice) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                temp->price = newPrice;
                cout << "Price updated for " << temp->name << " to PKR " << newPrice << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Cart (Front to End):" << endl;
        while (temp != nullptr) {
            cout << temp->id << " - " << temp->name << " - PKR " << temp->price << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (tail == nullptr) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = tail;
        cout << "Cart (End to Front):" << endl;
        while (temp != nullptr) {
            cout << temp->id << " - " << temp->name << " - PKR " << temp->price << endl;
            temp = temp->prev;
        }
    }

    void countItems() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total items in cart: " << count << endl;
    }

    void findMostExpensive() {
        if (head == nullptr) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        Node* maxNode = head;
        while (temp != nullptr) {
            if (temp->price > maxNode->price) {
                maxNode = temp;
            }
            temp = temp->next;
        }
        cout << "Most Expensive Item: " << maxNode->id << " - " 
             << maxNode->name << " - PKR " << maxNode->price << endl;
    }
};

int main() {
    DoublyLinkedList cart;

    cart.insertAtEnd(101, "Laptop Karachi", 120000);
    cart.insertAtEnd(102, "Phone Lahore", 75000);
    cart.insertAtEnd(103, "Tablet Islamabad", 50000);

    cart.displayForward();
    cout << endl;

    cart.insertAtFront(100, "Urgent Keyboard Multan", 8000);
    cart.displayForward();
    cout << endl;

    cart.removeFirst();
    cart.displayForward();
    cout << endl;

    cart.removeLast();
    cart.displayForward();
    cout << endl;

    cart.searchById(102);
    cart.searchById(200);
    cout << endl;

    cart.updatePriceById(102, 72000);
    cart.displayForward();
    cout << endl;

    cart.displayBackward();
    cout << endl;

    cart.countItems();
    cart.findMostExpensive();

    return 0;
}
