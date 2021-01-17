#include <bits/stdc++.h>
using namespace std;
int n, m;
void dfs(int u, int cnt, int state)
{
    //剩下的数字不够选
    if (n - u < m - cnt)
        return;
    if (cnt == m)
    {
        for (int i = 0; i < n; i++)
        {
            if (state & 1 << i)
            {
                cout << i + 1 << ' ';
            }
        }
        cout << endl;
        return;
    }
    //选u这个数
    dfs(u + 1, cnt + 1, state | (1 << u));
    //不选u这个数
    dfs(u + 1, cnt, state);
}
int main()
{
    cin >> n >> m;
    dfs(0, 0, 0);
    system("pause");
    return 0;
}