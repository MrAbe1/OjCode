#include <iostream>
using namespace std;
const int N = 10;
int n;
int path[N];
bool vis[N];
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            cout << path[i]<<' ';
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            path[u] = i;
            vis[i] = true;
            dfs(u + 1);
            //因为path会被不断的覆盖所以没有必要恢复path了
            //回溯要记得恢复现场
            vis[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}