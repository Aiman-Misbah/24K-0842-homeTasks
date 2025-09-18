#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int ticketID;
    string customerName;
    string rideName;
    Node *next;

    Node(int id, string cname, string rname)
    {
        ticketID = id;
        customerName = cname;
        rideName = rname;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void issueTicketEnd(int id, string cname, string rname)
    {
        Node *newNode = new Node(id, cname, rname);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void issueTicketFront(int id, string cname, string rname)
    {
        Node *newNode = new Node(id, cname, rname);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void cancelTicketByID(int id)
    {
        if (!head)
        {
            cout << "No tickets to cancel." << endl;
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        do
        {
            if (temp->ticketID == id)
            {
                if (temp == head)
                {
                    cancelFirstTicket();
                    return;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    cout << "Ticket " << id << " cancelled." << endl;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Ticket ID not found." << endl;
    }

    void cancelFirstTicket()
    {
        if (!head)
        {
            cout << "No tickets to cancel." << endl;
            return;
        }
        if (head->next == head)
        {
            cout << "Ticket " << head->ticketID << " cancelled." << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        cout << "Ticket " << temp->ticketID << " cancelled." << endl;
        delete temp;
    }

    void searchTicketByID(int id)
    {
        if (!head)
        {
            cout << "No tickets available." << endl;
            return;
        }
        Node *temp = head;
        do
        {
            if (temp->ticketID == id)
            {
                cout << "Ticket Found: ID=" << temp->ticketID
                     << ", Customer=" << temp->customerName
                     << ", Ride=" << temp->rideName << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Ticket ID not found." << endl;
    }

    void displayAllTickets()
    {
        if (!head)
        {
            cout << "No tickets available." << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << "ID=" << temp->ticketID
                 << ", Customer=" << temp->customerName
                 << ", Ride=" << temp->rideName << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void countTickets()
    {
        if (!head)
        {
            cout << "Total tickets: 0" << endl;
            return;
        }
        int count = 0;
        Node *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        cout << "Total tickets: " << count << endl;
    }

    void findNextTicket(int id)
    {
        if (!head)
        {
            cout << "No tickets available." << endl;
            return;
        }
        Node *temp = head;
        do
        {
            if (temp->ticketID == id)
            {
                Node *nextTicket = temp->next;
                cout << "Next Ticket: ID=" << nextTicket->ticketID
                     << ", Customer=" << nextTicket->customerName
                     << ", Ride=" << nextTicket->rideName << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Ticket ID not found." << endl;
    }
};

int main()
{
    CircularLinkedList bookingSystem;

    bookingSystem.issueTicketEnd(101, "Ali", "Ferris Wheel");
    bookingSystem.issueTicketEnd(102, "Sara", "Roller Coaster");
    bookingSystem.issueTicketFront(100, "VIP Ahmed", "Haunted House");

    cout << "--- All Tickets ---" << endl;
    bookingSystem.displayAllTickets();
    cout << endl;

    bookingSystem.searchTicketByID(102);
    cout << endl;

    bookingSystem.findNextTicket(100);
    cout << endl;

    bookingSystem.cancelTicketByID(101);
    cout << endl;

    cout << "--- After Cancellation ---" << endl;
    bookingSystem.displayAllTickets();
    cout << endl;

    bookingSystem.countTickets();
    cout << endl;

    bookingSystem.cancelFirstTicket();
    cout << endl;

    cout << "--- Final Tickets ---" << endl;
    bookingSystem.displayAllTickets();
    cout << endl;

    return 0;
}
