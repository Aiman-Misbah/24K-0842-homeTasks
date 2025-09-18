#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string itemName;
    int price;
    Node *next;

    Node(string name, int p)
    {
        itemName = name;
        price = p;
        next = nullptr;
    }
};

class ShoppingCart
{
private:
    Node *head;

public:
    ShoppingCart()
    {
        head = nullptr;
    }

    void addAtFront(string name, int price)
    {
        Node *newNode = new Node(name, price);
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(string name, int price)
    {
        Node *newNode = new Node(name, price);
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

    void insertAfter(string target, string name, int price)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->itemName == target)
            {
                Node *newNode = new Node(name, price);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    void searchItem(string name)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->itemName == name)
            {
                cout <<endl<< name << " found with price PKR " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in cart" << endl;
    }

    void displayCart()
    {
        Node *temp = head;
        cout << endl
             << "Cart Items:" << endl;
        while (temp != nullptr)
        {
            cout << temp->itemName << " - PKR " << temp->price << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    ShoppingCart cart;

    cart.addAtEnd("Laptop", 100000);
    cart.addAtEnd("Phone", 70000);
    cart.addAtEnd("Tablet", 40000);
    cart.addAtEnd("Headphones", 15000);

    cart.addAtFront("Smartwatch", 20000);
    cart.addAtEnd("Keyboard", 8000);
    cart.insertAfter("Phone", "Monitor", 30000);

    cart.searchItem("Tablet");

    cart.displayCart();

    return 0;
}

