#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Patron
{
public:
    string name;
    string transactionType;
    int numberOfBooks;
    int waitTime;

    Patron(string n, string trans, int books)
    {
        name = n;
        transactionType = trans;
        numberOfBooks = books;
        waitTime = 0;
    }
};

class LibraryQueue
{
private:
    queue<Patron> patronQueue;
    int totalPatronsServed;

public:
    LibraryQueue()
    {
        totalPatronsServed = 0;
    }

    void addPatron(string name, string transactionType, int numberOfBooks)
    {
        Patron newPatron(name, transactionType, numberOfBooks);
        patronQueue.push(newPatron);
        cout << "- " << name << " joined the queue for " << transactionType;
        cout << " (" << numberOfBooks << " books)" << endl;
        updateWaitTimes();
    }

    void serveNextPatron()
    {
        if (patronQueue.empty())
        {
            cout << "- No patrons in queue to serve." << endl;
            return;
        }

        Patron current = patronQueue.front();
        patronQueue.pop();
        totalPatronsServed++;

        int processTime = calculateProcessTime(current.numberOfBooks, current.transactionType);

        cout << endl
             << " SERVING PATRON:" << endl;
        cout << "   Name: " << current.name << endl;
        cout << "   Transaction: " << current.transactionType << endl;
        cout << "   Books: " << current.numberOfBooks << endl;
        cout << "   Process time: " << processTime << " minutes" << endl;
        cout << "   Wait time: " << current.waitTime << " minutes" << endl;
        cout << "   TRANSACTION COMPLETED" << endl;
        cout << "------------------------------" << endl;

        updateWaitTimes();
    }

    void displayCurrentQueue()
    {
        if (patronQueue.empty())
        {
            cout << "- Queue is currently empty." << endl;
            return;
        }

        cout << endl
             << " CURRENT LIBRARY QUEUE:" << endl;
        cout << "------------------------------" << endl;
        cout << "Patrons waiting: " << patronQueue.size() << endl;
        cout << "------------------------------" << endl;

        queue<Patron> tempQueue = patronQueue;
        int position = 1;

        while (!tempQueue.empty())
        {
            Patron p = tempQueue.front();
            cout << position << ". " << p.name << endl;
            cout << "   Type: " << p.transactionType;
            cout << " (" << p.numberOfBooks << " books)" << endl;
            cout << "   Waited: " << p.waitTime << " minutes" << endl;
            if (position < patronQueue.size())
            {
                cout << "   ----------------------" << endl;
            }
            tempQueue.pop();
            position++;
        }
        cout << "------------------------------" << endl;
    }

    int calculateProcessTime(int books, string transaction)
    {
        int baseTime = 2;
        if (transaction == "return")
        {
            baseTime = 3;
        }
        return baseTime + (books * 1);
    }

    void updateWaitTimes()
    {
        queue<Patron> tempQueue;
        int cumulativeTime = 0;

        while (!patronQueue.empty())
        {
            Patron p = patronQueue.front();
            patronQueue.pop();
            p.waitTime = cumulativeTime;
            cumulativeTime += calculateProcessTime(p.numberOfBooks, p.transactionType);
            tempQueue.push(p);
        }

        patronQueue = tempQueue;
    }

    void getQueueStats()
    {
        cout << endl
             << " LIBRARY STATISTICS:" << endl;
        cout << "------------------------------" << endl;
        cout << "Currently in queue: " << patronQueue.size() << " patrons" << endl;
        cout << "Total served today: " << totalPatronsServed << " patrons" << endl;
        if (!patronQueue.empty())
        {
            cout << "Next patron: " << patronQueue.front().name << endl;
        }
        else
        {
            cout << "Next patron: None" << endl;
        }
        cout << "------------------------------" << endl;
    }
};

int main()
{
    LibraryQueue library;

    cout << "ISLAMABAD PUBLIC LIBRARY SIMULATION" << endl;
    cout << "-----------------------------------" << endl;

    cout << endl
         << "PATRONS JOINING QUEUE:" << endl;
    cout << "------------------------------" << endl;
    library.addPatron("Ali Raza", "borrow", 3);
    library.addPatron("Fatima Khan", "return", 5);
    library.addPatron("Bilal Ahmed", "borrow", 2);
    library.addPatron("Sana Sheikh", "return", 7);

    library.displayCurrentQueue();

    cout << endl
         << "SERVING PATRONS:" << endl;
    cout << "------------------------------" << endl;
    library.serveNextPatron();
    library.serveNextPatron();

    library.displayCurrentQueue();

    cout << endl
         << "MORE PATRONS JOINING:" << endl;
    cout << "------------------------------" << endl;
    library.addPatron("Usman Malik", "borrow", 1);
    library.addPatron("Ayesha Noor", "return", 4);

    library.displayCurrentQueue();

    library.getQueueStats();

    cout << endl
         << "CONTINUING SERVICE:" << endl;
    cout << "------------------------------" << endl;
    library.serveNextPatron();
    library.serveNextPatron();
    library.serveNextPatron();

    library.getQueueStats();

    cout << endl
         << "SIMULATION COMPLETE" << endl;

    return 0;
}
