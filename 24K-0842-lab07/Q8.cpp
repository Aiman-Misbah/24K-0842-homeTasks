#include <iostream>
#include <string>
using namespace std;

class Order
{
public:
    int orderID;
    string customerName;
    double totalPrice;

    Order(int id, string name, double price)
    {
        orderID = id;
        customerName = name;
        totalPrice = price;
    }
};

class OrderManager
{
private:
    void swap(Order *a, Order *b)
    {
        Order temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(Order orders[], int low, int high)
    {
        double pivot = orders[high].totalPrice;
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (orders[j].totalPrice <= pivot)
            {
                i++;
                swap(&orders[i], &orders[j]);
            }
        }

        swap(&orders[i + 1], &orders[high]);
        return i + 1;
    }

    void quickSort(Order orders[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(orders, low, high);
            quickSort(orders, low, pi - 1);
            quickSort(orders, pi + 1, high);
        }
    }

public:
    void sortOrders(Order orders[], int size)
    {
        quickSort(orders, 0, size - 1);
    }

    void displayOrders(Order orders[], int size)
    {
        cout << "OrderID\tCustomer Name\tTotal Price (PKR)" << endl;
        cout << "----------------------------------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << orders[i].orderID << "\t" << orders[i].customerName
                 << "\t\t" << orders[i].totalPrice << endl;
        }
    }
};

int main()
{
    OrderManager manager;

    Order orders[] = {
        Order(101, "Ali Ahmed", 4500.75),
        Order(102, "Fatima Khan", 3200.50),
        Order(103, "Bilal Raza", 8900.25),
        Order(104, "Sana Malik", 2100.00),
        Order(105, "Usman Butt", 6700.80),
        Order(106, "Ayesha Sheikh", 1500.30),
        Order(107, "Zainab Hashmi", 5400.60)};

    int orderCount = sizeof(orders) / sizeof(orders[0]);

    cout << "Original Orders:" << endl;
    manager.displayOrders(orders, orderCount);

    manager.sortOrders(orders, orderCount);

    cout << "\nSorted Orders by Price (Ascending):" << endl;
    manager.displayOrders(orders, orderCount);

    Order testOrders[] = {
        Order(1, "Test Customer 1", 1000.0),
        Order(2, "Test Customer 2", 500.0),
        Order(3, "Test Customer 3", 1500.0)};

    int testCount = sizeof(testOrders) / sizeof(testOrders[0]);

    cout << "\nTest Orders Before Sorting:" << endl;
    manager.displayOrders(testOrders, testCount);

    manager.sortOrders(testOrders, testCount);

    cout << "\nTest Orders After Sorting:" << endl;
    manager.displayOrders(testOrders, testCount);

    return 0;
}
