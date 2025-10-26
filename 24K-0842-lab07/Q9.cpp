#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Transaction
{
public:
    int transactionID;
    int amount;
    string customerName;

    Transaction(int id, int amt, string name)
    {
        transactionID = id;
        amount = amt;
        customerName = name;
    }
};

class StableRadixSorter
{
private:
    int getMaxAmount(vector<Transaction> &transactions)
    {
        int maxAmount = transactions[0].amount;
        for (int i = 1; i < transactions.size(); i++)
        {
            if (transactions[i].amount > maxAmount)
            {
                maxAmount = transactions[i].amount;
            }
        }
        return maxAmount;
    }

    void countingSort(vector<Transaction> &transactions, int exp)
    {
        vector<vector<Transaction>> buckets(10);

        for (int i = 0; i < transactions.size(); i++)
        {
            int digit = (transactions[i].amount / exp) % 10;
            buckets[digit].push_back(transactions[i]);
        }

        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < buckets[i].size(); j++)
            {
                transactions[index] = buckets[i][j];
                index++;
            }
        }
    }

public:
    void stableRadixSort(vector<Transaction> &transactions)
    {
        if (transactions.size() <= 1)
            return;

        int maxAmount = getMaxAmount(transactions);

        for (int exp = 1; maxAmount / exp > 0; exp *= 10)
        {
            countingSort(transactions, exp);
        }
    }

    void displayTransactions(vector<Transaction> &transactions, string title)
    {
        cout << title << endl;
        cout << "ID\tAmount (PKR)\tCustomer Name" << endl;
        cout << "--------------------------------" << endl;
        for (int i = 0; i < transactions.size(); i++)
        {
            cout << transactions[i].transactionID << "\t"
                 << transactions[i].amount << "\t\t"
                 << transactions[i].customerName << endl;
        }
        cout << endl;
    }
};

int main()
{
    StableRadixSorter sorter;

    vector<Transaction> transactions = {
        Transaction(101, 4500, "Ali Ahmed - Karachi"),
        Transaction(102, 3200, "Fatima Khan - Lahore"),
        Transaction(103, 4500, "Bilal Raza - Islamabad"),
        Transaction(104, 2100, "Sana Malik - Rawalpindi"),
        Transaction(105, 3200, "Usman Butt - Faisalabad"),
        Transaction(106, 1500, "Ayesha Sheikh - Peshawar"),
        Transaction(107, 4500, "Zainab Hashmi - Multan"),
        Transaction(108, 3200, "Omar Farooq - Quetta")};

    sorter.displayTransactions(transactions, "Original Transactions:");

    sorter.stableRadixSort(transactions);

    sorter.displayTransactions(transactions, "Stable Sorted Transactions:");

    vector<Transaction> testTransactions = {
        Transaction(1, 1000, "Test Customer A"),
        Transaction(2, 500, "Test Customer B"),
        Transaction(3, 1000, "Test Customer C"),
        Transaction(4, 500, "Test Customer D")};

    sorter.displayTransactions(testTransactions, "Test Transactions Before Sorting:");

    sorter.stableRadixSort(testTransactions);

    sorter.displayTransactions(testTransactions, "Test Transactions After Stable Sorting:");

    vector<Transaction> singleTransaction = {
        Transaction(999, 7500, "Single Transaction")};

    sorter.displayTransactions(singleTransaction, "Single Transaction Test:");

    sorter.stableRadixSort(singleTransaction);

    sorter.displayTransactions(singleTransaction, "Single Transaction After Sorting:");

    return 0;
}
