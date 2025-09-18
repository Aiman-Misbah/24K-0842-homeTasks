#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string itemName;
    int price;
    Node* next;

    Node(string name, int p) {
        itemName = name;
        price = p;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() {
        head = nullptr;
    }

    void addToTail(string name, int price) {
        Node* newNode = new Node(name, price);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteFromFront() {
        if (head == nullptr) {
            cout << "Cart is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByName(string name) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->itemName == name) {
                cout << name << " found with price PKR " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in cart" << endl;
    }

    void searchByPosition(int pos) {
        if (pos <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != nullptr) {
            if (count == pos) {
                cout << "Position " << pos << ": " << temp->itemName 
                     << " - PKR " << temp->price << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "No item at position " << pos << endl;
    }

    void displayCart() {
        if (head == nullptr) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Cart Items:" << endl;
        while (temp != nullptr) {
            cout << temp->itemName << " - PKR " << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ShoppingCart cart;

    cart.addToTail("Laptop Karachi", 120000);
    cart.addToTail("Phone Lahore", 75000);
    cart.addToTail("Tablet Islamabad", 50000);
    cart.addToTail("Headphones Multan", 18000);

    cart.displayCart();

    cout << endl << "Deleting first item..." << endl;
    cart.deleteFromFront();

    cart.displayCart();

    cout << endl;
    cart.searchByName("Tablet Islamabad");
    cart.searchByName("Camera Peshawar");

    cout << endl;
    cart.searchByPosition(2);
    cart.searchByPosition(5);

    return 0;
}

