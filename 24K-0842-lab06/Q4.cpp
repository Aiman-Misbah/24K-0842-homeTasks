#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int getPrecedence(char op)
{
    if (op == '^')
        return 4;
    if (op == '*' || op == '/')
        return 3;
    if (op == '+' || op == '-')
        return 2;
    return 0;
}

bool isRightAssociative(char op)
{
    return op == '^';
}

string infixToPostfix(string infix)
{
    stack<char> operatorStack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char current = infix[i];

        if (isalpha(current))
        {
            postfix += current;
        }
        else if (current == '(')
        {
            operatorStack.push(current);
        }
        else if (current == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty())
            {
                operatorStack.pop();
            }
        }
        else
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                if (getPrecedence(operatorStack.top()) > getPrecedence(current) ||
                    (getPrecedence(operatorStack.top()) == getPrecedence(current) &&
                     !isRightAssociative(current)))
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                else
                {
                    break;
                }
            }
            operatorStack.push(current);
        }
    }

    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    string result = infixToPostfix(expression);
    cout << endl
         << "Result: " << result << endl
         << endl;
    return 0;
}
