#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class ProductSorter
{
private:
    void countingSort(vector<int> &products, int exp)
    {
        vector<vector<int>> buckets(10);

        for (int i = 0; i < products.size(); i++)
        {
            int digit = (products[i] / exp) % 10;
            buckets[digit].push_back(products[i]);
        }

        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < buckets[i].size(); j++)
            {
                products[index] = buckets[i][j];
                index++;
            }
        }
    }

    string getDigitName(int exp)
    {
        if (exp == 1)
            return "Units Digit";
        if (exp == 10)
            return "Tens Digit";
        if (exp == 100)
            return "Hundreds Digit";
        if (exp == 1000)
            return "Thousands Digit";
        if (exp == 10000)
            return "Ten-Thousands Digit";
        return "Unknown Digit";
    }

public:
    void displayProducts(vector<int> &products, string title)
    {
        cout << title << endl;
        for (int i = 0; i < products.size(); i++)
        {
            cout << setw(6) << products[i] << " ";
            if ((i + 1) % 5 == 0)
                cout << endl;
        }
        cout << endl;
    }

    void radixSortWithSteps(vector<int> &products)
    {
        cout << "=== RADIX SORT STEP-BY-STEP ===" << endl
             << endl;
        displayProducts(products, "Original Product IDs:");

        for (int exp = 1; exp <= 10000; exp *= 10)
        {
            countingSort(products, exp);
            displayProducts(products, "After sorting by " + getDigitName(exp) + ":");
        }
    }
};

int main()
{
    ProductSorter sorter;

    vector<int> productIDs = {
        45678, 12345, 98765, 23456, 87654,
        34567, 76543, 11111, 99999, 55555,
        22222, 88888, 33333, 77777, 44444,
        66666, 10101, 90909, 50505, 12121};

    sorter.radixSortWithSteps(productIDs);

    vector<int> testProducts = {
        54321, 12345, 98765, 12346, 12347};

    cout << "=== ADDITIONAL TEST CASE ===" << endl;
    sorter.displayProducts(testProducts, "Test Products Before:");
    sorter.radixSortWithSteps(testProducts);

    vector<int> singleProduct = {99999};
    cout << "=== SINGLE PRODUCT TEST ===" << endl;
    sorter.displayProducts(singleProduct, "Single Product Before:");
    sorter.radixSortWithSteps(singleProduct);

    vector<int> sameProducts(5, 12345);
    cout << "=== ALL SAME PRODUCTS TEST ===" << endl;
    sorter.displayProducts(sameProducts, "Same Products Before:");
    sorter.radixSortWithSteps(sameProducts);

    return 0;
}
