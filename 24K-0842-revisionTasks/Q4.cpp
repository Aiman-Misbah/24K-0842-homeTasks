// If no safe route exists, backtracking keeps exploring all possible paths and then systematically returns(backtracks) from every dead end until no options remain.In this case, the algorithm ultimately returns false, meaning no path was found.The specific line responsible for this behaviour is the return false; statement after backtracking inside the recursive function, which signals that the current route failed and the program should backtrack to try another path.

#include <iostream>
using namespace std;

bool isSafe(int arr[][4], int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool maze(int arr[][4], int x, int y, int n, int solArr[][4])
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;
        if (maze(arr, x + 1, y, n, solArr))
        {
            return true;
        }
        if (maze(arr, x, y + 1, n, solArr))
        {
            return true;
        }
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int building[][4] = {{1, 1, 0, 1}, {0, 1, 1, 0}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    int solArr[4][4];
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }
    if (maze(building, 0, 0, n, solArr))
    {
        cout << endl
             << "Solution Maze: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Sorry, no path found." << endl;
    }
    cout << endl;
    return 0;
}
