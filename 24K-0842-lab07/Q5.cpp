#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class QuickSortAnalyzer
{
private:
    int comparisonCount;

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(int arr[], int low, int high, int pivotIndex)
    {
        int pivotValue = arr[pivotIndex];
        swap(&arr[pivotIndex], &arr[high]);

        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            comparisonCount++;
            if (arr[j] <= pivotValue)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[high]);
        return i + 1;
    }

    void quickSortHelper(int arr[], int low, int high, string pivotMethod)
    {
        if (low < high)
        {
            int pivotIndex = selectPivot(arr, low, high, pivotMethod);
            int pi = partition(arr, low, high, pivotIndex);

            quickSortHelper(arr, low, pi - 1, pivotMethod);
            quickSortHelper(arr, pi + 1, high, pivotMethod);
        }
    }

    int selectPivot(int arr[], int low, int high, string method)
    {
        if (method == "first")
        {
            return low;
        }
        else if (method == "random")
        {
            return low + rand() % (high - low + 1);
        }
        else if (method == "middle")
        {
            return low + (high - low) / 2;
        }
        else if (method == "median")
        {
            int mid = low + (high - low) / 2;

            if (arr[low] > arr[mid])
            {
                if (arr[mid] > arr[high])
                    return mid;
                else if (arr[low] > arr[high])
                    return high;
                else
                    return low;
            }
            else
            {
                if (arr[low] > arr[high])
                    return low;
                else if (arr[mid] > arr[high])
                    return high;
                else
                    return mid;
            }
        }
        return low;
    }

public:
    QuickSortAnalyzer() : comparisonCount(0) {}

    int quickSort(int arr[], int size, string pivotMethod)
    {
        comparisonCount = 0;
        int *tempArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            tempArr[i] = arr[i];
        }

        quickSortHelper(tempArr, 0, size - 1, pivotMethod);

        cout << "Sorted array (" << pivotMethod << " pivot): ";
        for (int i = 0; i < size; i++)
        {
            cout << tempArr[i] << " ";
        }
        cout << endl;

        delete[] tempArr;
        return comparisonCount;
    }
};

int main()
{
    srand(time(0));

    QuickSortAnalyzer sorter;

    int Population[] = {21500, 13200, 2270, 1250, 1980, 3200, 1750};
    int size = sizeof(Population) / sizeof(Population[0]);

    cout << "Original City populations (in thousands): ";
    for (int i = 0; i < size; i++)
    {
        cout << Population[i] << " ";
    }
    cout << endl
         << endl;

    string methods[] = {"first", "random", "middle", "median"};
    string methodNames[] = {"First Element", "Random Element", "Middle Element", "Median of Three"};

    for (int i = 0; i < 4; i++)
    {
        int comparisons = sorter.quickSort(Population, size, methods[i]);
        cout << "Comparisons made: " << comparisons << endl;
        cout << "Method: " << methodNames[i] << endl;
        cout << "------------------------" << endl;
    }

    int testArray[] = {10, 7, 8, 9, 1, 5, 3};
    int testSize = sizeof(testArray) / sizeof(testArray[0]);

    cout << endl
         << "Test with assignment numbers {10, 7, 8, 9, 1, 5, 3}:" << endl;

    for (int i = 0; i < 4; i++)
    {
        int comparisons = sorter.quickSort(testArray, testSize, methods[i]);
        cout << methodNames[i] << " comparisons: " << comparisons << endl;
    }

    return 0;
}
