#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
const int ms = 15;
int m, n;
int sx, sy, ex, ey;
int mg[15][15];
bool visited[ms][ms] = {0};
ll cnt = 0;
//题目中是左上右下
//实际的方向是下右上左
//实际以左上角为原点的话，右为x 下为y，所以题目中的左上右下可以理解了
int fx[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
vector<pair<int, int>> v;
bool in_mg(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
        return true;
    return false;
}
void dfs(int x, int y)
{
    visited[x][y] = 1;
    v.push_back(make_pair(x, y));
    if (x == ex && y == ey)
    {
        cnt++;
        rec(i, 0, v.size() - 2)
        {
            printf("(%d,%d)->", v[i].first, v[i].second);
        }
        printf("(%d,%d)\n", v.back().first, v.back().second);
        return;
    }
    rec(i, 0, 3)
    {
        int xx = x + fx[i][0];
        int yy = y + fx[i][1];
        if (in_mg(xx, yy) && mg[xx][yy] == 1 && !visited[xx][yy])
        {
            dfs(xx, yy);
            v.pop_back();
            visited[xx][yy] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    rec(i, 1, n)
    {
        rec(j, 1, m)
        {
            cin >> mg[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey;
    dfs(sx, sy);
    if (cnt == 0)
    {
        cout << "-1\n";
    }
    system("pause");
    return 0;
}
