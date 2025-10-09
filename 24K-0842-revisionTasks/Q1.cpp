//Shell sort is more efficient than insertion sort for sorting an integer array because it starts by comparing and moving elements that are far apart, which quickly reduces large disorder in the array.As the gap decreases, fewer swaps are needed to fine-tune the nearly sorted data, leading to fewer total comparisions and shifts overall compared to insertion sort, which only compares adjacent elements one by one.

#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void shellSort(int arr[], int n)
{
    cout << "Sorting through Shell Sort: ";
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
    printArray(arr, n);
}

int main()
{
    int IDs[] = {205, 102, 310, 450, 120, 90};
    int n = 6;
    shellSort(IDs, n);
    return 0;
}
