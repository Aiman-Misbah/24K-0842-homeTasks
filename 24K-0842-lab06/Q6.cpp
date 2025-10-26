#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Order
{
public:
    string customerName;
    map<string, int> items;
    double totalAmount;
    int orderNumber;

    Order(string name, map<string, int> orderItems, double amount, int number)
    {
        customerName = name;
        items = orderItems;
        totalAmount = amount;
        orderNumber = number;
    }
};

class RestaurantOrderSystem
{
private:
    queue<Order> orderQueue;
    vector<Order> processedOrders;
    int currentOrderNumber;
    int maxQueueSize;

public:
    RestaurantOrderSystem(int maxSize = 100)
    {
        currentOrderNumber = 1;
        maxQueueSize = maxSize;
    }

    bool addOrder(string customerName, map<string, int> items, double amount)
    {
        if (orderQueue.size() >= maxQueueSize)
        {
            cout << "Queue full! Cannot accept new orders temporarily." << endl;
            return false;
        }

        Order newOrder(customerName, items, amount, currentOrderNumber);
        orderQueue.push(newOrder);
        currentOrderNumber++;

        cout << "Order #" << newOrder.orderNumber << " added for " << customerName << endl;
        return true;
    }

    bool processOrder()
    {
        if (orderQueue.empty())
        {
            cout << "No orders to process." << endl;
            return false;
        }

        Order processed = orderQueue.front();
        orderQueue.pop();
        processedOrders.push_back(processed);

        cout << "Processing Order #" << processed.orderNumber << " for " << processed.customerName << endl;
        cout << "Items: ";
        for (auto item : processed.items)
        {
            cout << item.first << " (Qty: " << item.second << ") ";
        }
        cout << endl;
        cout << "Total: Rs. " << processed.totalAmount << endl;
        cout << "---" << endl;

        return true;
    }

    void displayCurrentQueue()
    {
        if (orderQueue.empty())
        {
            cout << "No orders in queue." << endl;
            return;
        }

        cout << "=== CURRENT ORDER QUEUE ===" << endl;
        queue<Order> temp = orderQueue;
        int position = 1;

        while (!temp.empty())
        {
            Order order = temp.front();
            cout << position << ". Order #" << order.orderNumber << " - " << order.customerName;
            cout << " (Rs. " << order.totalAmount << ")" << endl;
            temp.pop();
            position++;
        }
        cout << "Total orders waiting: " << orderQueue.size() << endl;
    }

    void displayProcessedOrders()
    {
        if (processedOrders.empty())
        {
            cout << "No orders processed yet." << endl;
            return;
        }

        cout << "=== PROCESSED ORDERS ===" << endl;
        for (Order order : processedOrders)
        {
            cout << "Order #" << order.orderNumber << " - " << order.customerName;
            cout << " - Rs. " << order.totalAmount << endl;
        }
    }

    bool isQueueFull()
    {
        return orderQueue.size() >= maxQueueSize;
    }

    bool isQueueEmpty()
    {
        return orderQueue.empty();
    }
};

int main()
{
    RestaurantOrderSystem restaurant(5);

    cout << "=== KARACHI BIRYANI CENTER ORDER SYSTEM ===" << endl;
    cout << endl;

    map<string, int> order1;
    order1["Chicken Biryani"] = 2;
    order1["Raita"] = 2;
    order1["Cold Drink"] = 2;
    restaurant.addOrder("Ali Ahmed", order1, 1200.0);

    map<string, int> order2;
    order2["Mutton Biryani"] = 1;
    order2["Salad"] = 1;
    restaurant.addOrder("Fatima Khan", order2, 850.0);

    map<string, int> order3;
    order3["Chicken Karahi"] = 1;
    order3["Naan"] = 4;
    order3["Lassi"] = 2;
    restaurant.addOrder("Bilal Raza", order3, 1800.0);

    cout << endl;
    restaurant.displayCurrentQueue();
    cout << endl;

    cout << "=== PROCESSING ORDERS ===" << endl;
    restaurant.processOrder();
    restaurant.processOrder();

    cout << endl;
    restaurant.displayCurrentQueue();

    map<string, int> order4;
    order4["Seekh Kabab"] = 6;
    order4["Roghni Naan"] = 3;
    restaurant.addOrder("Sana Sheikh", order4, 950.0);

    cout << endl;
    restaurant.displayProcessedOrders();

    return 0;
}
