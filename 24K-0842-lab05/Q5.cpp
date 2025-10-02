#include <iostream>
using namespace std;

int sumDigits(int n)
{
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int nestedSum(int n)
{
    if (n < 10)
        return n;

    int sum = sumDigits(n);
    return nestedSum(sum);
}

int main()
{
    int num;
    cout << endl
         << "Enter a number: ";
    cin >> num;

    int result = nestedSum(num);
    cout << "Final single digit sum is: " << result << endl
         << endl;

    return 0;
}
