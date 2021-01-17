#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n;
void dfs(int u, int state)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (state >> i & 1)
            {
                cout << i + 1 << ' ';
            }
        }
        cout << endl;

        return;
    }
    dfs(u + 1, state | 1 << u); //用这个数，u位状态值为1
    dfs(u + 1, state);          //不用这个数，状态不用变
}

int main()
{
    cin >> n;
    dfs(0, 0); //从第1个数开始枚举，当前的方案数state
    system("pause");
    return 0;
}
