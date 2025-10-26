#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

int evaluatePrefix(string expression)
{
    stack<int> operands;

    for (int i = expression.length() - 1; i >= 0; i--)
    {
        char current = expression[i];

        if (isdigit(current))
        {
            int number = current - '0';
            operands.push(number);
            cout << "Pushed operand: " << number << endl;
            cout << "Stack top: " << operands.top() << endl;
        }
        else
        {
            if (operands.empty())
            {
                cout << "Error: Not enough operands" << endl;
                return -1;
            }
            int right = operands.top();
            operands.pop();

            if (operands.empty())
            {
                cout << "Error: Not enough operands" << endl;
                return -1;
            }
            int left = operands.top();
            operands.pop();

            cout << "Operator: " << current << ", Left: " << left << ", Right: " << right;

            int result;
            if (current == '+')
            {
                result = left + right;
                cout << " → " << left << " + " << right << " = " << result << endl;
            }
            else if (current == '-')
            {
                result = left - right;
                cout << " → " << left << " - " << right << " = " << result << endl;
            }
            else if (current == '*')
            {
                result = left * right;
                cout << " → " << left << " * " << right << " = " << result << endl;
            }
            else if (current == '/')
            {
                if (right == 0)
                {
                    cout << "Error: Division by zero" << endl;
                    return -1;
                }
                result = left / right;
                cout << " → " << left << " / " << right << " = " << result << endl;
            }
            else if (current == '^')
            {
                result = pow(left, right);
                cout << " → " << left << " ^ " << right << " = " << result << endl;
            }

            operands.push(result);
            cout << "Pushed result: " << result << endl;
            cout << "Stack top: " << operands.top() << endl;
        }

        cout << "Stack empty? " << (operands.empty() ? "Yes" : "No") << endl;
        cout << "---" << endl;
    }

    if (operands.empty())
    {
        cout << "Error: Invalid expression" << endl;
        return -1;
    }

    return operands.top();
}

int main()
{
    cout << "=== EVALUATING PREFIX EXPRESSION: -+*23549 ===" << endl;
    int result1 = evaluatePrefix("-+*23549");
    cout << "FINAL RESULT: " << result1 << endl;
    cout << "Verification: ((2*3)+5)-9 = (6+5)-9 = 11-9 = 2" << endl;
    cout << "========================================" << endl
         << endl;

    cout << "=== EVALUATING PREFIX EXPRESSION: +*324 ===" << endl;
    int result2 = evaluatePrefix("+*324");
    cout << "FINAL RESULT: " << result2 << endl;
    cout << "Verification: (3*2)+4 = 6+4 = 10" << endl;
    cout << "========================================" << endl
         << endl;

    cout << "=== EVALUATING PREFIX EXPRESSION: ^23 ===" << endl;
    int result3 = evaluatePrefix("^23");
    cout << "FINAL RESULT: " << result3 << endl;
    cout << "Verification: 2^3 = 8" << endl;
    cout << "========================================" << endl
         << endl;

    return 0;
}
