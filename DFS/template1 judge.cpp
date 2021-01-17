/*
8
2 1 7 8
1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 1
1 1 0 1 0 1 0 1
1 0 0 1 0 1 0 1
1 0 1 1 0 0 0 1
1 0 0 0 0 1 1 1
1 1 0 1 0 0 0 0
1 1 1 1 1 1 1 1
*/

#include <bits/stdc++.h>
using namespace std;
#define ms 100 //迷宫最大大小
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;

int n;              //迷宫大小
int sx, sy, zx, zy; //起点终点
int fx[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int mg[ms][ms]; //迷宫
bool visited[ms][ms] = {0};

//判断x，y是否在迷宫内
bool in_mg(int x, int y)
{
    if (x <= n && x >= 1 && y <= n && y >= 1)
        return true;
    return false;
}
bool dfs(int x, int y)
{
    visited[x][y] = 1;      //设这个点已经走过
    if (x == zx && y == zy) //已经到终点
        return true;
    rec(i, 0, 3)
    {
        int tx = x + fx[i][0];
        int ty = y + fx[i][1];
        //判断tx，ty是否可以走
        //在迷宫中，没走过，可以走
        if (in_mg(tx, ty) && !visited[tx][ty] && mg[tx][ty] != 1)
        {
            if (dfs(tx, ty))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n;
    cin >> sx >> sy >> zx >> zy;
    int i, j;
    rec(i, 1, n)
    {
        rec(j, 1, n)
        {
            cin >> mg[i][j];
        }
    }
    if (dfs(sx, sy))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    system("pause");
    return 0;
}