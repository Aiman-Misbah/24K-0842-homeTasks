#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct ListNode
{
    string url;
    ListNode *next;
    ListNode(string u) : url(u), next(nullptr) {}
};

class BrowserHistory
{
private:
    ListNode *head;
    stack<string> backStack;

public:
    BrowserHistory() : head(nullptr) {}

    void visitWebsite(string url)
    {
        ListNode *newNode = new ListNode(url);
        newNode->next = head;
        head = newNode;
        backStack.push(url);
        cout << "Visited: " << url << endl;
    }

    void goBack(int steps)
    {
        cout << "Going back " << steps << " step(s)" << endl;

        for (int i = 0; i < steps; i++)
        {
            if (head == nullptr || backStack.empty())
            {
                cout << "Cannot go back further!" << endl;
                return;
            }

            string removedUrl = backStack.top();
            backStack.pop();

            ListNode *temp = head;
            head = head->next;
            delete temp;

            cout << "Removed from history: " << removedUrl << endl;
        }
    }

    void displayHistory()
    {
        cout << "=== CURRENT BROWSING HISTORY ===" << endl;
        if (head == nullptr)
        {
            cout << "History is empty" << endl;
            return;
        }

        ListNode *current = head;
        int position = 1;
        while (current != nullptr)
        {
            cout << position << ". " << current->url << endl;
            current = current->next;
            position++;
        }
        cout << "-----------------------" << endl;
    }
};

int main()
{
    BrowserHistory browser;

    cout << "=== WEB BROWSING SIMULATION ===" << endl;
    cout << endl;

    browser.visitWebsite("www.google.com");
    browser.visitWebsite("www.facebook.com");
    browser.visitWebsite("www.twitter.com");
    browser.visitWebsite("www.linkedin.com");
    browser.visitWebsite("www.instagram.com");

    cout << endl;
    browser.displayHistory();

    cout << "User clicks back button twice..." << endl;
    browser.goBack(2);

    cout << endl;
    browser.displayHistory();

    cout << "Visiting new websites..." << endl;
    browser.visitWebsite("www.daraz.pk");
    browser.visitWebsite("www.urdupoint.com");

    cout << endl;
    browser.displayHistory();

    cout << "Going back 1 step..." << endl;
    browser.goBack(1);

    cout << endl;
    browser.displayHistory();

    return 0;
}
