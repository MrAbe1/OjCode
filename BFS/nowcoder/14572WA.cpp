#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;

const int N = 510;
char g[N][N];
int d[N][N];

int n, m;
int sx, sy, ex, ey;
void bfs()
{
    queue<PII> q;
    memset(d, -1, sizeof d);

    q.push({sx, sy});
    d[sx][sy] = 0;

    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    while (q.size())
    {
        auto t = q.front();
        int x = t.first, y = t.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && d[a][b] == -1 && g[a][b]=='.')
            {
                q.push({a, b});
                d[a][b] = d[x][y] + 1;
            }
        }
    }
    if (d[ex][ey] == -1)
        puts("No");
    else
        puts("Yes");
}
int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            cin >> g[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 'S') sx = i, sy = j;
                if (g[i][j] == 'E') ex = i, ey = j;
            }
        }
        bfs();
    }
    return 0;
}