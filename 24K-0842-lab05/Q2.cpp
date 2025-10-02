#include <iostream>
using namespace std;

#define N 5

int solution[N][N];

bool isSafe(int maze[N][N], int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y)
{
    if (x == N - 1 && y == N - 1)
    {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y))
    {
        solution[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y))
            return true;
        if (solveMazeUtil(maze, x, y + 1))
            return true;
        if (solveMazeUtil(maze, x - 1, y))
            return true;
        if (solveMazeUtil(maze, x, y - 1))
            return true;

        solution[x][y] = 0; 
        return false;
    }

    return false;
}

bool solveMaze(int maze[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            solution[i][j] = 0;

    if (!solveMazeUtil(maze, 0, 0))
    {
        cout << "No path found" << endl;
        return false;
    }

    return true;
}

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int maze[N][N] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}};

    if (solveMaze(maze))
    {
        cout << endl
             << "Lion's path to meat (Solution Array):" << endl;
        printSolution(solution);
        cout << endl;
    }

    return 0;
}

