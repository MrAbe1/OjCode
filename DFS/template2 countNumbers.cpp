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
#define ms 100
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;

int n;
int cnt = 0;
int sx, sy, ex, ey;
int mg[ms][ms];
int fx[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool visited[ms][ms] = {0};
bool in_mg(int x, int y)
{
    if (x <= n && x >= 1 && y >= 1 && y <= n)
        return true;
    return false;
}
void dfs(int x, int y)
{
    visited[x][y] = 1;
    if (x == ex && y == ey)
    {
        cnt++;
        return;
    }
    rec(i, 0, 3)
    {
        int tx = x + fx[i][0];
        int ty = y + fx[i][1];
        if (in_mg(tx, ty) && !visited[tx][ty] && mg[tx][ty] != 1)
        {
            dfs(tx, ty);
            visited[tx][ty] = 0;
        }
    }
}
int main()
{
    cin >> n;
    cin >> sx >> sy >> ex >> ey;
    rec(i, 1, n)
    {
        rec(j, 1, n)
        {
            cin >> mg[i][j];
        }
    }
    dfs(sx, sy);
    cout << cnt << endl;
    system("pause");
    return 0;
}
