// The robot always tries to move downwards first and only moves right if going down is blocked.If both directions fail, it backtracks to the previous position and tries a new route.So, when multiple paths exist, the robot follows the downward path first because the algorithm gives priority to moving down before moving right.

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

bool robot(int arr[][4], int x, int y, int n, int solArr[][4])
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;
        if (robot(arr, x + 1, y, n, solArr))
        {
            return true;
        }
        if (robot(arr, x, y + 1, n, solArr))
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
    int maze[][4] = {{1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    int n = 4;
    int solArr[4][4];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }
    if (robot(maze, 0, 0, n, solArr))
    {
        cout << "Robot Delivering Package: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Sorry, No path found." << endl;
    }
    return 0;
}
