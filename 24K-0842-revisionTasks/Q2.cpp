// The Airport finds Shell sort more efficient than bubble sort since it compares and moves the luggages that are far apart in the early stages, quickly reducing large disorder in the array before performing smaller, fine-tuning passes.This allows the luggages to move long distances in fewer steps, while bubble sort can only swap adjacent elements one by one, requiring many repeated passes.As a result, shell sort significantly reduces the total number of comparisions and swaps, especially for larger arrays.
// If most of the luggage is already sorted, shell sort becomes much faster and more efficient.This is because, in a nearly sorted array, most elements are already close to their correct positions, so the larger-gap passes make very few or no shifts.When the gap becomes small(like 1), only minor adjustments are needed-similar to insertion sort on a nearly sorted list, which is very fast.In short, shell sort performs exceptionally well on a nearly sorted data, often approaching its best-case performance with very few comparisons and movements.

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
    int luggages[] = {32, 25, 40, 12, 18, 50, 28};
    int n = 7;
    shellSort(luggages, n);
    return 0;
}
