#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Call
{
public:
    string name;
    string number;
    int duration;

    Call(string n, string num, int d) : name(n), number(num), duration(d) {}
};

void displayCallLog(stack<Call> callHistory)
{
    if (callHistory.empty())
    {
        cout << "Call history is empty" << endl;
        cout << "------------------------" << endl;
        return;
    }

    stack<Call> temp;
    int count = 1;

    while (!callHistory.empty())
    {
        temp.push(callHistory.top());
        callHistory.pop();
    }

    cout << "=== CURRENT CALL LOG ===" << endl;
    while (!temp.empty())
    {
        Call current = temp.top();
        cout << count << ". Name: " << current.name << endl;
        cout << "   Number: " << current.number << endl;
        cout << "   Duration: " << current.duration << " seconds" << endl;
        cout << "-----------------------" << endl;
        temp.pop();
        count++;
    }
    cout << endl;
}

int main()
{
    stack<Call> callHistory;

    cout << "=== MOBILE CALL HISTORY SYSTEM ===" << endl;
    cout << endl;

    callHistory.push(Call("Ali Ahmed", "+92-300-1234567", 120));
    cout << "ACTION: Added call from Ali Ahmed" << endl;
    displayCallLog(callHistory);

    callHistory.push(Call("Fatima Khan", "+92-321-7654321", 45));
    cout << "ACTION: Added call from Fatima Khan" << endl;
    displayCallLog(callHistory);

    callHistory.push(Call("Bilal Raza", "+92-333-8889999", 180));
    cout << "ACTION: Added call from Bilal Raza" << endl;
    displayCallLog(callHistory);

    cout << "ACTION: Viewing most recent call" << endl;
    if (!callHistory.empty())
    {
        Call recent = callHistory.top();
        cout << "MOST RECENT CALL:" << endl;
        cout << "Name: " << recent.name << endl;
        cout << "Number: " << recent.number << endl;
        cout << "Duration: " << recent.duration << " seconds" << endl;
        cout << "-----------------------" << endl;
    }
    cout << endl;

    cout << "ACTION: Removing most recent call" << endl;
    if (!callHistory.empty())
    {
        callHistory.pop();
        displayCallLog(callHistory);
    }

    callHistory.push(Call("Sanaullah", "+92-302-5556666", 90));
    cout << "ACTION: Added call from Sanaullah" << endl;
    displayCallLog(callHistory);

    cout << "ACTION: Checking call history status" << endl;
    if (callHistory.empty())
    {
        cout << "Call history is empty" << endl;
    }
    else
    {
        cout << "Call history has " << callHistory.size() << " calls" << endl;
    }
    cout << "-----------------------" << endl;

    return 0;
}
