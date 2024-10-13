#include<iostream>
#include<stack>

using namespace std;

const int m = 8;
const int n = 8;


typedef struct
{
    int x, y;
}Direction;

struct Point
{
    int x;
    int y;
};

Direction dire[4] = { {0,1},{0,-1},{1,0},{1,-1} };

int GetDirection(int** maze, Point cur);//方向

bool FindPath(int** maze, stack<Point> *S);//看看是否可以找到解

int main()
{
    stack<Point> storage;

    int mazeSample[m + 2][n + 2] =
    {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,0,0,1,1,0,0,1},
        {1,0,1,1,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,0,1},
        {1,0,1,1,1,0,1,1,0,1},
        {1,1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };


    int** maze = new int* [m + 2];


    for (int i = 0; i < m + 2; i++)
    {
        maze[i] = new int[n + 2];
    }

    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            maze[i][j] = mazeSample[i][j];
        }
    }


    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }


    stack<Point> strage;
    FindPath(maze, &strage);
    cout << endl;

    
}



bool FindPath(int** maze, stack<Point> *S)//看看是否可以找到解
{
    Point current;
    current.x = 1;
    current.y = 1;
    S->push(current);
    maze[current.x][current.y] = -1;
    while (S->empty()!=0)
    {
        Point top = S->top();
        if (top.x == 8 && top.y == 8)
        {
            return true;
        }
        int direction = GetDirection(maze, top);
        if (direction == 4)
        {
            S->pop();
        }
        else
        {
            top.x += dire[direction].x;
            top.y += dire[direction].y;
            maze[top.x][top.y] = -1;
            S->push(top);
        }
    }
    return false;
}
int GetDirection(int** maze, Point cur)//方向
{
    int d = 0;
    while (d < 4)
    {
        if (cur.x + dire[d].x < n + 1 && cur.y + dire[d].y < m + 1 && maze[cur.x + dire[d].x][cur.y + dire[d].y] == 0) return d;
        d++;

    }
    return 4;
}

