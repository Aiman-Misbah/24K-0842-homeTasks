#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string expression)
{
    stack<int> st;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (ch)
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    cout << "=== POSTFIX EXPRESSION EVALUATOR ===" << endl;
    cout << endl;

    string expression1 = "23*54*+9-";
    cout << "Expression: " << expression1 << endl;
    cout << "Result: " << evaluatePostfix(expression1) << endl;
    cout << "-----------------------" << endl;

    string expression2 = "34+52-*";
    cout << "Expression: " << expression2 << endl;
    cout << "Result: " << evaluatePostfix(expression2) << endl;
    cout << "-----------------------" << endl;

    string expression3 = "92/33*+";
    cout << "Expression: " << expression3 << endl;
    cout << "Result: " << evaluatePostfix(expression3) << endl;
    cout << "-----------------------" << endl;

    string Example = "53+82-*";
    cout << "Example - Expression: " << Example << endl;
    cout << "Result: " << evaluatePostfix(Example) << endl;
    cout << "-----------------------" << endl;

    return 0;
}
