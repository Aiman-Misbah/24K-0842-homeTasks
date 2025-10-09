#include <iostream>
using namespace std;

int n = 5;
int foodX = 2, foodY = 2;

bool isSafe(int arr[][5], int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1);
}

bool findPath(int arr[][5], int x, int y, int solArr[][5])
{
    if (x == foodX && y == foodY)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y) && solArr[x][y] == 0)
    {
        solArr[x][y] = 1;

        if (findPath(arr, x + 1, y, solArr))
            return true;
        if (findPath(arr, x, y + 1, solArr))
            return true;
        if (findPath(arr, x - 1, y, solArr))
            return true;
        if (findPath(arr, x, y - 1, solArr))
            return true;

        solArr[x][y] = 0;
        return false;
    }
    return false;
}

void printSolution(int solArr[][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << solArr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int mazeArr[5][5] = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}};

    int solRabbit[5][5] = {0};
    int solCat[5][5] = {0};

    if (findPath(mazeArr, 0, 0, solRabbit))
    {
        cout << endl
             << "Solution Array For Rabbit:" << endl;
        printSolution(solRabbit);
    }
    else
        cout << "No path found for Rabbit." << endl;

    if (findPath(mazeArr, 4, 4, solCat))
    {
        cout << "Solution Array For Cat:" << endl;
        printSolution(solCat);
    }
    else
        cout << "No path found for Cat." << endl;

    cout << "Intersection Points:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (solRabbit[i][j] == 1 && solCat[i][j] == 1)
                cout << "(" << i << "," << j << ") ";
        }
    }
    cout << endl;

    return 0;
}
