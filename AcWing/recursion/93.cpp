#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n, m;
void dfs(int u, int cnt, int state)
{
    //n-u < m-cnt 当剩下的数字 不够后续选择的时候，直接return
    if (cnt + n - u < m)
        return;
    //当上述的判断如果不加的话，到最后会出现，dfs(u + 1, cnt, state); //一直不选，直接栈溢出
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
    dfs(u + 1, cnt + 1, state | 1 << u); //选中u，u位state置为1

    dfs(u + 1, cnt, state); //不选u
}
int main()
{
    cin >> n >> m;
    dfs(0, 0, 0);

    system("pause");
    return 0;
}
